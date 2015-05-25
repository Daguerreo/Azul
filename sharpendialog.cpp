#include "sharpendialog.h"
#include "ui_sharpendialog.h"

SharpenDialog::SharpenDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SharpenDialog)
{
	ui->setupUi(this);
	ui->graphicsView->setScene(&mScene);
	mPixmapItem = new QGraphicsPixmapItem();
	mScene.addItem( mPixmapItem );

	connect( this,		SIGNAL( sigCommitImage(QImage) ),
			 parent,	SLOT( updateImage(QImage) ) );
}

SharpenDialog::~SharpenDialog()
{
	delete ui;
	delete mPixmapItem;
}

void SharpenDialog::processImage(const QImage &image)
{
	mImageOriginal = image.copy(0,0,image.width(),image.height());
	sharpen( image );

	mImage = QImage( (const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32);
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
}

void SharpenDialog::sharpen(const QImage &image)
{
	cv::Mat kernel = (cv::Mat_<char>(3,3) << 0, -1,  0,
										 -1,  5, -1,
										 0, -1,  0);

	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	cv::filter2D( tmp, mat, tmp.depth(), kernel );
}

void SharpenDialog::on_buttonBox_accepted()
{
	emit( sigCommitImage( mImage ) );
	SharpenDialog::close();
}

void SharpenDialog::on_buttonBox_rejected()
{
	SharpenDialog::close();
}
