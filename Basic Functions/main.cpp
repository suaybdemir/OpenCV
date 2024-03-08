#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>


int main(void)
{
	std::string path = "example.jpg";
	
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
	
	cv::cvtColor(img,imgGray,cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img,imgBlur,cv::Size(3,3),3,0);
	cv::Canny(imgBlur,imgCanny,50,75);
	
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(2,2));
	cv::dilate(imgCanny,imgDil,kernel);
	cv::erode(imgDil,imgErode,kernel);
	
	cv::imshow("Image",img);
	cv::imshow("Image Gray",imgGray);
	cv::imshow("Image Blur",imgBlur);
	cv::imshow("Image Canny",imgCanny);
	cv::imshow("Image Dilation",imgDil);
	cv::imshow("Image Erode",imgErode);
	cv::waitKey(0);
	
	cv::destroyAllWindows();

	return 0;
}
