//
// Created by Yashvardhan Mulki on 2020-09-02.
//

#ifndef HADAMARD_DEFAULTGATES_H
#define HADAMARD_DEFAULTGATES_H


#include "../HmdMatrix/HmdMatrix.h"

namespace hmd {
    class DefaultGates {
    public:
        HmdMatrix hadamard();
        HmdMatrix zeros();
        HmdMatrix cnot();
        HmdMatrix identity();
        HmdMatrix rtheta(double angle);
    };
}

#endif //HADAMARD_DEFAULTGATES_H
