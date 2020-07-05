//
// Created by Yashvardhan Mulki on 2020-07-04.
//

#include <string>
#include "HmdVector.h"

using namespace hmd;

// Addition of two hmd vectors
HmdVector HmdVector::operator+(const HmdVector &b) {
    unsigned long myLen = elements.size();
    unsigned long otherLen = b.elements.size();
    std::vector<Complex> result;

    for (int i = 0; i < std::max(myLen, otherLen); i++) {
        Complex newElement = Complex(0,0);

        if (i < myLen) {
            newElement = newElement + elements.at(i);
        }

        if (i < otherLen) {
            newElement = newElement + b.elements.at(i);
        }
        result.push_back(newElement);
    }
    return HmdVector(result);
}

HmdVector HmdVector::scalarMultiply(Complex scalar) {
    unsigned long myLen = elements.size();
    std::vector<Complex> result;
    for (int i = 0; i < myLen; i++) {
        result.push_back(scalar * elements.at(i));
    }
    return HmdVector(result);
}

HmdVector HmdVector::additiveInverse() {
    return scalarMultiply(Complex(-1,0));
}

std::string HmdVector::description() {
    std::string output = "";
    for (int i = 0; i < elements.size(); i++) {
        output += elements.at(i).description();
        output += '\n';
    }
    return output;
}
