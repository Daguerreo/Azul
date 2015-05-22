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
    /*
     * Setup Dialogs
     */
	mPixelInfoDialog = new PixelInfoDialog( this );
	connect( this,			SIGNAL( sigPixelInfoDialog(QPixmap, QPointF) ),
			 mPixelInfoDialog, SLOT( updateClip(QPixmap, QPointF) ) );

	mImageDialog = new GrayscaleDialog( this );
	connect( this,			SIGNAL( sigImageDialog(QImage) ),
			 mImageDialog,	SLOT( processImage(QImage) ) );

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
    ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
    QWidget::resizeEvent(event);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
    Q_UNUSED( obj ); //zittisce il compilatore dal warning;

    if( ev->type() == QEvent::GraphicsSceneMouseMove )
    {
        QGraphicsSceneMouseEvent* mouseMov = static_cast<QGraphicsSceneMouseEvent*>(ev);

        if( !mPixmapItem->contains( mouseMov->scenePos() ) )
                return true;

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

void MainWindow::showImage(const QImage &image)
{
	mImage = image;
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
}

void MainWindow::on_action_Open_triggered()
{
    QString path = QFileDialog::getOpenFileName();

    if( path.isEmpty() )
    {
        return;
    }

    QImage image(path);
    if( image.isNull() )
        return;

	showImage( image );

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
	mImageDialog->show();
	emit( sigImageDialog( mImage ) );
}


