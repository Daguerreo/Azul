#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>

#include <Image.h>
#include <ImageProcessing.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class Mediator : QObject
{
	Q_OBJECT

public:
	Mediator(QObject *parent=0);
	~Mediator();

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

private:
	Image mImage;
	Image mWCImage; // Working Copy

};

#endif // MEDIATOR_H
