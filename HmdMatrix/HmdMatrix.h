//
// Created by Yashvardhan Mulki on 2020-07-05.
//

#ifndef HADAMARD_HMDMATRIX_H
#define HADAMARD_HMDMATRIX_H

#include <vector>
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

        std::string description() const;

        static HmdMatrix identity(int n);

    };

}


#endif //HADAMARD_HMDMATRIX_H
