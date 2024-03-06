#include <opencv2/opencv.hpp>

using namespace std;

void WebIpCamR(int ch)
{
	cv::VideoCapture cam;
	
	try
	{
		if(cam.open(ch))
		{
			cv::Mat frame;
			
			while(cam.grab())
			{
				cam.retrieve(frame);
				cv::imshow("Webcam !",frame);
				cv::waitKey(23);
			}
		}
		else throw runtime_error ("Cam not opened!! Channel :"+ch);
	}
	catch(const exception&e)
	{
		cerr<<e.what()<<endl;
	}
	
	return;

}

void WebIpCamR(string ip)
{
	cv::VideoCapture cam;
	
	try
	{
		if(cam.open(ip))
		{
			cv::Mat frame;
			
			while(cam.grab())
			{
				cam.retrieve(frame);
				cv::imshow("Webcam !",frame);
				cv::waitKey(23);
				if(cv::waitKey(23)==27) break;
			}
			
			cv::destroyAllWindows();
		}
		else throw runtime_error ("Cam not opened!! Channel :"+ip);
	}
	catch(const exception&e)
	{
		cerr<<e.what()<<endl;
	}
	
	return;

}

int main(void)
{
	WebIpCamR(0);

	return 0;
}
