#include <iostream>
#include <string>
#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;

int main(void)
{
    string path = "example.png";
    cv::Mat img = cv::imread(path);
    cv::Mat imgGray, imgBlur,imgCanny, imgDil;


    // Preprocessing
    cv::cvtColor(img,imgGray,cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(imgGray,imgBlur,cv::Size(3,3),3,0);
    cv::Canny(imgBlur,imgCanny,25,75);

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(3,3));
    cv::dilate(imgCanny,imgDil,kernel);

    vector<vector<cv::Point>> contours;
    vector<vector<cv::Vec4i>> hierarchy;

    cv::findContours(imgDil,contours,hierarchy,cv::RETR_LIST,cv::CHAIN_APPROX_SIMPLE);
    cv::drawContours(img,contours, -1 , cv::Scalar(255,0,255),1);

    ///// 
    
    cv::imshow("Original Image",img);
    /*cv::imshow("Image Gray",imgGray);
    cv::imshow("Image Blur",imgBlur);
    cv::imshow("Image Canny",imgCanny);
    cv::imshow("Image Dil",imgDil);*/
    cv::waitKey(0);

    return 0;
}


