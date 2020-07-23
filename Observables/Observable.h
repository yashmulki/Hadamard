//
// Created by Yashvardhan Mulki on 2020-07-22.
//

#ifndef HADAMARD_OBSERVABLE_H
#define HADAMARD_OBSERVABLE_H

#include "../HmdMatrix/HmdMatrix.h"
#include "../HmdVector/HmdVector.h"

namespace hmd {

    class Observable {
    public:
        HmdMatrix observable;

        Observable(HmdMatrix &observable);

        double expectedValue(HmdVector state);
        double variance(HmdVector state);

    };
}


#endif //HADAMARD_OBSERVABLE_H
