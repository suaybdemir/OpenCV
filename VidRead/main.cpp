#include <stdexcept>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;

void VidRead(string path)
{
	int limit = 23;
	int btn;
	cv::VideoCapture video;
	video.open(path);
	
	try
	{
		if(video.isOpened())
		{
			cv::Mat frame;
			cv::namedWindow("Video Window");
			
			
			while(video.read(frame))
			{
				cv::imshow("Video Window",frame);
				btn = cv::waitKey(limit);
				
				if(btn == 27)
				{
					cout<<"Exited to video!"<<endl;
					break;
				}
				else if(btn == 43)
				{
					cout<<"Fps = "<<++btn<<endl;	
				}
				else if(btn == 45)
				{
					cout<<"Fps = "<<--btn<<endl;
				}
			}
			
			cv::destroyAllWindows();
		}
		else
		{
			throw runtime_error ("Video can't opened!! : "+path);
		}
		
	}
	catch(exception& e)
	{
		cerr<<e.what()<<endl;
	}


}

int main(void)
{
	VidRead("vid.mp4");


	return 0;
}
