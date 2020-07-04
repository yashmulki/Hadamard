//
// Created by Yashvardhan Mulki on 2020-07-04.
//

#ifndef HADAMARD_HMDVECTOR_H
#define HADAMARD_HMDVECTOR_H

#include <vector>
#include <string>
#include "../Complex/Complex.h"

namespace hmd {

    // An abelian group with scalar multiplication --> Complex vector space
    class HmdVector {

    private:
        std::vector<Complex> elements;
    public:
        HmdVector (std::vector<Complex> elements): elements(elements) {};

        HmdVector operator+(const HmdVector& b); // Adding in C^n
        HmdVector scalarMultiply(Complex scalar);
        HmdVector additiveInverse();

        std::string description();
    };

}


#endif //HADAMARD_HMDVECTOR_H
