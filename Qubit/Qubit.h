//
// Created by Yashvardhan Mulki on 2020-07-22.
//

#ifndef HADAMARD_QUBIT_H
#define HADAMARD_QUBIT_H

#include "../HmdVector/HmdVector.h"

namespace hmd {

    class Qubit {
    public:
        HmdVector state;


        Qubit(const HmdVector &state);
        double transitionProbability(HmdVector toState) const;

        Complex transitionAmplitude(HmdVector toState) const;

    };
}


#endif //HADAMARD_QUBIT_H
