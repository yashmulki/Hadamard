#include <iostream>
#include <vector>
#include "Complex/Complex.h"
#include "HmdVector/HmdVector.h"
#include "HmdMatrix/HmdMatrix.h"

int main() {
//
//    int num_rows;
//    int num_cols;
//    std::cout << "Please enter the number of rows and columns" << std::endl;
//    std::cin >> num_rows;
//    std::cin >> num_cols;
//
//    std::vector<std::vector<hmd::Complex>> data;
//
//    double real;
//    double imaginary;
//
//    for (int r = 0; r < num_rows; r++) {
//        std::vector<hmd::Complex> row;
//        for (int c = 0; c < num_cols; c++) {
//            std::cin >> real;
//            std::cin >> imaginary;
//            std::cin.clear();
//            row.push_back(hmd::Complex(real, imaginary));
//        }
//        data.push_back(row);
//    }
//
//    hmd::HmdMatrix first(data);
//
//    std::cout << first.isUnitary();
//    std::cout << std::endl;

//    std::cout << "Please enter the number of rows and columns" << std::endl;
//    std::cin >> num_rows;
//    std::cin >> num_cols;
//
//
//    std::vector<std::vector<hmd::Complex>> data2;
//
//    double real2;
//    double imaginary2;
//
// 0.5 0.5 0.5 -0.5
//0.5 -0.5 0.5 0.5

//    for (int r = 0; r < num_rows; r++) {
//        std::vector<hmd::Complex> row;
//        for (int c = 0; c < num_cols; c++) {
//            std::cin >> real2;
//            std::cin >> imaginary2;
//            row.push_back(hmd::Complex(real2, imaginary2));
//        }
//        data2.push_back(row);
//    }
//
//    hmd::HmdMatrix second = hmd::HmdMatrix(data2);
//    std::cout << second.description();
//    std::cout << std::endl;
//
//    hmd::HmdMatrix product = first * second;
//
//    std::cout << product.description();

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

    int num_rows_2;
    std::cout << "Please enter the number of rows" << std::endl;
    std::cin >> num_rows_2;

    std::vector<hmd::Complex> data2;
    for (int r = 0; r < num_rows_2; r++) {
        std::cin >> real;
        std::cin >> imaginary;
        data2.push_back(hmd::Complex(real, imaginary));
    }

    hmd::HmdVector vec1 = hmd::HmdVector(data);
    hmd::HmdVector vec2 = hmd::HmdVector(data2);

    hmd::HmdVector difference = vec1.tensorProduct(vec2);
    std::cout << difference.description();
//    std::cout << vec1.distanceFrom(vec2);

//    double distance = vec1.distanceFrom(vec2);
//    std::cout << distance;

    //  int num_qubits;


    // Welcome users and take in length
//    std::cout << "Welcome to Hadamard --> Simple Quantum Computer Simulator" << std::endl;
//    std::cout << "Please enter the number of Qubits you'd like to simulate" << std::endl;
//    std::cin >> num_qubits;
//
//    for (int i = 0; i < num_qubits; i++) {
//        std::cout << "Please enter (space separated) the initial state of Qubit " << (i+1) << std::endl;
//
//        // check if state is normaliezd
//    }


    return 0;
}