#include"include.h"

void im2double(Mat &src_img, Mat &dst_img){

	for (int y = 0; y < src_img.rows; y++){
		for (int x = 0; x < src_img.cols; x++){
			dst_img.data[(y * dst_img.cols) + x] = double (src_img.data[(y * src_img.cols) + x]) / double ((FLT_MAX - FLT_MIN));
		}
	}

}
