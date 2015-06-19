#include "morphologydialog.h"
#include "ui_morphologydialog.h"

MorphologyDialog::MorphologyDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::MorphologyDialog)
{
	ui->setupUi(this);
	ui->graphicsView->setScene(&mScene);
	mPixmapItem = new QGraphicsPixmapItem();
	mScene.addItem( mPixmapItem );

	mKernelSize = 1;
	mIter = 1;
	mShape = cv::MORPH_RECT;

	connect( this,		SIGNAL( sigCommitImage(QImage,qint64) ),
			 parent,	SLOT( updateImage(QImage,qint64) ) );
}

MorphologyDialog::~MorphologyDialog()
{
	delete ui;
}

void MorphologyDialog::processImage(const QImage &image)
{
	mImageOriginal = image.copy(0,0,image.width(),image.height());

	dilate( mImageOriginal, mKernelSize, mShape, mIter );

	mImage = QImage( (const uchar *) mMat.data, mMat.cols, mMat.rows, mMat.step, QImage::Format_RGB32);
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
}

void MorphologyDialog::resizeEvent(QResizeEvent *event)
{
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	QWidget::resizeEvent(event);
}

void MorphologyDialog::on_buttonBox_accepted()
{
	emit( sigCommitImage( mImage, mTime ) );
	MorphologyDialog::close();
}

void MorphologyDialog::on_buttonBox_rejected()
{
	MorphologyDialog::close();
}

void MorphologyDialog::on_btnApply_clicked()
{
	if( ui->radioRectangle->isChecked())
	{
		mShape = cv::MORPH_RECT;
	}
	else if( ui->radioCross->isChecked() )
	{
		mShape = cv::MORPH_CROSS;
	}
	else
	{
		mShape = cv::MORPH_ELLIPSE;
	}

	if( ui->radioDilate->isChecked() )
	{
		dilate( mImageOriginal, mKernelSize, mShape, mIter );
	}
	if( ui->radioErode->isChecked() )
	{
		erode( mImageOriginal, mKernelSize, mShape, mIter );
	}

	mImage = QImage( (const uchar *) mMat.data, mMat.cols, mMat.rows, mMat.step, QImage::Format_RGB32);
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
}

void MorphologyDialog::dilate( const QImage &image, const int &size, const int &shape, const int &iterations )
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	cv::Mat element = cv::getStructuringElement( shape, cv::Size(2*size+1, 2*size+1), cv::Point(size,size) );
	cv::dilate( tmp, mMat, element, cv::Point(-1,-1), iterations );
}


void MorphologyDialog::erode( const QImage &image, const int &size, const int &shape, const int &iterations )
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	cv::Mat element = cv::getStructuringElement( shape, cv::Size(2*size+1, 2*size+1), cv::Point(size,size) );
	cv::erode( tmp, mMat, element, cv::Point(-1,-1), iterations );
}


void MorphologyDialog::on_leKernel_textChanged(const QString &arg1)
{
	int size = arg1.toInt();
	mKernelSize = size;
}

void MorphologyDialog::on_leIterations_textChanged(const QString &arg1)
{
	int iter = arg1.toInt();
	mIter = iter;
}
