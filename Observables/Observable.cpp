//
// Created by Yashvardhan Mulki on 2020-07-22.
//

#include "Observable.h"
#include <iostream>

hmd::Observable::Observable(hmd::HmdMatrix &observable) : observable(observable) {

    if (!observable.isHermitian()) {
        std::cout << "This operator is invalid because it is not hermitian" << std::endl;
    }

}

double hmd::Observable::expectedValue(hmd::HmdVector state) {
    HmdVector applied = state.action(observable);
    Complex expected = applied * state;
    return expected.getReal();
}

double hmd::Observable::variance(hmd::HmdVector state) {
    // Subtract the expected value from the observable
    HmdMatrix identity = HmdMatrix::identity(observable.elements.size());
    HmdMatrix negMean = identity.scalarMultiply(Complex(expectedValue(state), 0)).additiveInverse();
    HmdMatrix demeaned = observable + negMean;
    HmdMatrix demeanedSquared = demeaned * demeaned;
    HmdVector applied = state.action(demeanedSquared);
    Complex variance = state * applied;
    return variance.getReal();
}


