#pragma once

#include <iostream>

#include "expression.h"

class Constant : public Expression {
    // ToDo
    public:
    // Constructor
    Constant(const double k = 0) : Expression(), c(k) {}

    // Destructor
    ~Constant() = default; // No dynamic memory so default should be fine


    // Assignment operator
    Constant& operator=(Constant&) = delete;

    double evaluate() const override {
        return c;
    }

    Constant* clone() const override;
    
    void display(std::ostream& os) const override;



    private:

    const double c;
};
