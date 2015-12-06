#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <opencv2/core/core.hpp>

using namespace cv;

class Image
{
public:
	Image();
	~Image();

	Mat getMat() const;
	void setMat(const Mat &image);

	QImage getQImage() const;
	void setQImage(const QImage &image);

private:
	Mat mMatImage;
	QImage mQImage;
};

#endif // IMAGE_H
