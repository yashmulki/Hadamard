#include <iostream>

int main() {
    int num_qubits;

    // Welcome users and take in length
    std::cout << "Welcome to Hadamard --> Simple Quantum Computer Simulator" << std::endl;
    std::cout << "Please enter the number of Qubits you'd like to simulate" << std::endl;
    std::cin >> num_qubits;

    for (int i = 0; i < num_qubits; i++) {
        std::cout << "Please enter (space separated) the initial state of Qubit " << (i+1) << std::endl;

        // check if state is normaliezd
    }


    return 0;
}