#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Eigen>
#include "nnls.h"

using namespace Eigen;

extern "C" {

    void nnlsd(double* A, double* b, double* c, int d1, int d2);
	 
	void nnlsf(float* A, float* b, float* c, int d1, int d2);

	void nnls_doublearray(double* input1, double* input2, double* output_ptr, int d1, int d2);

	void nnls_floatarray(float* input1, float* input2, float* output_ptr, int d1, int d2);
	

}

void nnlsd(double* A, double* b, double* c, int d1, int d2){ 
            
            MatrixXd AMat = Map<MatrixXd> (A, d1, d2);

            VectorXd bV = Map<VectorXd> (b, d1);

            VectorXd x(d2);
            
            NNLS<MatrixXd>::solve(AMat, bV, x);


			Map<VectorXd>( c, x.rows(), x.cols() ) = x;

}

void nnlsf(float* A, float* b, float* c, int d1, int d2){ 
            
            MatrixXf AMat = Map<MatrixXf> (A, d1, d2);

            VectorXf bV = Map<VectorXf> (b, d1);

            VectorXf x(d2);
            
            NNLS<MatrixXf>::solve(AMat, bV, x);


			Map<VectorXf>( c, x.rows(), x.cols() ) = x;

}

// now the pointers represent two array of length equal to len
void nnls_doublearray(double* input1, double* input2, double* output_ptr, int d1, int d2){
	
	nnlsd(input1,  input2,  output_ptr,  d1,  d2);

}

// now the pointers represent two array of length equal to len
void nnls_floatarray(float* input1, float* input2, float* output_ptr, int d1, int d2){
	
	nnlsf(input1,  input2,  output_ptr,  d1,  d2);

}


