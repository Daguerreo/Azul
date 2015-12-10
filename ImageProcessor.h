#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/*
 * TODO
 * Exception management
 * Correggere single channel
 * Add dithering
 * Custom Filter Tool
*/

class ImageProcessor
{
public:
	static int minRGB(const int &r, const int &g, const int &b);
	static int maxRGB(const int &r, const int &g, const int &b);
	static void grayscaleAverage(cv::Mat& img, const int &range);
	static void grayscaleMin(cv::Mat& img);
	static void grayscaleMax(cv::Mat& img);
	static void grayscaleLuma(cv::Mat& img);
	static void grayscaleDesaturation(cv::Mat& img);
	static void grayscaleSingleChannel(cv::Mat& img, const int &channel);
	static void contrastBrightness(cv::Mat& img, const double &contrast=1.0, const int& brightness=0);
	static void negative(cv::Mat& img);
	static void meanFilter(cv::Mat& img, const int& kernelRadius);
	static void medianFilter(cv::Mat& img, const int& kernelRadius);
	static void gaussianFilter(cv::Mat& img, const int& kernelRadius);
	static void cannyFilter(cv::Mat& imgGray, const double &lower, const double &upper);
	static void cannyAutoFilter(cv::Mat &img, double sigma=0.33);
	static int medianValue(cv::Mat &img);
	static cv::Scalar medianValues(cv::Mat &img);
};

#endif // CONTROLLER_H
