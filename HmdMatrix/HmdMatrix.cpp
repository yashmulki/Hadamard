//
// Created by Yashvardhan Mulki on 2020-07-05.
//

#include "HmdMatrix.h"
#include <string>
#include <vector>
#include <iostream>

using namespace hmd;

// Addition of two hmd vectors
HmdMatrix HmdMatrix::operator+(const HmdMatrix &b) {
    int rows = elements.size();
    int cols = elements.at(0).size();

    int otherRows = b.elements.size();
    int otherCols = b.elements.at(0).size();

    std::vector<std::vector<Complex>> result;

    for (int row = 0; row < std::max(rows, otherRows); row++) {
        std::vector<Complex> rowVec;
        for (int col = 0; col < std::max(cols, otherCols); col++) {
            Complex sum = Complex(0,0);

            if (row < rows && col < elements.at(row).size()) {
                sum = sum + elements.at(row).at(col);
            }

            if (row < otherRows && col < b.elements.at(row).size()) {
                sum = sum + b.elements.at(row).at(col);
            }
            rowVec.push_back(sum);
        }
        result.push_back(rowVec);
    }
    return HmdMatrix(result);
}

HmdMatrix HmdMatrix::operator*(const HmdMatrix &b) {
    int rows = elements.size();
    int cols = elements.at(0).size();

    int otherRows = b.elements.size();
    int otherCols = b.elements.at(0).size();

    std::vector<std::vector<Complex>> result;

    if (cols != otherRows) {
        return HmdMatrix(result);
    }

    for (int row = 0; row < rows; row++) {
        std::vector<Complex> rowVec;
        for (int col = 0; col < otherCols; col++) {
            Complex item = Complex(0,0);
            for (int i = 0; i < cols; i++) {
                std::cout << row << " " << col << " " << i << std::endl;
                std::cout << elements.at(row).at(i).description() << std::endl;
                std::cout << b.elements.at(i).at(col).description() << std::endl;
                item = item + (elements.at(row).at(i)*b.elements.at(i).at(col));
            }
            rowVec.push_back(item);
        }
        result.push_back(rowVec);
    }

    return HmdMatrix(result);
}

bool HmdMatrix::operator==(const hmd::HmdMatrix &b) {
    int rows = elements.size();
    int cols = elements.at(0).size();

    int otherRows = b.elements.size();
    int otherCols = b.elements.at(0).size();

    if (rows != otherRows || cols != otherCols) {
        return false;

    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (elements.at(row).at(col) == b.elements.at(row).at(col)) {
                // They are the same
            } else {
                return false;
            }
        }
    }

    return true;

}

bool HmdMatrix::isHermitian() {
    if (elements.size() != elements.at(0).size()) return false;
    return adjoint() == *this;
}

HmdMatrix HmdMatrix::conjugate() {
    int rows = elements.size();
    int cols = elements.at(0).size();
    std::vector<std::vector<Complex>> result;

    for (int row = 0; row < rows; row++) {
        std::vector<Complex> column;
        for (int col = 0; col < cols; col++) {
            if (col < elements.at(row).size()) {
                column.push_back(elements.at(row).at(col).conjugate());
            }
        }
        result.push_back(column);
    }
    return HmdMatrix(result);
}

HmdMatrix HmdMatrix::transpose() {
    int nRows = elements.at(0).size(); // Rows in new matrix, columns in old
    int nCols = elements.size(); // Columns in new matrix, rows in old
    std::vector<std::vector<Complex>> result;
    // Loop through new matrix and create it
    for (int nRow = 0; nRow < nRows; nRow++) {
        result.push_back(std::vector<Complex>());
        for (int nCol = 0; nCol < nCols; nCol++) {
            result.at(nRow).push_back(elements.at(nCol).at(nRow));
        }
    }
    return HmdMatrix(result);
}

HmdMatrix HmdMatrix::adjoint() {
    return conjugate().transpose();
}


HmdMatrix HmdMatrix::scalarMultiply(Complex scalar) {
    int rows = elements.size();
    int cols = elements.at(0).size();
    std::vector<std::vector<Complex>> result;

    for (int row = 0; row < rows; row++) {
        std::vector<Complex> column;
        for (int col = 0; col < cols; col++) {
            if (col < elements.at(row).size()) {
                column.push_back(elements.at(row).at(col) * scalar);
            }
        }
        result.push_back(column);
    }
    return HmdMatrix(result);
}

HmdMatrix HmdMatrix::additiveInverse() {
    return scalarMultiply(Complex(-1,0));
}

std::string HmdMatrix::description() const {
    int cols = elements.at(0).size();
    std::string desc = "";
    int rows = elements.size();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (col < elements.at(row).size()) {
                desc += elements.at(row).at(col).description() + ", ";
            } else {
                desc += "0 + 0i, ";
            }
        }
        desc += '\n';
    }
    return desc;
}

