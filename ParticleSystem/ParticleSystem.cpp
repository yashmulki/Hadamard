//
// Created by Yashvardhan Mulki on 2020-07-22.
//

#include "ParticleSystem.h"
#include "../Complex/Complex.h"
#include "../HmdVector/VectorReader.h"
#include <iostream>
#include <vector>

using namespace demos;

void ParticleSystem::particleSystemDemo() {

    int num_points;
    std::cout << "Please enter the number of mutually exclusive end states" << std::endl;
    std::cin >> num_points;

    std::cout << "Please enter the initial ket state vector" << std::endl;
    hmd::VectorReader reader;
    hmd::HmdVector ket = reader.readVector();

    int program_mode;

    std::cout << "Enter 0 to calculate probability of finding the particle at a given point, or enter 1 to determine probability of transitioning to another ket" << std::endl;
    std::cin >> program_mode;

    if (program_mode == 0) {

        int point_location;
        std::cout << "Please enter a point between 0 and " << num_points << std::endl;
        std::cin >> point_location;

        std::vector<hmd::Complex> base_state(num_points);
        base_state.at(num_points) = hmd::Complex(1, 0);

        hmd::HmdVector bra(base_state);
        bra = bra.conjugate();

        hmd::Complex amplitude = bra*ket;
        std::cout << amplitude.description() << std::endl;

    } else {
        std::cout << "Please enter the end state vector" << std::endl;
        hmd::HmdVector bra = reader.readVector();
        hmd::Complex amplitude = bra*ket;
        std::cout << amplitude.description() << std::endl;
    }

}