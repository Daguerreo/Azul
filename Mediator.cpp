#include "Mediator.h"

Mediator::Mediator(QObject *parent): QObject(parent)
{
}

Mediator::~Mediator()
{
}

bool Mediator::createImage(const QString& path)
{
	QImage image(path);
	if( image.isNull() )
	{
		qWarning("Warning: path does not contains a valid image");
		return false;
	}
	cv::Mat temp = cv::imread(path.toStdString(), cv::IMREAD_COLOR);

	mImage.setQImage(image);
	mImage.setMat(temp);

	return true;
}

QImage Mediator::requestQImage()
{
	return mImage.getQImage();
}

cv::Mat Mediator::requestMatImage()
{
	return mImage.getMat();
}

void Mediator::commitImage()
{
	mImage.setMat( mWCImage.getMat() );
	mImage.setQImage( mWCImage.getQImage() );
}

void Mediator::createWorkingCopy()
{
	mWCImage.setQImage( mImage.getQImage() );
	mWCImage.setMat( mImage.getMat() );
}

QImage Mediator::requestWCQImage()
{
	return mWCImage.getQImage();
}

cv::Mat Mediator::requestWCMatImage()
{
	return mWCImage.getMat();
}

void Mediator::matchWCMat2Qimage( cv::Mat mat )
{
	QImage qimage = QImage( (const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
	mWCImage.setQImage( qimage.rgbSwapped() );
}

void Mediator::matchWCQimage2Mat( QImage image )
{
	cv::Mat mat(image.height(),image.width(),CV_8UC3,(uchar*)image.bits(),image.bytesPerLine());
}

void Mediator::cleanWorkingCopy()
{
	mWCImage.setQImage( mImage.getQImage() );
	mWCImage.setMat( mImage.getMat() );
}

void Mediator::grayscaleAverage(const int& range)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessing::grayscaleAverage( mat, range);
	matchWCMat2Qimage( mat );
}

void Mediator::grayscaleDesaturation()
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessing::grayscaleDesaturation( mat );
	matchWCMat2Qimage( mat );
}

void Mediator::grayscaleLuma()
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessing::grayscaleLuma( mat );
	matchWCMat2Qimage( mat );
}

void Mediator::grayscaleMax()
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessing::grayscaleMax( mat );
	matchWCMat2Qimage( mat );
}


void Mediator::grayscaleMin()
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessing::grayscaleMin( mat );
	matchWCMat2Qimage( mat );
}

void Mediator::contrast(const double &contrast, const int &brightness)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessing::contrastBrightness( mat, contrast, brightness );
	matchWCMat2Qimage( mat );
}

