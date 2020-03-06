#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	VideoCapture videocapture;

	videocapture.open(0);

	if (!videocapture.isOpened())
	{
		cout << "�޷�����" << endl;
		return -1;
	}
	while (1)
	{
		Mat frame;
		bool fail = videocapture.read(frame);
		if (!fail)
		{
			cout << "�޷���ȡ֡" << endl;
			break;
		}
		else
		{
			imshow("frame", frame);
		}
		waitKey(30);
	}
	return 0;
}