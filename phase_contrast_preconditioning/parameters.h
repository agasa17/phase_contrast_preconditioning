#pragma once

#include<string>

using namespace std;

struct OptParas{
	OptParas(
	//èâä˙íl
	double	c_w_smooth_spatio = 0.3,
	double	c_w_sparsity = 0.15,
	double	c_sel = 3,
	double	c_epsilon = 3,
	double	c_gamma = 3,
	double	c_m_scale = 1,
	double	c_maxiter = 100,
	double	c_tol = 10
	){
		w_smooth_spatio = c_w_smooth_spatio;
		w_sparsity = c_w_sparsity;
		sel = c_sel;
		epsilon = c_epsilon;
		gamma = c_gamma;
		m_scale = c_m_scale;
		maxiter = c_maxiter;
		tol = c_tol;
	}

	double w_smooth_spatio;	//weight of the spatial smoothness term
	double w_sparsity;		//weight of the sparsity term
	double sel;				//maximum number of selected basis
	double epsilon;			//used in smooth term : (epsilon + exp) / (epsilon + 1)
	double gamma;			//used in re - weighting. 1 / (f + gamma) : [1 / (maxf + gamma), 1 / gamma]
	double m_scale;			//%downsize image
	double maxiter;			//the max iteration in optimization
	double tol;				//tolerance in the optimization
};

struct KernParas{
	KernParas(
	double c_R = 4.0,
	double c_W = 0.8,
	double c_radius = 2.0,
	double c_zetap = 0.8,
	double c_dicsize = 20
	){
		R = c_R;
		W = c_W;
		radius = c_radius;
		zetap = c_zetap;
		dicsize = c_dicsize;
	}

	double R;		//Outer radius of phase ring;
	double W;		//width of phase ring;
	double zetap;	//amplitude attenuation factors caused by phase ring.
	//R, W and zetap are provided by microscope manufacturers
	double radius;	//radius of kernel
	double dicsize;	//size of dictionary 
};