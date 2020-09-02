//
// Created by Yashvardhan Mulki on 2020-07-05.
//

#ifndef HADAMARD_HMDMATRIX_H
#define HADAMARD_HMDMATRIX_H

#include <vector>
#include <map>
#include <string>
#include "../Complex/Complex.h"

namespace hmd {

    class HmdMatrix {
    public:

        std::vector<std::vector<Complex>> elements;
        HmdMatrix (std::vector<std::vector<Complex>> elements): elements(elements) {};

        bool operator==(const HmdMatrix& b);
        HmdMatrix operator+(const HmdMatrix& b); // Adding in C^n
        HmdMatrix operator*(const HmdMatrix& b); // Matrix multiplication
        HmdMatrix scalarMultiply(Complex scalar);
        bool isHermitian();
        bool isUnitary();
        HmdMatrix conjugate();
        HmdMatrix transpose();
        HmdMatrix adjoint();
        HmdMatrix tensorProduct(HmdMatrix other);
        HmdMatrix additiveInverse();
        std::map<double, std::vector<Complex>> eignVecVal();
        std::string description() const;



        static HmdMatrix identity(int n);

    };

}


#endif //HADAMARD_HMDMATRIX_H
