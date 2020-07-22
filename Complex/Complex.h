//
// Created by Yashvardhan Mulki on 2020-06-18.
//

#ifndef HADAMARD_COMPLEX_H
#define HADAMARD_COMPLEX_H

#include <utility>
#include <string>


namespace hmd {

    class Complex{
    private:
        double real;
        double imaginary;

    public:
        static Complex createFromPolar(double p, double theta);

        double getReal() const;
        double getImaginary() const;

        Complex(double real, double imaginary);
        Complex() {};

        bool operator==(const Complex& b);
        Complex operator+(const Complex& b); // Overload adding
        Complex operator*(const Complex& b); // Multiplying
        Complex operator-(const Complex& b); // Subtracting
        Complex operator/(const Complex& b); // Dividing

        Complex conjugate() const;
        double modulus() const;

        std::pair<double, double> polarRepresentation();

        std::string description() const;

        };

}

#endif
