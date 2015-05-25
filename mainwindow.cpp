#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QSettings>
#include <QColorDialog>
#include <QCloseEvent>
#include <QElapsedTimer>
#include <QThread>
#include <QTimer>
#include <QDateTime>
#include <QGraphicsSceneMouseEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /*
     * Setup Scene
     */
    ui->setupUi(this);
    ui->graphicsView->setScene(&mScene);
    ui->graphicsView->setMouseTracking(true);
    mScene.installEventFilter( this );
	mPixmapItem = new QGraphicsPixmapItem();
	mScene.addItem( mPixmapItem );

    /*
     * Setup Variables
     */

	mScaleFactor = 1.0;
	mZoomBox.setMinimum(1);
	mZoomBox.setMaximum(2000);
	mZoomBox.setSuffix(" %");
	mZoomBox.setMinimumWidth(60);

	connect( &mZoomBox, SIGNAL( valueChanged(int) ),
			 this,      SLOT( updateZoomBoxManually(int) ) );

	ui->statusBar->addPermanentWidget( &mLoadTime );
	ui->statusBar->addPermanentWidget( &mImageSize );
	ui->statusBar->addPermanentWidget( &mLoadTime );
	ui->statusBar->addPermanentWidget( &mZoomBox );
	mRubberBand = new QRubberBand(QRubberBand::Rectangle, this );

    /*
     * Setup Dialogs
     */

	mPixelInfoDialog = new PixelInfoDialog( this );
	connect( this,			SIGNAL( sigPixelInfoDialog(QPixmap, QPointF) ),
			 mPixelInfoDialog, SLOT( updateClip(QPixmap, QPointF) ) );

	mGrayscaleDIalog = new GrayscaleDialog( this );
	connect( this,			SIGNAL( sigGrayscaleDialog(QImage) ),
			 mGrayscaleDIalog,	SLOT( processImage(QImage) ) );

	mContrastDialog = new ContrastDialog( this );
	connect( this,			SIGNAL( sigContrastDialog(QImage) ),
			 mContrastDialog,	SLOT( processImage(QImage) ) );

	mSharpenDialog = new SharpenDialog( this );
	connect( this,			SIGNAL( sigSharpenDialog(QImage) ),
			 mSharpenDialog,	SLOT( processImage(QImage) ) );

	mSmoothingDialog = new SmoothingDialog( this );
}

MainWindow::~MainWindow()
{
    delete ui;
	delete mPixmapItem;
}

void MainWindow::updateImage(const QImage &image)
{
	mImage = image.copy(0,0,image.width(),image.height());
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
	if(ui->action_Adapt_Zoom->isChecked())
	{
		ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
		mScaleFactor = getImageScaleFactor();
		updateZoomBox();
	}

    QWidget::resizeEvent(event);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    Q_UNUSED( obj ); //zittisce il compilatore dal warning;

	if( event->type() == QEvent::GraphicsSceneMouseMove )
    {
		QGraphicsSceneMouseEvent* mouseMov = static_cast<QGraphicsSceneMouseEvent*>(event);

        if( !mPixmapItem->contains( mouseMov->scenePos() ) )
				return true;

		//mypoint = mouseMov->scenePos().toPoint();

        int dimX = mPixelInfoDialog->getWidthClip();
        int dimY = mPixelInfoDialog->getHeightClip();

        QPointF topLeft = mouseMov->scenePos();
        topLeft -= QPointF( dimX/2, dimY/2 );
        QRect rect( topLeft.toPoint(), QSize( dimX, dimY ));

        QPixmap clip = mPixmapItem->pixmap().copy( rect );
        emit sigPixelInfoDialog( clip, mouseMov->scenePos() );

        return true;
	}

	return false;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
	mypoint = event->pos();
	mRubberBand->setGeometry(QRect(mypoint, QSize()));
	mRubberBand->show();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
	if(mRubberBand)
	{
		mRubberBand->setGeometry(QRect(mypoint, event->pos()).normalized());//Area Bounding
	}
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
	if(mRubberBand)
	{
		QRect myRect(mypoint, event->pos());
		mRubberBand->hide();// hide on mouse Release
		QImage copyImage;  //<= this Qimage hold nothing
		mImageInRect = copyImage.copy(myRect);
	}
}

float MainWindow::getImageScaleFactor()
{
	return ui->graphicsView->transform().m11();
}

void MainWindow::showImage(const QImage &image)
{
	mImage = image;
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());

	if(ui->action_Adapt_Zoom->isChecked())
	{
		ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
		mScaleFactor = getImageScaleFactor();
	}
	updateZoomBox();
}

void MainWindow::on_action_Open_triggered()
{
    QString path = QFileDialog::getOpenFileName();

    if( path.isEmpty() )
    {
        return;
    }

	QElapsedTimer et;
	et.start();

    QImage image(path);
    if( image.isNull() )
        return;

	showImage( image );
	updateStatusBar( image, et.nsecsElapsed());
}

void MainWindow::on_action_Save_triggered()
{
	QString path = QFileDialog::getSaveFileName( this, tr("Save File"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)") );
	mImage.save( path );
}

void MainWindow::on_action_Pixel_Info_triggered()
{
	mPixelInfoDialog->show();
}

void MainWindow::scaleView( const float &factor )
{

}

/*
	overlap pixmap
	mScene.clear();
	mScene.addPixmap(QPixmap::fromImage(image));
	mScene.setSceneRect(0, 0, image.width(), image.height());
*/

void MainWindow::on_action_Grayscale_triggered()
{
	mGrayscaleDIalog->show();
	emit( sigGrayscaleDialog( mImage ) );
}

void MainWindow::on_action_Contrast_Brightness_triggered()
{
	mContrastDialog->show();
	emit( sigContrastDialog( mImage ) );
}

void MainWindow::on_action_Sharpen_triggered()
{
	mSharpenDialog->show();
	emit( sigSharpenDialog( mImage ) );
}

void MainWindow::on_action_Smoothing_triggered()
{
	mSmoothingDialog->show();
}

void MainWindow::on_action_Adapt_Zoom_triggered()
{
	if(ui->action_Adapt_Zoom->isChecked())
	{
		ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
		mScaleFactor = getImageScaleFactor();
		mZoomBox.setValue( mScaleFactor*100 );
	}
}

void MainWindow::on_action_Zoom_In_triggered()
{
	if( mScaleFactor <= 0.01 )
		return;

	mScaleFactor *= (float) 0.8;
	ui->action_Adapt_Zoom->setChecked(false);
	ui->graphicsView->setTransform( QTransform::fromScale( mScaleFactor, mScaleFactor ) );
	updateZoomBox();
}


void MainWindow::on_action_Zoom_Out_triggered()
{
	if( mScaleFactor >= 20)
		return;

	mScaleFactor *= (float) 1.25;
	ui->action_Adapt_Zoom->setChecked(false);
	ui->graphicsView->setTransform( QTransform::fromScale( mScaleFactor, mScaleFactor ) );
	updateZoomBox();
}



void MainWindow::updateZoomBox()
{
	mZoomBox.setValue( mScaleFactor*100 );
}

void MainWindow::updateZoomBoxManually( int zoom )
{
	if(ui->action_Adapt_Zoom->isChecked())
	{
		ui->graphicsView->setTransform( QTransform::fromScale( zoom/100.0, zoom/100.0 ) );
	}
}

void MainWindow::updateStatusBar(const QImage& image, qint64 elapsedTime)
{
	double timeInms = elapsedTime/1000000.0;

	mLoadTime.setText(QString("Load Time: %1 ms")
				.arg( timeInms, 0, 'f', 2 )
				);
	mImageSize.setText(
				QString("%1 x %2 - %3 bpp")
				.arg( image.width() )
				.arg( image.height() )
				.arg( image.bitPlaneCount() )
				);
}
