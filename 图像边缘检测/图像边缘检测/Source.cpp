#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
#include <math.h>

Mat src, gray_src, dst;
int t1_value = 40;
int max_value = 255;
void Canny_Demo(int, void*);

int main(int argc, char** argv){
	// 图像边缘检测   大幅度地减少了数据量，并且剔除了可以认为不相关的信息，保留了图像重要的结构属性

	// 读取图片
	src = imread("D:/OpenCVProject/day1217/图像边缘检测/图像边缘检测/test.jpg");
	if (!src.data)
	{
		printf("could not load image.....");
	}
	imshow("origin image", src);

	// 转灰度图
	cvtColor(src, gray_src, CV_BGR2GRAY);
	imshow("gray_src image", gray_src);

	// 生成滑动条，调用函数
	namedWindow("final image", WINDOW_AUTOSIZE);
	createTrackbar("this window", "final image", &t1_value, max_value, Canny_Demo);
	Canny_Demo(0, 0);

	waitKey(0);
	return 0;
}

void Canny_Demo(int, void*){
	Mat edge_out;
	// 高斯模糊
	GaussianBlur(gray_src, gray_src, Size(3, 3), 0, 0);

	// 调用canny函数，检测边缘
	/*
		Canny（			InputArray src, // 8-bit的输入图像			OutputArray edges,// 输出边缘图像， 一般都是二值图像，背景是黑色			double threshold1,// 低阈值，常取高阈值的1/2或者1/3			double threshold2,// 高阈值			int aptertureSize,// Soble算子的size，通常3x3，取值3			bool L2gradient // 选择 true表示是L2来归一化，否则用L1归一化		）
	*/
	Canny(gray_src, dst, t1_value, t1_value*2, 3, false);
	imshow("final image", ~dst);
}