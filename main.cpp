#include <iostream>
// #include <string>
// #include <sstream>
#include <thread>
using namespace std;

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
// 创建视频采集对象;
VideoCapture cap;	
Mat frame;	// 摄像头读取到的帧

void hello()
{
	cout << "hello echo" << endl;
    system("pause");
	cout << "1111" << endl;
}

void cap_accept()
{
	namedWindow("Video", 1);	// 显示窗口命名;

	while (1)
	{
		// 获取新的一帧;
		// Mat frame;
		cap >> frame; 
		if (frame.empty())
			return;

		// 显示新的帧;
		imshow("Video", frame);
		
		// 按键退出显示;
		if (waitKey(30) >= 0) 
			break;
	}
}

void cap_process()
{
	namedWindow("Video", 1);	// 显示窗口命名;
	while (1)
	{
		// 显示新的帧;
		imshow("Video", frame);
		
		// // 按键退出显示;
		if (waitKey(30) >= 0) 
			break;
	}
}

int main(int argc, const char** argv)
{
	cap.open(0);	// 打开默认相机;

	// 判断相机是否打开成功;
	if (!cap.isOpened())
		return -1;

	thread a(hello),b(cap_accept);
	// thread c(cap_process);

	a.join();
	b.join();
	// c.join();

	cap.release();	// 释放视频采集对象;
	return 0;
}
