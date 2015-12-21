#include "Controller.h"
#include <QDebug>

Controller::Controller(QObject *parent): QObject(parent)
{
}

Controller::~Controller()
{
}

bool Controller::createImage(const QString& path)
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

QImage Controller::requestQImage()
{
	return mImage.getQImage();
}

cv::Mat Controller::requestMatImage()
{
	return mImage.getMat();
}

void Controller::commitImage()
{
	mImage.setMat( mWCImage.getMat() );
	mImage.setQImage( mWCImage.getQImage() );
}

void Controller::createWorkingCopy()
{
	mWCImage.setQImage( mImage.getQImage() );
	mWCImage.setMat( mImage.getMat() );
}

QImage Controller::requestWCQImage()
{
	return mWCImage.getQImage();
}

cv::Mat Controller::requestWCMatImage()
{
	return mWCImage.getMat();
}

void Controller::matchWCMat2Qimage(cv::Mat mat)
{
	QImage qimage = QImage( (const uchar *) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
	mWCImage.setQImage( qimage.rgbSwapped() );
}

void Controller::matchWCQimage2Mat(QImage image)
{
	cv::Mat mat(image.height(),image.width(),CV_8UC3,(uchar*)image.bits(),image.bytesPerLine());
}

void Controller::cleanWorkingCopy()
{
	mWCImage.setQImage( mImage.getQImage() );
	mWCImage.setMat( mImage.getMat() );
}

void Controller::grayscaleAverage(const int& range)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::grayscaleAverage( mat, range );
	matchWCMat2Qimage( mat );
}

void Controller::grayscaleDesaturation()
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::grayscaleDesaturation( mat );
	matchWCMat2Qimage( mat );
}

void Controller::grayscaleLuma()
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::grayscaleLuma( mat );
	matchWCMat2Qimage( mat );
}

void Controller::grayscaleMax()
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::grayscaleMax( mat );
	matchWCMat2Qimage( mat );
}


void Controller::grayscaleMin()
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::grayscaleMin( mat );
	matchWCMat2Qimage( mat );
}

void Controller::contrast(const double &contrast, const int &brightness)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::contrastBrightness( mat, contrast, brightness );
	matchWCMat2Qimage( mat );
}

void Controller::negativeFilter()
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::negative( mat );
	matchWCMat2Qimage( mat );
}

void Controller::meanFilter(const int &kernelRadius)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::meanFilter( mat , kernelRadius );
	matchWCMat2Qimage( mat );
}

void Controller::medianFilter(const int &kernelRadius)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::medianFilter( mat , kernelRadius );
	matchWCMat2Qimage( mat );
}

void Controller::gaussianFilter(const int &kernelRadius)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::gaussianFilter( mat , kernelRadius );
	matchWCMat2Qimage( mat );
}

void Controller::cannyFilter(const int& min, const int& max)
{
	createWorkingCopy();
	cv::Mat mat;
	mWCImage.getMat().copyTo( mat );
	ImageProcessor::cannyFilter( mat, min, max );
	mWCImage.setMat( mat );
	matchWCMat2Qimage( mat );
}

void Controller::cannyAutoFilter(const double& sigma)
{
	createWorkingCopy();
	cv::Mat mat;
	mWCImage.getMat().copyTo( mat );
	ImageProcessor::cannyAutoFilter( mat, sigma );
	mWCImage.setMat( mat );
	matchWCMat2Qimage( mat );
}

void Controller::morphologyDilate(const int &radiusSize, const int &shape, const int &iterations)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::dilate( mat, radiusSize, shape, iterations );
	matchWCMat2Qimage( mat );
}

void Controller::morphologyErode(const int &radiusSize, const int &shape, const int &iterations)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::dilate( mat, radiusSize, shape, iterations );
	matchWCMat2Qimage( mat );
}

void Controller::morphologyOpen(const int &radiusSize, const int &shape)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::open( mat, radiusSize, shape );
	matchWCMat2Qimage( mat );
}

void Controller::morphologyClose(const int &radiusSize, const int &shape)
{
	createWorkingCopy();
	cv::Mat mat = mWCImage.getMat();
	ImageProcessor::close( mat, radiusSize, shape );
	matchWCMat2Qimage( mat );
}

void Controller::binarization(const int& threshold, const int& threshType)
{
	createWorkingCopy();
	cv::Mat mat;
	mWCImage.getMat().copyTo( mat );
	ImageProcessor::threshold(mat, threshold, threshType);
	mWCImage.setMat( mat );
	matchWCMat2Qimage( mat );
}
