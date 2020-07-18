//
// Created by Yashvardhan Mulki on 2020-07-18.
//

#include "MatrixReader.h"
#include <iostream>

using namespace hmd;

HmdMatrix MatrixReader::readMatrix() {
    int num_rows;
    int num_cols;
    std::cout << "Please enter the number of rows and columns" << std::endl;
    std::cin >> num_rows;
    std::cin >> num_cols;

    std::vector<std::vector<hmd::Complex>> data;

    double real;
    double imaginary;

    for (int r = 0; r < num_rows; r++) {
        std::vector<hmd::Complex> row;
        for (int c = 0; c < num_cols; c++) {
            std::cin >> real;
            std::cin >> imaginary;
            std::cin.clear();
            row.push_back(hmd::Complex(real, imaginary));
        }
        data.push_back(row);
    }

    hmd::HmdMatrix first(data);
    std::cout << std::endl;

    return first;
}