#include"include.h"

//Backgroud estimation and subtraction
Mat background_removal(Mat &src_img){

	//clop/downsize an image or not
	Mat im;
	src_img.copyTo(im);
	int nrows = im.rows;
	int ncols = im.cols;
	int N = nrows * ncols;

	//for model_C of expression(23) in this paper
	Mat grid_x, grid_y;
	meshgridTest(Range(1, ncols), Range(1, nrows), grid_x, grid_y);
	
	Mat dim1_x(1, grid_x.rows * grid_x.cols, CV_64F);
	Mat dim1_y(1, grid_y.rows * grid_y.cols, CV_64F);

	int count = 0;
	for (int x = 0; x < grid_x.cols; x++){
		for (int y = 0; y < grid_x.rows; y++){
			dim1_x.data[count] = double(grid_x.data[(y*grid_x.cols) + x]);
			count++;
		}
	}
	count = 0;
	for (int x = 0; x < grid_y.cols; x++){
		for (int y = 0; y < grid_y.rows; y++){
			dim1_y.data[count] = double(grid_y.data[(y*grid_y.cols) + x]);
			count++;
		}
	}

	//make model_C
	Mat model_c(N, 6, CV_64F);
	for (int x = 0; x < 6; x++){
		for (int y = 0; y < N; y++){
			switch (x){
				case 0:	model_c.data[(y*model_c.cols) + x] = 1;					break;
				case 1:	model_c.data[(y*model_c.cols) + x] = dim1_x.data[y];	break;
				case 2:	model_c.data[(y*model_c.cols) + x] = dim1_y.data[y];	break;
				case 3:	model_c.data[(y*model_c.cols) + x] = dim1_x.data[y] * dim1_x.data[y];	break;
				case 4:	model_c.data[(y*model_c.cols) + x] = dim1_x.data[y] * dim1_y.data[y];	break;
				case 5:	model_c.data[(y*model_c.cols) + x] = dim1_y.data[y] * dim1_y.data[y];	break;
			}
		}
	}

	//im to dim_1 to make vector_k of expression(26) in this paper
	Mat dim1_im(1, nrows * ncols, CV_64F);
	count = 0;
	for (int x = 0; x < ncols; x++){
		for (int y = 0; y < nrows; y++){
			dim1_im.data[count] = double(im.data[(y*ncols) + x]);
			count++;
		}
	}

	//make vector_k
	Mat vector_k;
	solve(model_c, dim1_im, vector_k); 

	//make background image
	Mat background = model_c * vector_k;

	//subtraction background from input image
	Mat dim1_bg_free_im = dim1_im - background;
	Mat bg_free_im(nrows, ncols, CV_64F);
	count = 0;
	for (int x = 0; x < ncols; x++){
		for (int y = 0; y < nrows; y++){
			bg_free_im.data[(y*ncols) + x] = bg_free_im.data[count];
			count++;
		}
	}
	
	return bg_free_im;

}//end