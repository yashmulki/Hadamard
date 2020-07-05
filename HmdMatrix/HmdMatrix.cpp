//
// Created by Yashvardhan Mulki on 2020-07-05.
//

#include "HmdMatrix.h"
#include <string>
#include <vector>

using namespace hmd;

// Addition of two hmd vectors
HmdMatrix HmdMatrix::operator+(const HmdMatrix &b) {
    int cols = elements.size();
    int rows = elements.at(0).size();

    int otherCols = b.elements.size();
    int otherRows = b.elements.at(0).size();

    std::vector<std::vector<Complex>> result;

    for (int col = 0; col < std::max(cols, otherCols); col++) {
        std::vector<Complex> column;
        for (int row = 0; row < std::max(rows, otherRows); row++) {
            Complex sum = Complex(0,0);

            if (col < cols && row < elements.at(col).size()) {
                sum = sum + elements.at(col).at(row);
            }

            if (col < otherCols && row < b.elements.at(col).size()) {
                sum = sum + b.elements.at(col).at(row);
            }
            column.push_back(sum);
        }
        result.push_back(column);
    }
    return result;
}

HmdMatrix HmdMatrix::scalarMultiply(Complex scalar) {
    int cols = elements.size();
    int rows = elements.at(0).size();
    std::vector<std::vector<Complex>> result;

    for (int col = 0; col < cols; col++) {
        std::vector<Complex> column;
        for (int row = 0; row < rows; row++) {
            if (row < elements.at(col).size()) {
                column.push_back(elements.at(col).at(row) * scalar);
            }
        }
        result.push_back(column);
    }
    return result;
}

HmdMatrix HmdMatrix::additiveInverse() {
    return scalarMultiply(Complex(-1,0));
}

std::string HmdMatrix::description() {
    int cols = elements.size();
    std::string desc = "";

    int rows = elements.at(0).size();
    for (int col = 0; col < cols; col++) {
        for (int row = 0; row < rows; row++) {
            if (row < elements.at(col).size()) {
                desc += elements.at(col).at(row).description() + ", ";
            } else {
                desc += "0 + 0i, ";
            }
        }
        desc += '\n';
    }
    return desc;
}

