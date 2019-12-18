"""
Copyright 2019 Guillaume GODIN, Firmenich SA.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
"""

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
