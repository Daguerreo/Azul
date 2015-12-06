#include "ImageProcessing.h"


int ImageProcessing::minRGB(const int &r, const int &g, const int &b)
{
	int result = (r<=g && r<=b) ? r :
				 (g<=b)			? g :
								  b;
	return result;
}

int ImageProcessing::maxRGB(const int &r, const int &g, const int &b)
{
	int result = (r>=g && r>=b) ? r :
				 (g>=b)			? g :
								  b;
	return result;
}

void ImageProcessing::grayscaleAverage(cv::Mat &img, const int &range)
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

void ImageProcessing::grayscaleMin(cv::Mat &img)
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

void ImageProcessing::grayscaleMax(cv::Mat &img)
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

void ImageProcessing::grayscaleLuma(cv::Mat &img)
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

void ImageProcessing::grayscaleDesaturation(cv::Mat &img)
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

void ImageProcessing::grayscaleSingleChannel(cv::Mat &img, const int &channel)
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

void ImageProcessing::contrastBrightness(cv::Mat &img, const double &contrast, const int &brightness)
{
	img.convertTo( img, -1, contrast, brightness );
}

void ImageProcessing::negative(cv::Mat &img)
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

void ImageProcessing::meanFilter(cv::Mat &img, const int &kernelRadius)
{
	cv::blur(img, img, cv::Size(2*kernelRadius+1, 2*kernelRadius+1));
}

void ImageProcessing::medianFilter(cv::Mat &img, const int &kernelRadius)
{
	cv::medianBlur(img, img, 2*kernelRadius+1);
}

void ImageProcessing::gaussianFilter(cv::Mat &img, const int &kernelRadius)
{
	cv::GaussianBlur(img, img, cv::Size(2*kernelRadius+1, 2*kernelRadius+1), 0, 0);
}

/*
 * Canny recommended a upper:lower ratio between 2:1 and 3:1.
*/
void ImageProcessing::cannyFilter(cv::Mat &img, const double &lower, const double &upper)
{
	cv::Canny(img, img, lower, upper);
}

/*
 * Warning, much slower, try to avoid in videos
*/
void ImageProcessing::cannyAutoFilter(cv::Mat &img, double sigma)
{
	int median = medianValue(img);
	int up = (int)((1.0 + sigma) * median);
	int down = (int)((0, (1.0 - sigma) * median));

	int lower = down > 0 ? down : 0;
	int upper = up < 255 ? up : 255;

	cv::Canny(img, img, lower, upper);
}

int ImageProcessing::medianValue(cv::Mat &img)
{
	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	cv::Mat hist;
	cv::calcHist(&img, 1, 0, cv::Mat(), hist, 1, &histSize, &histRange, true, false );

	return hist.data[histSize/2];
}

cv::Scalar ImageProcessing::medianValues(cv::Mat &img)
{
	int histSize = 256;
	float range[] = { 0, 256 } ;
	const float* histRange = { range };
	std::vector<cv::Mat> bgr;
	cv::Scalar median;

	cv::split(img, bgr);

	bool uniform = true; bool accumulate = false;
	cv::Mat b_hist, g_hist, r_hist;

	/// Compute the histograms:
	cv::calcHist( &bgr[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
	cv::calcHist( &bgr[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
	cv::calcHist( &bgr[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

	median.val[0] = b_hist.data[histSize/2];
	median.val[1] = g_hist.data[histSize/2];
	median.val[2] = r_hist.data[histSize/2];

	return median;
}
