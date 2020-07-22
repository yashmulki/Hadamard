//
// Created by Yashvardhan Mulki on 2020-07-18.
//

#include "QuantumBilliardBall.h"
#include "../HmdMatrix/MatrixReader.h"
#include "../HmdVector/VectorReader.h"
#include <iostream>

using namespace demos;

void QuantumBilliardBall::marbles() {

    // Create matrix and vector readers
    hmd::MatrixReader matrixReader;
    hmd::VectorReader vectorReader;

    std::cout << "Please enter adjacency matrix" << std::endl;
    hmd::HmdMatrix adjacency = matrixReader.readMatrix();

    std::cout << "Please enter initial state vector" << std::endl;
    hmd::HmdVector state = vectorReader.readVector();

    int time_clicks;

    std::cout << "Please enter number of time-clciks" << std::endl;
    std::cin >> time_clicks;

    for (int i = 1; i < time_clicks + 1; i++) {
        std::cout << "Adjacency Matrix at Time " << i << std::endl;
        std::cout << adjacency.description();

        std::cout << "State Vector at Time " << i << std::endl;
        std::cout << (state.action(adjacency).description());
        adjacency = adjacency * adjacency;
    }

}