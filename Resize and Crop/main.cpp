#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string path = "example.jpg";
	cv::Mat img = cv::imread(path);
	cv::Mat imgResize,imgCrop;
	
	cv::resize(img,imgResize, cv::Size(100,100));
	
	cv::Rect roi(50,50,50,50);
	imgCrop = img(roi);
	
	imshow("Image",img);
	imshow("Image Resize",imgResize);
	imshow("Image crop",imgCrop);
	
	cv::waitKey(0);

	return 0;
}
