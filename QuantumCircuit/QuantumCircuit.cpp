//
// Created by Yashvardhan Mulki on 2020-09-02.
//

#include "QuantumCircuit.h"
#include "DefaultGates.h"
#include <iostream>


using namespace hmd;

hmd::QuantumCircuit::QuantumCircuit(std::vector<hmd::Qubit> qubits) {
    this->qubits = qubits;
    num_qubits = qubits.size();
}

void QuantumCircuit::addGate(HmdMatrix gate, int toQubit) {
    if (!gate.isUnitary()) {
        return;
    }

    DefaultGates universalSet;
    HmdMatrix generatedGate = toQubit == 0 ? gate : universalSet.hadamard();
    for (int i = toQubit == 0 ? 1 : 0; i < num_qubits; i++) {
        generatedGate = i == toQubit ?  generatedGate.tensorProduct(gate) : generatedGate.tensorProduct(universalSet.hadamard());
    }
    gates.push_back(generatedGate);
}

void QuantumCircuit::runSimulation() {
    HmdVector tensoredState = qubits.front().state;

    if (num_qubits > 1) {

        for (auto iter = next(qubits.begin()); iter < qubits.end(); iter++) {
            auto state = iter->state;
            tensoredState = tensoredState.tensorProduct(state);
        }
    }

    for (auto gate : gates) {
        tensoredState.action(gate);
        std::cout << tensoredState.description();
    }

}


