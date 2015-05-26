#include "grayscaledialog.h"
#include "ui_grayscaledialog.h"
#include <QDebug>

GrayscaleDialog::GrayscaleDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ImageDialog)
{
    ui->setupUi(this);
	ui->graphicsView->setScene(&mScene);
	mPixmapItem = new QGraphicsPixmapItem();
	mScene.addItem( mPixmapItem );

	connect( this,		SIGNAL( sigCommitImage(QImage, qint64) ),
			 parent,	SLOT( updateImage(QImage,qint64) ) );

	setOptions();
}

GrayscaleDialog::~GrayscaleDialog()
{
	delete ui;
	delete mPixmapItem;
}

void GrayscaleDialog::setOptions()
{
	ui->radioAvg->setChecked( true );
	ui->lblCurrGray->setNum( ui->hsldGray->value() );
}

void GrayscaleDialog::resizeEvent(QResizeEvent *event)
{
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	QWidget::resizeEvent(event);
}

void GrayscaleDialog::processImage( const QImage &image )
{
	mImageOriginal = image.copy(0,0,image.width(),image.height());
	grayscaleAvg( image, ui->hsldGray->value() );

	mImage = QImage( (const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32);
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
}

void GrayscaleDialog::on_buttonBox_accepted()
{
	emit( sigCommitImage( mImage, mTime ) );
	GrayscaleDialog::close();
}

void GrayscaleDialog::on_buttonBox_rejected()
{
	GrayscaleDialog::close();
}

void GrayscaleDialog::grayscaleAvg( const QImage &image, int range )
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	tmp.copyTo( mat );
	float factor = 255 / (range-1);

	int r,g,b,i,gray;
	for(int y=0; y<mat.rows; y++)
	{
		for(int x=0; x<mat.cols; x++)
		{
			r = mat.at<cv::Vec4b>(y,x)[0];
			g = mat.at<cv::Vec4b>(y,x)[1];
			b = mat.at<cv::Vec4b>(y,x)[2];

			i = ((r+g+b)/3);
			gray = (int) (i/factor+0.5)*factor;

			mat.at<cv::Vec4b>(y,x)[0] = gray;
			mat.at<cv::Vec4b>(y,x)[1] = gray;
			mat.at<cv::Vec4b>(y,x)[2] = gray;
		}
	}
}

void GrayscaleDialog::grayscaleMin( const QImage &image )
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	tmp.copyTo( mat );

	int r,g,b,i,gray;
	for(int y=0; y<mat.rows; y++)
	{
		for(int x=0; x<mat.cols; x++)
		{
			r = mat.at<cv::Vec4b>(y,x)[0];
			g = mat.at<cv::Vec4b>(y,x)[1];
			b = mat.at<cv::Vec4b>(y,x)[2];

			i = ((r+g+b)/3);
			gray = minRGB( r, g ,b );

			mat.at<cv::Vec4b>(y,x)[0] = gray;
			mat.at<cv::Vec4b>(y,x)[1] = gray;
			mat.at<cv::Vec4b>(y,x)[2] = gray;
		}
	}

}

void GrayscaleDialog::grayscaleMax( const QImage &image )
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	tmp.copyTo( mat );

	int r,g,b,i,gray;
	for(int y=0; y<mat.rows; y++)
	{
		for(int x=0; x<mat.cols; x++)
		{
			r = mat.at<cv::Vec4b>(y,x)[0];
			g = mat.at<cv::Vec4b>(y,x)[1];
			b = mat.at<cv::Vec4b>(y,x)[2];

			i = ((r+g+b)/3);
			gray = maxRGB( r, g ,b );

			mat.at<cv::Vec4b>(y,x)[0] = gray;
			mat.at<cv::Vec4b>(y,x)[1] = gray;
			mat.at<cv::Vec4b>(y,x)[2] = gray;
		}
	}

}

void GrayscaleDialog::grayscaleLuma( const QImage &image )
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	tmp.copyTo( mat );

	int r,g,b,gray;
	float i;

	for(int y=0; y<mat.rows; y++)
	{
		for(int x=0; x<mat.cols; x++)
		{
			r = mat.at<cv::Vec4b>(y,x)[0];
			g = mat.at<cv::Vec4b>(y,x)[1];
			b = mat.at<cv::Vec4b>(y,x)[2];

			i = r*0.299 + g*0.587 + b*0.114;
			gray = (int) i;

			mat.at<cv::Vec4b>(y,x)[0] = gray;
			mat.at<cv::Vec4b>(y,x)[1] = gray;
			mat.at<cv::Vec4b>(y,x)[2] = gray;
		}
	}

}

void GrayscaleDialog::grayscaleDesaturation( const QImage &image )
{
	cv::Mat tmp(image.height(),image.width(),CV_8UC4,(uchar*)image.bits(),image.bytesPerLine());
	tmp.copyTo( mat );

	int r,g,b,gray;

	for(int y=0; y<mat.rows; y++)
	{
		for(int x=0; x<mat.cols; x++)
		{
			r = mat.at<cv::Vec4b>(y,x)[0];
			g = mat.at<cv::Vec4b>(y,x)[1];
			b = mat.at<cv::Vec4b>(y,x)[2];

			gray = (maxRGB( r, g ,b ) + minRGB( r, g ,b ))/2;

			mat.at<cv::Vec4b>(y,x)[0] = gray;
			mat.at<cv::Vec4b>(y,x)[1] = gray;
			mat.at<cv::Vec4b>(y,x)[2] = gray;
		}
	}

}

void GrayscaleDialog::on_btnApply_clicked()
{
	if( ui->radioAvg->isChecked() )
	{
		grayscaleAvg( mImageOriginal, ui->hsldGray->value() );
	}
	if( ui->radioMin->isChecked() )
	{
		grayscaleMin( mImageOriginal );
	}
	if( ui->radioMax->isChecked() )
	{
		grayscaleMax( mImageOriginal );
	}
	if( ui->radioLuma->isChecked() )
	{
		grayscaleLuma( mImageOriginal );
	}
	if( ui->radioDesaturation->isChecked() )
	{
		grayscaleDesaturation( mImageOriginal );
	}
	mImage = QImage( (const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32);
	mPixmapItem->setPixmap(QPixmap::fromImage(mImage));
	ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	mScene.setSceneRect(0, 0, mImage.width(), mImage.height());
}

int GrayscaleDialog::maxRGB( const int &r, int &g, int &b )
{
	if( r >= g)
	{
		if( r >= b)
			return r;
		return b;
	}
	else if( g >= b)
	{
		return g;
	}
	else
		return b;
}

int GrayscaleDialog::minRGB( const int &r, int &g, int &b )
{
	if( r <= g)
	{
		if( r <= b)
			return r;
		return b;
	}
	else if( g <= b)
	{
		return g;
	}
	else
		return b;
}
