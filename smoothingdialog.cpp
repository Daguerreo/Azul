#include "smoothingdialog.h"
#include "ui_smoothingdialog.h"

SmoothingDialog::SmoothingDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SmoothingDialog)
{
	ui->setupUi(this);
	ui->graphicsView->setScene(&mScene);
	mPixmapItem = new QGraphicsPixmapItem();
	mScene.addItem( mPixmapItem );

	mKernel = 1;

	connect( this,		SIGNAL( sigCommitImage(QImage,qint64) ),
			 parent,	SLOT( updateImage(QImage,qint64) ) );
}

SmoothingDialog::~SmoothingDialog()
{
	delete ui;
}

void SmoothingDialog::processImage(const QImage &image)
{
	mImageOriginal = image.copy(0,0,image.width(),image.height());

	meanFilter( image, mKernel );

	mImage = QImage( (const uchar *) mMat.data, mMat.cols, mMat.rows, mMat.step, QImage::Format_RGB32);
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
}

void SmoothingDialog::resizeEvent(QResizeEvent *event)
{
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	QWidget::resizeEvent(event);
}

void SmoothingDialog::on_buttonBox_accepted()
{
	emit( sigCommitImage( mImage, mTime ) );

	SmoothingDialog::close();
}

void SmoothingDialog::on_buttonBox_rejected()
{
	SmoothingDialog::close();
}

void SmoothingDialog::on_btnApply_clicked()
{
	if( ui->radioMean->isChecked() )
	{
		meanFilter( mImageOriginal, mKernel );
	}
	if( ui->radioMedian->isChecked() )
	{
		medianFilter( mImageOriginal, mKernel );
	}
	if( ui->radioGaussian->isChecked() )
	{
		gaussianFilter( mImageOriginal, mKernel );
	}

	mImage = QImage( (const uchar *) mMat.data, mMat.cols, mMat.rows, mMat.step, QImage::Format_RGB32);
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());

}

void SmoothingDialog::meanFilter( const QImage &image, const int &kernel )
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	cv::blur( tmp, mMat, cv::Size( kernel, kernel ) );
}

void SmoothingDialog::medianFilter(const QImage &image, const int &kernel)
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	cv::medianBlur( tmp, mMat, kernel );
}

void SmoothingDialog::bilateralFilter(const QImage &image, const int &kernel)
{

}

void SmoothingDialog::gaussianFilter(const QImage &image, const int &kernel)
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	//sigma x, sigma y -> 0 use the kernel size
	cv::GaussianBlur( tmp, mMat, cv::Size( kernel, kernel ), 0, 0 );
}

void SmoothingDialog::on_leKernel_textChanged(const QString &arg1)
{
	mKernel = arg1.toInt();
	if( mKernel % 2 == 0 )
	{
		mKernel++;
		ui->leKernel->setText( QString("%1").arg(mKernel) );
	}
}
