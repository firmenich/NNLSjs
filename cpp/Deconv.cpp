#include <emscripten/bind.h>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Eigen>
#include "nnls.h"

using namespace Eigen;

class deconv{
    // other stuff
    public:
        deconv() {
        }

        std::vector<double>  A;
        std::vector<double>  b;
        std::vector<double>  res;
        int d1;
        int d2;

        void init(int d1, int d2){
            std::vector<double>  A(d1*d2);
            std::vector<double>  b(d1);

            this->A = A;
            this->b = b;
            this->d1 = d1;
            this->d2 = d2;
        }

        void setA(int index, double value){
            this->A[index]=value; 
        }

        void setb(int index, double value){
            this->b[index]=value; 
        }

        double getA(int index){
            return this->A[index]; 
        }

        double getb(int index){
            return this->b[index]; 
        }

        double getRes(int index){
            return this->res[index]; 
        }

        void calc(){  
                MatrixXd AMat = Map<MatrixXd> (this->A.data(), this->d1, this->d2);

                VectorXd bV = Map<VectorXd> (this->b.data(), this->d1);

                VectorXd x(this->d2);
                NNLS<MatrixXd>::solve(AMat, bV, x);

                std::vector<double> calcres;
                
                for (int i=0; i<this->d2;i++)
                {
                    calcres.push_back(x[i]);
                }

                this->res = calcres;
            }
};

EMSCRIPTEN_BINDINGS(Deconv) {
    emscripten::class_<deconv>("deconv")
        .constructor()
        .function("init",&deconv::init)
        .function("setA",&deconv::setA)
        .function("setb",&deconv::setb)
        .function("getA",&deconv::getA)
        .function("getb",&deconv::getb)
        .function("getRes",&deconv::getRes)
        .function("calc",&deconv::calc)
        ;
};