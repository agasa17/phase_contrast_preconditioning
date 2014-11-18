#include"include.h"
#include"parameters.h"

void precondition_linear_model(Mat &src_img, Mat &dst_img, struct OptParas &optparas, struct KernParas &kernparas){

	//Optimization parameter setting
	double w_smooth_spatio = optparas.w_smooth_spatio;		//weight of the spatial smoothness term
	double w_sparsity = optparas.w_sparsity;				//weight of the sparsity term
	double epsilon = optparas.epsilon;						//used in smooth term : (epsilon + exp) / (epsilon + 1)
	double gamma = optparas.gamma;							//used in re - weighting. 1 / (f + gamma) : [1 / (maxf + gamma), 1 / gamma]
	double m_scale = optparas.m_scale;						//downsize image
	double maxiter = optparas.maxiter; 
	double tol = optparas.tol;								//the max iteration and tolerance in the optimization

	//Kernel parameter setting
	double R = kernparas.R;
	double W = kernparas.W;
	double radius = kernparas.radius;

	//Remove constant items in phase contrast image by a second - order polynomial surface
	Mat im = background_removal(src_img);





}
