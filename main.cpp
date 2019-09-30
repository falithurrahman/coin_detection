#include "opencv2/opencv.hpp"
//#include "opencv2/core/core.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
//#include <math.h>

using namespace cv;
using namespace std;

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;

int main(int argc, char** argv)
{
	Mat frame;
	Mat grey;

	VideoCapture capture;
	capture.open(0);

	for (;;)
	{	
		capture.read(frame);
		//namedWindow("kamera", WINDOW_AUTOSIZE);
		//imshow("kamera", frame);
		cvtColor(frame, grey, COLOR_BGR2GRAY);
		GaussianBlur(grey, grey, Size(13, 13), 0);
		Canny(grey, grey, 40, 130, 3);
		//namedWindow("hasil canny", WINDOW_AUTOSIZE);
		//imshow("hasil canny", grey);

		findContours(grey, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point(0, 0));

		Mat drawing = Mat::zeros(grey.size(), CV_8UC3);
		int koin = 0;
		int jumlah_koin = 0;
		int z = 0;
	
		for (int i = 0; i < contours.size(); i++) {
			//Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			drawContours(drawing, contours, i, Scalar(128, 255, 255), 2, 8, hierarchy, 0, Point());

			if (contours[i].size() > 160) {
				Point2f pusat;
				float jari[200];
				float luas;

				minEnclosingCircle(contours[i], pusat, jari[i]);
				circle(drawing, pusat, jari[i], Scalar(0, 0, 255), 1);
				luas = jari[i] * jari[i] * 3.14;
				cout << "luas lingkaran = " << luas << endl;
				
				if (luas > 14500 && luas <= 16000)
					koin = 500;
				else if (luas > 12500 && luas <= 14000)
					koin = 1000;
				else if (luas > 11000 && luas <= 12500)
					koin = 100;

				jumlah_koin += koin;
				z++;
				//namedWindow("Source", WINDOW_AUTOSIZE);
				//imshow("Source", src);

			}
		}
		cout << " " << endl;
		cout << "jumlah koin =" << contours.size() << endl;

		putText(drawing, format("%d", jumlah_koin), Point(30, 30), FONT_ITALIC, 1.4, Scalar(255, 255, 0));

		namedWindow("baca blob", 1);
		imshow("baca blob", drawing);

		namedWindow("hasil canny", WINDOW_AUTOSIZE);
		imshow("hasil canny", grey);

		namedWindow("dari webcam", WINDOW_AUTOSIZE);
		imshow("dari webcam", frame);
		//imshow("hasil", drawing);

		if (waitKey(10) == 27) break; // stop capturing by pressing ESC 
	}
	return 0;
}
