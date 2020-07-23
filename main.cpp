#include <iostream>
#include <vector>
#include "Complex/Complex.h"
#include "HmdVector/HmdVector.h"
#include "HmdMatrix/HmdMatrix.h"
#include "QuantumMarbles/QuantumBilliardBall.h"
#include "ParticleSystem/ParticleSystem.h"
#include "HmdMatrix/MatrixReader.h"
#include "HmdVector/VectorReader.h"
#include "Observables/Observable.h"

int main() {

    hmd::MatrixReader matReader;
    hmd::HmdMatrix obs = matReader.readMatrix();
    hmd::VectorReader vecReader;
    hmd::HmdVector state = vecReader.readVector();

    hmd::Observable observable(obs);

    std::cout << "The expected value is " << observable.expectedValue(state) << " and the variance is " << observable.variance(state) << std::endl;

    return 0;
}

