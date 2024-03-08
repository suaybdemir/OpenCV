#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(void)
{
	cv::Mat img(512,512,CV_8UC3,cv::Scalar(255,255,255));
	
	cv::circle(img,cv::Point(256,256),155,cv::Scalar(0,0,0),cv::FILLED);
	cv::rectangle(img,cv::Point(130,226),cv::Point(382,286),cv::Scalar(0,69,255),cv::FILLED);
	cv::line(img,cv::Point(130,300),cv::Point(382,300),cv::Scalar(0,69,255),2);
	
	//Text
	
	cv::putText(img,"Stop",cv::Point(235,262),cv::FONT_HERSHEY_DUPLEX,0.75,cv::Scalar(15,15,25),2);

	imshow("Image",img);
	cv::waitKey(0);

	return 0;
	
}
