#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
#include <math.h>

Mat src, gray_src, dst;
int t1_value = 40;
int max_value = 255;
void Canny_Demo(int, void*);

int main(int argc, char** argv){
	// ͼ���Ե���   ����ȵؼ������������������޳��˿�����Ϊ����ص���Ϣ��������ͼ����Ҫ�Ľṹ����

	// ��ȡͼƬ
	src = imread("D:/OpenCVProject/day1217/ͼ���Ե���/ͼ���Ե���/test.jpg");
	if (!src.data)
	{
		printf("could not load image.....");
	}
	imshow("origin image", src);

	// ת�Ҷ�ͼ
	cvtColor(src, gray_src, CV_BGR2GRAY);
	imshow("gray_src image", gray_src);

	// ���ɻ����������ú���
	namedWindow("final image", WINDOW_AUTOSIZE);
	createTrackbar("this window", "final image", &t1_value, max_value, Canny_Demo);
	Canny_Demo(0, 0);

	waitKey(0);
	return 0;
}

void Canny_Demo(int, void*){
	Mat edge_out;
	// ��˹ģ��
	GaussianBlur(gray_src, gray_src, Size(3, 3), 0, 0);

	// ����canny����������Ե
	/*
		Canny��			InputArray src, // 8-bit������ͼ��			OutputArray edges,// �����Եͼ�� һ�㶼�Ƕ�ֵͼ�񣬱����Ǻ�ɫ			double threshold1,// ����ֵ����ȡ����ֵ��1/2����1/3			double threshold2,// ����ֵ			int aptertureSize,// Soble���ӵ�size��ͨ��3x3��ȡֵ3			bool L2gradient // ѡ�� true��ʾ��L2����һ����������L1��һ��		��
	*/
	Canny(gray_src, dst, t1_value, t1_value*2, 3, false);
	imshow("final image", ~dst);
}