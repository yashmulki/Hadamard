//
// Created by Yashvardhan Mulki on 2020-07-22.
//

#include "Qubit.h"

using namespace hmd;

Complex Qubit::transitionAmplitude(HmdVector toState) const {
    HmdVector bra = toState.conjugate();
    hmd::Complex amplitude = bra*state;
    return amplitude;
}

Qubit::Qubit(const HmdVector &state) : state(state) {

}
