#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QGraphicsSceneMouseEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /*
     * Setup Scene
     */
	ui->setupUi( this );
	ui->graphicsView->setScene( &mScene );
	ui->graphicsView->setMouseTracking( true );
	mScene.installEventFilter( this );
	mPixmapItem = new QGraphicsPixmapItem();
	mScene.addItem( mPixmapItem );

	/*
	 * Setup Variables
	 */
	mController = new Controller();
	mScaleFactor = 1.0;
	mZoomBox.setMinimum(1);
	mZoomBox.setMaximum(2000);
	mZoomBox.setSuffix(" %");
	mZoomBox.setMinimumWidth(60);

	ui->statusBar->addPermanentWidget( &mLoadTime );
	ui->statusBar->addPermanentWidget( &mImageSize );
	ui->statusBar->addPermanentWidget( &mZoomBox );

	connect( &mZoomBox, SIGNAL( valueChanged(int) ),
			 this,      SLOT( updateZoomBoxManually(int) ) );

	/*
	 * Setup Dialogs
	 */
	mGrayscaleDialog = new GrayscaleFilterDialog(this, mController);
	connect( this,				SIGNAL( sigOpenGrayscaleDialog() ),
			 mGrayscaleDialog,	SLOT( openDialog() ) );

	mContrastDialog = new ContrastDialog(this, mController);
	connect( this,				SIGNAL( sigOpenContrastDialog() ),
			 mContrastDialog,	SLOT( openDialog() ) );

	mNegativeDialog = new NegativeFilterDialog(this, mController);
	connect( this,				SIGNAL( sigOpenNegativeDialog() ),
			 mNegativeDialog,	SLOT( openDialog() ) );

	mPixelInfoDialog = new PixelInfoDialog(this);
	connect( this,				SIGNAL( sigOpenPixelInfoDialog(QPixmap, QPointF) ),
			 mPixelInfoDialog,	SLOT( updateClip(QPixmap, QPointF) ) );

	mSmoothingDialog = new SmoothingFilterDialog(this, mController);
	connect( this,				SIGNAL( sigOpenSmoothingDialog() ),
			 mSmoothingDialog,	SLOT( openDialog() ) );

	mCannyDialog = new CannyFilterDialog(this, mController);
	connect( this,				SIGNAL( sigOpenCannyDialog() ),
			 mCannyDialog,	SLOT( openDialog() ) );

	mMorphologyDialog = new MorphologyDialog(this, mController);
	connect( this,				SIGNAL( sigOpenMorphologyDialog() ),
			 mMorphologyDialog,	SLOT( openDialog() ) );

	mThresholdDialog = new ThresholdDialog(this, mController);
	connect( this,				SIGNAL( sigOpenThresholdDialog() ),
			 mThresholdDialog,	SLOT( openDialog() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
	delete mPixmapItem;
	delete mController;
	delete mGrayscaleDialog;
	delete mContrastDialog;
	delete mNegativeDialog;
	delete mPixelInfoDialog;
	delete mSmoothingDialog;
	delete mMorphologyDialog;
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

void MainWindow::closeEvent(QCloseEvent *event)
{
	QMessageBox::StandardButton quitButton;
	quitButton = QMessageBox::question( this,
								APP_NAME,
								tr("Are you sure?\n"),
								QMessageBox::No | QMessageBox::Yes,
								QMessageBox::Yes);

	if (quitButton != QMessageBox::Yes)
		event->ignore();
	else
		event->accept();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
	Q_UNUSED( obj ); //zittisce il compilatore dal warning;

	if( event->type() == QEvent::GraphicsSceneMouseMove )
	{
		QGraphicsSceneMouseEvent* mouseMov = static_cast<QGraphicsSceneMouseEvent*>(event);
		if( !mPixmapItem->contains( mouseMov->scenePos() ) )
				return true;

		int dimX = mPixelInfoDialog->getWidthClip();
		int dimY = mPixelInfoDialog->getHeightClip();

		QPointF topLeft = mouseMov->scenePos();
		topLeft -= QPointF( dimX/2, dimY/2 );
		QRect rect( topLeft.toPoint(), QSize( dimX, dimY ));

		QPixmap clip = mPixmapItem->pixmap().copy( rect );
		emit( sigOpenPixelInfoDialog( clip, mouseMov->scenePos() ) );

		return true;
	}

	return false;
}

float MainWindow::getImageScaleFactor()
{
	return ui->graphicsView->transform().m11();
}

void MainWindow::updateView()
{
	QImage image = mController->requestQImage();
	displayImage(image);
}

void MainWindow::displayImage(const QImage &image)
{
	mPixmapItem->setPixmap(QPixmap::fromImage(image));
	mScene.setSceneRect(0, 0, image.width(), image.height());

	if(ui->action_Adapt_Zoom->isChecked())
	{
		ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
		mScaleFactor = getImageScaleFactor();
	}
	updateZoomBox();
}

void MainWindow::scaleView(const double &factor)
{
	mScaleFactor *= factor;
	ui->action_Adapt_Zoom->setChecked( false );
	ui->graphicsView->setTransform( QTransform::fromScale( mScaleFactor, mScaleFactor ) );
	updateZoomBox();
}

void MainWindow::updateZoomBox()
{
	mZoomBox.setValue( mScaleFactor*100 );
}

void MainWindow::updateZoomBoxManually(int zoom)
{

	mScaleFactor = zoom/100.0;
	ui->graphicsView->setTransform( QTransform::fromScale( mScaleFactor, mScaleFactor ) );

}

/* * * * * * * * * * * * * * * * *
 *	Menu Methods				 *
 * * * * * * * * * * * * * * * * */

void MainWindow::on_action_Open_triggered()
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	bool success = mController->createImage( path );

	if( !success )
		return;

	QImage image = mController->requestQImage();
	displayImage( image );
}

void MainWindow::on_action_Save_triggered()
{
	QString path = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr("JPEG (*.jpg *.jpeg);BMP (*.bmp);PNG (*.png)"));
	QImage image = mController->requestQImage();
	image.save( path );
}

void MainWindow::on_action_Close_triggered()
{
}


void MainWindow::on_action_Quit_triggered()
{
	MainWindow::close();
}

/*
 * View
 */

void MainWindow::on_action_Adapt_Zoom_triggered()
{
	if( ui->action_Adapt_Zoom->isChecked() )
	{
		ui->graphicsView->fitInView( mPixmapItem, Qt::KeepAspectRatio );
		mScaleFactor = getImageScaleFactor();
		mZoomBox.setValue( mScaleFactor*100 );
	}
}

void MainWindow::on_action_Zoom_In_triggered()
{
	if( mScaleFactor <= 0.01 )
		return;

	scaleView( 0.8 );
}

void MainWindow::on_action_Zoom_Out_triggered()
{
	if( mScaleFactor >= 20)
		return;

	scaleView( 1.25 );
}

void MainWindow::on_action_Original_Size_triggered()
{

}

/*
 * Image
 */

void MainWindow::on_action_Pixel_Info_triggered()
{
	mPixelInfoDialog->show();
}

void MainWindow::on_action_Contrast_Brightness_triggered()
{
	mContrastDialog->show();
	emit( sigOpenContrastDialog() );
}

/*
 * Filters
 */

void MainWindow::on_action_Grayscale_triggered()
{
	mGrayscaleDialog->show();
	emit sigOpenGrayscaleDialog();
}

void MainWindow::on_action_Negative_triggered()
{
	mNegativeDialog->show();
	emit( sigOpenNegativeDialog() );
}

void MainWindow::on_action_Sharpen_triggered()
{
}

void MainWindow::on_action_Smoothing_triggered()
{
	mSmoothingDialog->show();
	emit sigOpenSmoothingDialog();
}

void MainWindow::on_action_Morphology_triggered()
{
	mMorphologyDialog->show();
	emit sigOpenMorphologyDialog();
}

void MainWindow::on_action_Canny_triggered()
{
	mCannyDialog->show();
	emit sigOpenCannyDialog();
}

void MainWindow::on_action_Binarization_triggered()
{
	mThresholdDialog->show();
	emit sigOpenThresholdDialog();
}


/*
 * Help
 */

void MainWindow::on_action_About_Qt_triggered()
{
	QMessageBox::aboutQt(this);
}


void MainWindow::on_action_Lena_triggered()
{
	QString path("C:/Users/Daguerreo/Documents/workaspace/git/Azul.git/trunk/res/lena.jpg");

	bool success = mController->createImage( path );

	if( !success )
		return;

	QImage image = mController->requestQImage();
	displayImage( image );
}
