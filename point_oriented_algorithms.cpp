//https://github.com/flyingwolfz/point-oriented-algorithms-CGH-opencv
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>  
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("C:\\Users\\22337\\Desktop\\dioda.png",0);//100*100
	Mat t(1080, 1920, CV_8UC1, 1);

	int i, j, kuan, chang;
	int ii = -50, jj = -50;
	int f2 = 500 * 500;
	int x = -960, y = -540;
	float   fudu,lambda, pitch, k,  fai, coss=0, sinn=0, jiao=0;
	float pitch2 = 0.1;
	int jishi = 0;

	lambda = 632.8 * 0.000001;
	pitch = 0.008;
	k = 2 * CV_PI / lambda;

	for (chang = 0; chang < 1080; chang++)
	{
		uchar* tu = t.ptr<uchar>(chang);

		for (kuan = 0; kuan< 1920; kuan++)
		{
			
			for (i = 0; i< 100; i++)
			{
				uchar* data = image.ptr<uchar>(i);

				for (j = 0; j < 100; j++)
				{
					float xx = (x*pitch - jj * pitch2)*(x*pitch - jj * pitch2);
					float yy = (y*pitch - ii* pitch2)*(y*pitch - ii * pitch2);
					jj++;
					fai = k * sqrt(xx + yy + f2);
					fudu = data[j];
					coss = coss + fudu * cos(fai);
					sinn = sinn + fudu * sin(fai);

				}
				jj = -50;
				ii++;

			}
			ii = -50;
			x++;
			jiao = cvFastArctan(sinn, coss) / 360 * 255;
			tu[kuan] = jiao;
			coss = 0;
			sinn = 0;

		}
		x=-960;
		y++;
		jishi++;
		cout << jishi<<endl;

	}
	
	
	imshow("ÏÔÊ¾Í¼Ïñ", t);
	imwrite("C:\\Users\\22337\\Desktop\\cdianyun.png", t);
	waitKey(0);
	return 0;
}
