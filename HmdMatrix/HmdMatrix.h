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
    private:
        std::vector<std::vector<Complex>> elements;
    public:
        HmdMatrix (std::vector<std::vector<Complex>> elements): elements(elements) {};

        HmdMatrix operator+(const HmdMatrix& b); // Adding in C^n
        HmdMatrix scalarMultiply(Complex scalar);
        HmdMatrix additiveInverse();

        std::string description();
    };

}


#endif //HADAMARD_HMDMATRIX_H
