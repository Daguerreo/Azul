#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>

#include <Image.h>
#include <ImageProcessor.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class Controller : QObject
{
	Q_OBJECT

public:
	Controller(QObject *parent=0);
	~Controller();

	bool createImage(const QString &path);
	QImage requestQImage();
	cv::Mat requestMatImage();
	void commitImage();

	void createWorkingCopy();
	QImage requestWCQImage();
	cv::Mat requestWCMatImage();
	void cleanWorkingCopy();
	void matchWCMat2Qimage(cv::Mat mat);
	void matchWCQimage2Mat(QImage image);

	void grayscaleAverage(const int &range);
	void grayscaleDesaturation();
	void grayscaleLuma();
	void grayscaleMax();
	void grayscaleMin();
	void contrast(const double &contrast, const int &brightness);
	void negativeFilter();
	void meanFilter(const int &kernelRadius);
	void medianFilter(const int &kernelRadius);
	void gaussianFilter(const int &kernelRadius);

private:
	Image mImage;
	Image mWCImage; // Working Copy

};

#endif // MEDIATOR_H
