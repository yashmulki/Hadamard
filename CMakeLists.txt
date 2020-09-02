cmake_minimum_required(VERSION 3.14)
project(Hadamard)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hadamard main.cpp Complex/Complex.h Complex/Complex.cpp HmdVector/HmdVector.cpp HmdVector/HmdVector.h HmdMatrix/HmdMatrix.cpp HmdMatrix/HmdMatrix.h HmdMatrix/MatrixReader.cpp HmdMatrix/MatrixReader.h HmdVector/VectorReader.cpp HmdVector/VectorReader.h QuantumMarbles/QuantumBilliardBall.cpp QuantumMarbles/QuantumBilliardBall.h ParticleSystem/ParticleSystem.cpp ParticleSystem/ParticleSystem.h Qubit/Qubit.cpp Qubit/Qubit.h Observables/Observable.cpp Observables/Observable.h Helpers/matplotlibcpp.h QuantumCircuit/QuantumCircuit.cpp QuantumCircuit/QuantumCircuit.h QuantumCircuit/DefaultGates.cpp QuantumCircuit/DefaultGates.h)
find_package(Python2 COMPONENTS Development NumPy)
target_include_directories(Hadamard PRIVATE ${Python2_INCLUDE_DIRS} ${Python2_NumPy_INCLUDE_DIRS})
target_link_libraries(Hadamard Python2::Python Python2::NumPy)
#add_submodule(eigen)
#target_link_library(Hadamard PUBLIC Eigen3::Eigen)