#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
	cv::Mat img = cv::imread("cat.jpg",cv::IMREAD_COLOR);
	cv::Mat bilateralImg,gaussianImg,medianImg;
	
	cv::bilateralFilter(img,bilateralImg,15,95,45);
	
	cv::GaussianBlur(img,gaussianImg,cv::Size(15,15),0);
	
	cv::medianBlur(img,medianImg,15);
	
	
	cv::imshow("Median",medianImg);
	cv::imshow("Gaussian",gaussianImg);
	cv::imshow("Bilateral",bilateralImg);
	cv::imshow("Input",img);
	cv::waitKey(0);

	return 0;
}
