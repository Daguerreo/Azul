#include "Image.h"

Image::Image()
{
}

Image::~Image()
{
}

Mat Image::getMat() const
{
	return mMatImage;
}

void Image::setMat(const Mat &image)
{
	image.copyTo( mMatImage );
}

QImage Image::getQImage() const
{
	return mQImage;
}

void Image::setQImage(const QImage &image)
{
	mQImage = image.copy(0,0,image.width(),image.height());
}



