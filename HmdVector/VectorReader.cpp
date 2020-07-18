//
// Created by Yashvardhan Mulki on 2020-07-18.
//

#include "VectorReader.h"
#include <iostream>

using namespace hmd;

HmdVector VectorReader::readVector() {
    int num_rows;
    std::cout << "Please enter the number of rows" << std::endl;
    std::cin >> num_rows;

    std::vector<hmd::Complex> data;
    double real;
    double imaginary;

    for (int r = 0; r < num_rows; r++) {
        std::cin >> real;
        std::cin >> imaginary;
        data.push_back(hmd::Complex(real, imaginary));
    }

    return HmdVector(data);
}