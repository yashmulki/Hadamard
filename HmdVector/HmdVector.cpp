//
// Created by Yashvardhan Mulki on 2020-07-04.
//

#include <string>
#include <math.h>
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

HmdVector HmdVector::operator-(const hmd::HmdVector &b)  {
    return HmdVector(this->elements) + b.scalarMultiply(Complex(-1,0));
}

HmdVector HmdVector::scalarMultiply(Complex scalar) const {
    unsigned long myLen = elements.size();
    std::vector<Complex> result;
    for (int i = 0; i < myLen; i++) {
        result.push_back(scalar * elements.at(i));
    }
    return HmdVector(result);
}

HmdVector HmdVector::action(HmdMatrix matrix, bool left) {
    unsigned long myLen = elements.size();
    unsigned long matrixRows = matrix.elements.size();
    unsigned long matrixCols = matrix.elements.at(0).size();

    std::vector<Complex> result;

    if (matrixCols != myLen) {
        return HmdVector(elements);
    }

    if (left) {
        for (int matCol = 0; matCol < matrixCols; matCol++) {
            Complex colVal = Complex(0,0);
            for (int matRow = 0; matRow < matrixRows; matRow++) {
                colVal = colVal + matrix.elements.at(matRow).at(matCol) * elements.at(matRow);
            }
            result.push_back(colVal);
        }
        return HmdVector(result);
    }



    for (int matRow = 0; matRow < matrixRows; matRow++) {
        Complex rowVal = Complex(0,0);
        for (int i = 0; i < myLen; i++) {
            rowVal = rowVal + (matrix.elements.at(matRow).at(i) * elements.at(i));
        }
        result.push_back(rowVal);
    }
    return HmdVector(result);
}

Complex HmdVector::operator*(HmdVector other) {
    unsigned long size = elements.size();
    unsigned long otherSize = other.elements.size();

    Complex innerProduct = Complex(0,0);

    if (size != otherSize) {
        return Complex(0,0);
    }

    for (int i = 0; i < size; i++) {
        innerProduct = innerProduct + (elements.at(i).conjugate()*other.elements.at(i));
    }

    return innerProduct;

}

double HmdVector::norm() {
    Complex result = HmdVector(this->elements) * HmdVector(this->elements);
    return sqrt(result.getReal());
}

double HmdVector::distanceFrom(hmd::HmdVector other) {
    HmdVector difference = HmdVector(this->elements) - HmdVector(other.elements);
    return difference.norm();
}

HmdVector HmdVector::tensorProduct(hmd::HmdVector other) {
    std::vector<Complex> result;
    for (int i = 0; i < elements.size(); i++) {
        for (int j = 0; j < other.elements.size(); j++) {
            result.push_back(elements.at(i)*other.elements.at(j));
        }
    }
    return HmdVector(result);
}



HmdVector HmdVector::conjugate() {
    int myLen = elements.size();
    std::vector<Complex> result;
    for (int i = 0; i < myLen; i++) {
        result.push_back(elements.at(i).conjugate());
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

bool HmdVector::operator==(const HmdVector &b) {
    const double tolerance = 0.01;
    int myLen = elements.size();
    int otherLen = elements.size();

    if (myLen != otherLen) {
        return false;
    }

    for (int i = 0; i < myLen; i++) {
        if ((elements.at(i) - b.elements.at(i)).getReal() < tolerance && (elements.at(i) - b.elements.at(i)).getImaginary() < tolerance) {
            // They are the same
        } else {
            return false;
        }
    }
    return true;
}
