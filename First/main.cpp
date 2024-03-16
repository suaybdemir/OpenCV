#include <iostream>
#include <opencv2/opencv.hpp>


int main() {
    // Resmi yükle
    cv::Mat image = cv::imread("example.jpg");
    
    cv::imshow("Windows",image);
    cv::waitKey(0);
    
    return 0;
}
