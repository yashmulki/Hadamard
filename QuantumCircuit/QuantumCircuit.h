//
// Created by Yashvardhan Mulki on 2020-09-02.
//

#ifndef HADAMARD_QUANTUMCIRCUIT_H
#define HADAMARD_QUANTUMCIRCUIT_H

#include <vector>
#include "../Qubit/Qubit.h"
#include "../HmdMatrix/HmdMatrix.h"

namespace hmd {
    class QuantumCircuit {
    private:
        std::vector<Qubit> qubits; // Store all current qubits
        std::vector<HmdMatrix> gates;
    public:
        int num_qubits;

        QuantumCircuit(std::vector<Qubit> qubits);
        void addGate(HmdMatrix gate, int toQubit);
        void runSimulation();


    };
}


#endif //HADAMARD_QUANTUMCIRCUIT_H
