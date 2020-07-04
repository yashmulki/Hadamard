//
// Created by Yashvardhan Mulki on 2020-06-18.
//

#include "Complex.h";
#include <cmath>
#include <string>
#include <utility>

using namespace hmd;

Complex Complex::createFromPolar(double p, double theta) {
    double a = p * cos(theta);
    double b = p * sin(theta);
    return Complex(a, b);
}

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

Complex Complex::operator+(const Complex &b) {
    return Complex(real+b.getReal(), imaginary+b.getImaginary());
}

Complex Complex::operator*(const hmd::Complex &b) {
    double realComponent = real * b.getReal() - (imaginary * b.getImaginary());
    double imaginaryComponent = real * b.getImaginary() + imaginary*b.getReal();
    return Complex(realComponent, imaginaryComponent);
}

Complex Complex::operator-(const hmd::Complex &b) {
    return Complex(real-b.getReal(), imaginary-b.getImaginary());
}

Complex Complex::operator/(const hmd::Complex &b) {
    double modulusSquared = pow(b.modulus(), 2);
    double realComponent = real*b.getReal() + imaginary*b.getImaginary();
    double imaginaryComponent = imaginary*b.getReal() - real*b.getImaginary();
    return Complex(realComponent/modulusSquared, imaginaryComponent/modulusSquared);
}

Complex Complex::conjugate() const {
    return Complex(real, -1*imaginary);
}

double Complex::modulus() const {
    return sqrt(pow(real,2) + pow(imaginary, 2));
}

std::pair<double, double> Complex::polarRepresentation() {
    double p = modulus();
    double theta = tan(imaginary/real);
    return std::make_pair(p, theta);
}

std::string Complex::description() {
    return std::to_string(real) + " + " + std::to_string(imaginary) + "i";
}

// Constructor
Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}



