cmake_minimum_required(VERSION 3.14)
project(Hadamard)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hadamard main.cpp Complex/Complex.h Complex/Complex.cpp HmdVector/HmdVector.cpp HmdVector/HmdVector.h HmdMatrix/HmdMatrix.cpp HmdMatrix/HmdMatrix.h HmdMatrix/MatrixReader.cpp HmdMatrix/MatrixReader.h HmdVector/VectorReader.cpp HmdVector/VectorReader.h QuantumMarbles/QuantumBilliardBall.cpp QuantumMarbles/QuantumBilliardBall.h ParticleSystem/ParticleSystem.cpp ParticleSystem/ParticleSystem.h)