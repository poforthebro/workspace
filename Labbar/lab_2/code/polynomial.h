/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Polynomial : public Expression {
    // ADD CODE
    public:
    // Destructor? Should use compiler made one since no heap memory

    /*   Constructors   */
    explicit Polynomial(const std::vector<double>& coefficients);   // Vector constructor
    explicit Polynomial(const double& constant); // Constructor from a real constant to a polynomial
    Polynomial(const Polynomial&); // Copy Constructor
    Polynomial& operator=(const Polynomial& rhs);
    Polynomial& operator+=(const Polynomial& rhs);
    Polynomial& operator+(const Polynomial& rhs); // Should work for val + pol or pol + pol
    double operator[](int i);
    std::string to_string(); // Different formating with two decimal places include zeros
    

    private:
    std::vector<double> coefficients;

};

/*
 * std::vector should be used to store polinomial's coefficients
 */