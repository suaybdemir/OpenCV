#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <stdexcept>

using namespace std;


void ImageReadAndShow(string path)
{
	cv::Mat img;
	img = cv::imread(path);
	try
	{
		if(!img.data)
		{
			throw runtime_error ("Img wasn't found: "+path);
		}
		else
		{
			cv::namedWindow("Window1");
			cv::imshow("Window1",img);
			
			cv::waitKey(0);
			
		}
		
	}
	catch(const exception& e)
	{
		cerr<<e.what()<<endl;
	}
}

int main(void)
{	
	ImageReadAndShow("example.jpg");
	
	return 0;
}
