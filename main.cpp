#include <iostream>
#include <vector>
#include "Complex/Complex.h"
#include "HmdVector/HmdVector.h"

int main() {

    int num_elements;
    std::cout << "Please enter the number of elements" << std::endl;
    std::cin >> num_elements;

    std::vector<hmd::Complex> data;

    double real;
    double imaginary;

    for (int i = 0; i < num_elements; i++) {
        std::cin >> real;
        std::cin >> imaginary;
        data.push_back(hmd::Complex(real, imaginary));
    }

    hmd::HmdVector vec1 = hmd::HmdVector(data);
    hmd::HmdVector smultiply = vec1.scalarMultiply(hmd::Complex(2, 0));

    std::cout << smultiply.description();

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