#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void srcSplit(Mat src)
{
	vector<Mat> channel;
	split(src, channel);
	Mat B = channel.at(0);
	Mat G = channel.at(1);
	Mat R = channel.at(2);
	imshow("B", B);
	imshow("G", G);
	imshow("R", R);
	imshow("src", src);
	waitKey(0);
}

void drawCircle(Mat src)
{
	Point point;
	point.x = 150;
	point.y = 150;
	circle(src, point, 50, Scalar(255, 0, 0), 1);
}

void drawLine(Mat src)
{
	Point pt1, pt2;
	pt1.x = 150;pt1.y = 150;
	pt2.x = 1; pt2.y = 1;
	line(src, pt1, pt2, Scalar(0, 255, 0), 1);
}

void drawRect(Mat src)
{
	Rect rect;
	rect.x = 150;
	rect.y = 150;
	rect.height = 100;
	rect.width = 100;
	rectangle(src, rect, Scalar(0, 0, 255), 1);
}
void calStraight(Mat src)	
{
	float histgram[256] = { 0 };
	int histgrams[256] = { 0 };
	int height = src.rows;
	int width = src.cols;
	int f;
	for (int m = 1; m < 256; m++)
	{
		histgrams[m] = histgrams[m-1] + 1;
		cout << histgrams[m] << endl;
	}
	for (int i = 0; i < height; i++)
	{
		uchar *p = src.ptr<uchar>(i);
		for (int j = 0; j < width; j++)
		{
			f = p[j];
			for (int k = 0; k < 256; k++)
			{
				if (f == histgrams[k])
				{
					histgram[k]++;
				}
			}
		}
	}
	for (int n = 0; n < 256; n++)
	{
		histgram[n] = histgram[n] / (height*width);
		cout << histgram[n] << endl;
	}
}


int main()
{
	Mat src = imread("ͼƬ1.png");
	srcSplit(src);
	Mat src2 = Mat(300, 300, CV_8UC3);
	drawCircle(src2);
	drawLine(src2);
	drawRect(src2);
	imshow("draw", src2);
	waitKey(0);
	Mat src3 = imread("ͼƬ1.png",0);
	calStraight(src3);
	return 0;
}