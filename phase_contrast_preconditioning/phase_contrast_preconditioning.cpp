#include"include.h"
#include"parameters.h"

int main(){

	//specify parameters
	OptParas optparas(1, 0.4, 3, 3, 3, 1, 100, numeric_limits<double>::epsilon());
	KernParas kernparas(4, 0.8, 2, 0.8, 20);

	// Read a phase contrast image:
	Mat phc_img = imread("..\\dataset\\Ph3.tif", -1);
	if (phc_img.empty()){ 
		cout << "read error" << endl;
		getchar();
		return -1;
	}
	if (phc_img.type() != CV_16U){
		cout << "not 16bit Grayscale" << endl;
		getchar();
		return -1;
	}

	//cast uint16 to double
	Mat casted_img = Mat::zeros(phc_img.rows, phc_img.cols, CV_64F);	//Œ^‚ð”{¸“x‚É•ÏŠ·
	im2double(phc_img,casted_img);
	if (casted_img.type() != CV_64F){
		cout << "can't cast double" << endl;
		getchar();
		return -1;
	}

	//begin preconditioning
	cout << "begin preconditioning" << endl;
	Mat dst_img = Mat::zeros(phc_img.rows, phc_img.cols, CV_64F);


	


	namedWindow("phc_img", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	imshow("phc_img", phc_img);
	cvWaitKey();
	
	return 0;
}