#include "ImageProcessor.h"
#include <QDebug>

int ImageProcessor::minRGB(const int &r, const int &g, const int &b)
{
	int result = (r<=g && r<=b) ? r :
				 (g<=b)			? g :
								  b;
	return result;
}

int ImageProcessor::maxRGB(const int &r, const int &g, const int &b)
{
	int result = (r>=g && r>=b) ? r :
				 (g>=b)			? g :
								  b;
	return result;
}

void ImageProcessor::grayscaleAverage(cv::Mat &img, const int &range)
{
	unsigned char *data = (unsigned char*) (img.data);
	double factor = 255.0 / (range-1);

	int r,g,b,i,gray;
	for(int y=0; y<img.rows; y++)
	{
		for(int x=0; x<img.cols; x++)
		{
			b = data[y*img.step + x*img.channels()];
			g = data[y*img.step + x*img.channels() + 1];
			r = data[y*img.step + x*img.channels() + 2];

			i = ((r+g+b)/3);
			gray = (int) (i/factor+0.5)*factor;

			data[y*img.step + x*img.channels()] = gray;
			data[y*img.step + x*img.channels() + 1] = gray;
			data[y*img.step + x*img.channels() + 2] = gray;
		}
	}
}

void ImageProcessor::grayscaleMin(cv::Mat &img)
{
	unsigned char *data = (unsigned char*) (img.data);
	int r,g,b,gray;

	for(int y=0; y<img.rows; y++)
	{
		for(int x=0; x<img.cols; x++)
		{
			b = data[y*img.step + x*img.channels()];
			g = data[y*img.step + x*img.channels() + 1];
			r = data[y*img.step + x*img.channels() + 2];

			gray = minRGB(r, g ,b);

			data[y*img.step + x*img.channels()] = gray;
			data[y*img.step + x*img.channels() + 1] = gray;
			data[y*img.step + x*img.channels() + 2] = gray;
		}
	}
}

void ImageProcessor::grayscaleMax(cv::Mat &img)
{
	unsigned char *data = (unsigned char*) (img.data);
	int r,g,b,gray;

	for(int y=0; y<img.rows; y++)
	{
		for(int x=0; x<img.cols; x++)
		{
			b = data[y*img.step + x*img.channels()];
			g = data[y*img.step + x*img.channels() + 1];
			r = data[y*img.step + x*img.channels() + 2];

			gray = maxRGB(r, g ,b);

			data[y*img.step + x*img.channels()] = gray;
			data[y*img.step + x*img.channels() + 1] = gray;
			data[y*img.step + x*img.channels() + 2] = gray;
		}
	}
}

void ImageProcessor::grayscaleLuma(cv::Mat &img)
{
	unsigned char *data = (unsigned char*) (img.data);
	int r,g,b,gray;

	for(int y=0; y<img.rows; y++)
	{
		for(int x=0; x<img.cols; x++)
		{
			b = data[y*img.step + x*img.channels()];
			g = data[y*img.step + x*img.channels() + 1];
			r = data[y*img.step + x*img.channels() + 2];

			gray = (int) (r*0.299 + g*0.587 + b*0.114);

			data[y*img.step + x*img.channels()] = gray;
			data[y*img.step + x*img.channels() + 1] = gray;
			data[y*img.step + x*img.channels() + 2] = gray;
		}
	}
}

void ImageProcessor::grayscaleDesaturation(cv::Mat &img)
{
	unsigned char *data = (unsigned char*) (img.data);
	int r,g,b,gray;

	for(int y=0; y<img.rows; y++)
	{
		for(int x=0; x<img.cols; x++)
		{
			b = data[y*img.step + x*img.channels()];
			g = data[y*img.step + x*img.channels() + 1];
			r = data[y*img.step + x*img.channels() + 2];

			gray = (int) ((maxRGB(r,g,b) + minRGB(r,g,b))/2);

			data[y*img.step + x*img.channels()] = gray;
			data[y*img.step + x*img.channels() + 1] = gray;
			data[y*img.step + x*img.channels() + 2] = gray;
		}
	}
}

void ImageProcessor::grayscaleSingleChannel(cv::Mat &img, const int &channel)
{
	unsigned char *data = (unsigned char*) (img.data);
	int gray;

	for(int y=0; y<img.rows; y++)
	{
		for(int x=0; x<img.cols; x++)
		{
			switch(channel)
			{
			case 0:
				gray = data[y*img.step + x*img.channels()];
				data[y*img.step + x*img.channels() + 1] = gray;
				data[y*img.step + x*img.channels() + 2] = gray;
				break;

			case 1:
				gray = data[y*img.step + x*img.channels() + 1];
				data[y*img.step + x*img.channels()] = gray;
				data[y*img.step + x*img.channels() + 2] = gray;
				break;
			case 2:
				gray = data[y*img.step + x*img.channels() + 2];
				data[y*img.step + x*img.channels()] = gray;
				data[y*img.step + x*img.channels() + 1] = gray;
				break;

			default:
				gray = data[y*img.step + x*img.channels()];
				break;
			}
		}
	}
}

void ImageProcessor::contrastBrightness(cv::Mat &img, const double &contrast, const int &brightness)
{
	img.convertTo( img, -1, contrast, brightness );
}

void ImageProcessor::negative(cv::Mat &img)
{
	unsigned char *data = (unsigned char*) (img.data);

	for(int y=0; y<img.rows; y++)
	{
		for(int x=0; x<img.cols; x++)
		{
			data[y*img.step + x*img.channels()] = 255 - data[y*img.step + x*img.channels()];
			data[y*img.step + x*img.channels() + 1] = 255 - data[y*img.step + x*img.channels() + 1];
			data[y*img.step + x*img.channels() + 2] = 255 - data[y*img.step + x*img.channels() + 2];
		}
	}
}

void ImageProcessor::meanFilter(cv::Mat &img, const int &kernelRadius)
{
	cv::blur(img, img, cv::Size(2*kernelRadius+1, 2*kernelRadius+1));
}

void ImageProcessor::medianFilter(cv::Mat &img, const int &kernelRadius)
{
	cv::medianBlur(img, img, 2*kernelRadius+1);
}

void ImageProcessor::gaussianFilter(cv::Mat &img, const int &kernelRadius)
{
	cv::GaussianBlur(img, img, cv::Size(2*kernelRadius+1, 2*kernelRadius+1), 0, 0);
}

/*
 * Canny recommended a upper:lower ratio between 2:1 and 3:1.
 */
void ImageProcessor::cannyFilter(cv::Mat &imgGray, const double &lower, const double &upper)
{
	if( imgGray.channels() > 1 )
	{
		cv::cvtColor( imgGray, imgGray, CV_BGR2GRAY );
		cv::Canny(imgGray, imgGray, lower, upper);
		cv::cvtColor( imgGray, imgGray, CV_GRAY2BGR );
	}
	else
		cv::Canny(imgGray, imgGray, lower, upper);
}

/*
 * Warning, much slower, avoid in videos
 */
void ImageProcessor::cannyAutoFilter(cv::Mat &imgGray, const double& sigma)
{
	if( imgGray.channels() > 1 )
	{
		cv::cvtColor( imgGray, imgGray, CV_BGR2GRAY );

		int median = medianValue(imgGray);
		int up = (int)((1.0 + sigma) * median);
		int down = (int)((0, (1.0 - sigma) * median));

		int lower = down > 0 ? down : 0;
		int upper = up < 255 ? up : 255;

		cv::Canny(imgGray, imgGray, lower, upper);
		cv::cvtColor( imgGray, imgGray, CV_GRAY2BGR );
		qDebug() << "median " << median << " low " << lower << " high " << upper;
	}
	else
	{
		int median = medianValue(imgGray);
		int up = (int)((1.0 + sigma) * median);
		int down = (int)((0, (1.0 - sigma) * median));

		int lower = down > 0 ? down : 0;
		int upper = up < 255 ? up : 255;

		cv::Canny(imgGray, imgGray, lower, upper);
	}
}

int ImageProcessor::medianValue(cv::Mat &img)
{
	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	cv::Mat hist;
	cv::calcHist( &img, 1, 0, cv::Mat(), hist, 1, &histSize, &histRange, true, false );
	cv::normalize( hist, hist, 0, 255, cv::NORM_MINMAX, -1, cv::Mat() );
	for(int i=0; i<256; i++)
	{
		qDebug() << i << " " << hist.data[i] << " ";
	}
	return hist.data[histSize/2];
}

cv::Scalar ImageProcessor::medianValues(cv::Mat &img)
{
	int histSize = 256;
	float range[] = { 0, 256 } ;
	const float* histRange = { range };
	std::vector<cv::Mat> bgr;
	cv::Scalar median;

	cv::split(img, bgr);

	cv::Mat b_hist, g_hist, r_hist;

	/// Compute the histograms:
	cv::calcHist( &bgr[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, true, false );
	cv::calcHist( &bgr[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, true, false );
	cv::calcHist( &bgr[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, true, false );
	cv::normalize( bgr[0], bgr[0], 0, 255, cv::NORM_MINMAX, -1, cv::Mat() );
	cv::normalize( bgr[1], bgr[1], 0, 255, cv::NORM_MINMAX, -1, cv::Mat() );
	cv::normalize( bgr[2], bgr[2], 0, 255, cv::NORM_MINMAX, -1, cv::Mat() );
	median.val[0] = b_hist.data[histSize/2];
	median.val[1] = g_hist.data[histSize/2];
	median.val[2] = r_hist.data[histSize/2];

	return median;
}

void ImageProcessor::dilate(cv::Mat &img, const int &radiusSize, const int &shape, const int &iterations)
{
	cv::Mat element = cv::getStructuringElement( shape, cv::Size(2*radiusSize+1, 2*radiusSize+1), cv::Point(radiusSize, radiusSize) );
	cv::dilate( img, img, element, cv::Point(-1,-1), iterations );
}

void ImageProcessor::erode(cv::Mat &img, const int &radiusSize, const int &shape, const int &iterations)
{
	cv::Mat element = cv::getStructuringElement( shape, cv::Size(2*radiusSize+1, 2*radiusSize+1), cv::Point(radiusSize, radiusSize) );
	cv::erode( img, img, element, cv::Point(-1,-1), iterations );
}

void ImageProcessor::close(cv::Mat &img, const int &radiusSize, const int &shape)
{
	cv::Mat element = cv::getStructuringElement( shape, cv::Size(2*radiusSize+1, 2*radiusSize+1), cv::Point(radiusSize, radiusSize) );
	cv::morphologyEx( img, img, cv::MORPH_CLOSE, element );
}

void ImageProcessor::open(cv::Mat &img, const int &radiusSize, const int &shape)
{
	cv::Mat element = cv::getStructuringElement( shape, cv::Size(2*radiusSize+1, 2*radiusSize+1), cv::Point(radiusSize, radiusSize) );
	cv::morphologyEx( img, img, cv::MORPH_OPEN, element );
}

void ImageProcessor::threshold(cv::Mat &imgGray, const int& threshold, const int& threshType)
{
	if( imgGray.channels() > 1 )
	{
		cv::cvtColor( imgGray, imgGray, CV_BGR2GRAY );
		cv::threshold( imgGray, imgGray, threshold, 255, threshType );
		cv::cvtColor( imgGray, imgGray, CV_GRAY2BGR );
	}
	else
		cv::threshold( imgGray, imgGray, threshold, 255, threshType );
}

void ImageProcessor::adaptiveThreshold(cv::Mat &imgGray, const int& thresholdValue, const int& threshType, const int& inverted, const int& blockSize, const int& C)
{
	if( imgGray.channels() > 1 )
	{
		cv::cvtColor( imgGray, imgGray, CV_BGR2GRAY );
		cv::adaptiveThreshold( imgGray, imgGray, thresholdValue, threshType, inverted, blockSize, C );
		cv::cvtColor( imgGray, imgGray, CV_GRAY2BGR );
	}
	else
		cv::adaptiveThreshold( imgGray, imgGray, thresholdValue, threshType, inverted, blockSize, C );
}
