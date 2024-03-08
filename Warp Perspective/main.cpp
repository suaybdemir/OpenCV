#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;



int main(void)
{

	float w = 350,h=300;
	cv::Mat matrix,imgWarp;
	
	string path = "example.jpg";
	cv::Mat img = cv::imread(path);
	
	cv::Point2f src[4] = {{336,314},{611,271},{353,563},{702,503}};
	cv::Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};
	
	matrix = cv::getPerspectiveTransform(src,dst);
	cv::warpPerspective(img,imgWarp,matrix,cv::Point(w,h));
	
	for(int i = 0; i<4; i++)
	{
	
		cv::circle(img,src[i],10,cv::Scalar(0,0,255),cv::FILLED);
	}
	
	cv::imshow("Image",img);
	cv::imshow("Image Warp",imgWarp);
	cv::waitKey(0);

	return 0;
}
