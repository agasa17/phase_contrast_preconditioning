#pragma once

#include<iostream>
#include<float.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void im2double(Mat &src_img, Mat &dst_img);
void meshgrid(const cv::Mat &xgv, const cv::Mat &ygv,
	cv::Mat &X, cv::Mat &Y);
void meshgridTest(const cv::Range &xgv, const cv::Range &ygv,
	cv::Mat &X, cv::Mat &Y);
Mat background_removal(Mat &src_img);