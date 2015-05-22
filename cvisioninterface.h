#ifndef CVISIONINTERFACE_H
#define CVISIONINTERFACE_H

#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class CVisionInterface
{
public:
	CVisionInterface();
	~CVisionInterface();


	static void grayscale(QImage imageIn);
};

#endif // CVISIONINTERFACE_H
