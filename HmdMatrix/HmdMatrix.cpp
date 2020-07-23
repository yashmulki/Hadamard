//
// Created by Yashvardhan Mulki on 2020-07-05.
//

#include "HmdMatrix.h"
#include "../HmdVector/HmdVector.h"
#include <string>
#include <vector>
#include <iostream>
#include <random>

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
                item = item + (elements.at(row).at(i)*b.elements.at(i).at(col));
            }
            rowVec.push_back(item);
        }
        result.push_back(rowVec);
    }

    return HmdMatrix(result);
}

HmdMatrix HmdMatrix::tensorProduct(hmd::HmdMatrix other) {
    int rows = elements.size();
    int cols = elements.at(0).size();

    int otherRows = other.elements.size();
    int otherCols = other.elements.at(0).size();

    int combinedRows = rows * otherRows;
    int combinedColumns = cols * otherCols;

    // Keep track of a matrix of matrices for each spot, where each matrix is the scalar product of A[row][col] with B
    std::vector<std::vector<HmdMatrix>> intermediate;

    for (int row = 0; row < rows; row++) {
        std::vector<HmdMatrix> rowN;
        for (int col = 0; col < cols; col++) {
            rowN.push_back(other.scalarMultiply(elements.at(row).at(col)));
        }
        intermediate.push_back(rowN);
    }

    // "Pop" the matrices out and combine them into one

    std::vector<std::vector<Complex>> result;

    for (int row = 0; row < combinedRows; row++) {
        std::vector<Complex> rowN;
        for (int col = 0; col < combinedColumns; col++) {

            // Get the row and col of target matrix
            int matrixRowIndex = row / otherRows;
            int matrixColIndex = col / otherCols;

            // Get the row and col of target complex number in the matrix
            int complexRowIndex = row;
            int complexColIndex = col;

            if (matrixRowIndex == 0) {

            } else {
                complexRowIndex = row % (otherRows * matrixRowIndex);
            }

            if (matrixColIndex == 0) {

            } else {
                complexColIndex = col % (otherCols * matrixColIndex);
            }

            rowN.push_back(intermediate.at(matrixRowIndex).at(matrixColIndex).elements.at(complexRowIndex).at(complexColIndex));
        }
        result.push_back(rowN);
    }

    return result;
}

bool HmdMatrix::operator==(const hmd::HmdMatrix &b) {
    const double tolerance = 0.01;
    int rows = elements.size();
    int cols = elements.at(0).size();

    int otherRows = b.elements.size();
    int otherCols = b.elements.at(0).size();

    if (rows != otherRows || cols != otherCols) {
        return false;

    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if ((elements.at(row).at(col) - b.elements.at(row).at(col)).getReal() < tolerance && (elements.at(row).at(col) - b.elements.at(row).at(col)).getImaginary() < tolerance) {
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

bool HmdMatrix::isUnitary() {
    HmdMatrix result = HmdMatrix(elements) * HmdMatrix(elements).adjoint();
    int rows = result.elements.size();
    int cols = result.elements.at(0).size();

    std::cout << result.description();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (row == col && result.elements.at(row).at(col) == Complex(1,0)) {
                // This is expected
            } else if (row != col && result.elements.at(row).at(col) == Complex(0,0)) {

            } else {
                return false;
            }
        }
    }
    return true;
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

HmdMatrix HmdMatrix::identity(int n) {
    std::vector<std::vector<Complex>> result;
    for (int row = 0; row < n; row++) {
        std::vector<Complex> column(n, Complex(0,0));
        column.at(row) = Complex(1, 0);
        result.push_back(column);
    }
    return HmdMatrix(result);
}

std::map<double, std::vector<Complex>> HmdMatrix::eignVecVal() {

    std::map<double, std::vector<Complex>> result;

    // Remind user that input needs to be hermitian
    if (!isHermitian()) {
        std::cout << "Warning: finding eigenvectors is unsupported for non hermitian matrices" << std::endl;
    }

    // This is very inefficient, but until more optimization can be made this uses the power iteration technique to find eigenvalues
    int num_eigen = elements.size();

    // Find every eigenvalue
    for (int i = 0; i < num_eigen; i++) {

        // Generate a random vector
        std::random_device rnd_device;
        // Specify the engine and distribution.
        std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
        std::normal_distribution<double> dist(0.0, 1.0); // Normalized standard distribution

        auto gen = [&dist, &mersenne_engine](){
            return dist(mersenne_engine);
        };

        std::vector<double> templateVec(elements.size());
        std::vector<Complex> vec;
        generate(begin(templateVec), end(templateVec), gen);

        for (int k = 0; k < elements.size(); k++) {
            vec.push_back(Complex(templateVec.at(k), 0));
        }

        // Set the rows corresponding to discovered eigenvalues to zero to prevent convergence
        for (int j = 0; j < i; j++) {
            vec.at(j) = Complex(0,0);
        }

        // Do the power iteration process
        HmdVector v = HmdVector(vec);
        v = v.scalarMultiply(Complex(1/v.norm(),0));
        HmdVector previous  = v;

        while(true) {
            previous = v;
            v = v.action(HmdMatrix(elements));
            v = v.scalarMultiply(Complex(1/v.norm(),0));
            if (v == previous) {
                // Found an eigenvector, need to find a corresponding eigenvalue
                HmdVector origV = HmdVector(vec);
                Complex eigenVal;

                for (int row = 0; row < vec.size(); row++) {
                    if (v.elements.at(row).getReal() != 0 || v.elements.at(row).getImaginary() != 0) {
                        eigenVal = v.elements.at(row) / origV.elements.at(row);
                    }
                }

                result.insert(std::pair<double, std::vector<Complex>>(eigenVal.getReal(), v.elements));
                break;
            }
        }

    }

    return result;

}

