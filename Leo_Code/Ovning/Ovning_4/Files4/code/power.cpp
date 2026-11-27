#include <iostream>

#include "power.h"

// Add class Power member functions implementation
void Power::change_expotent(int e) {
	exponent = e; 
}

Power* Power::clone() const {
    Power* ptrnm = new Power(base,exponent);
    return ptrnm;
}
double Power::evaluate() const {
    return std::pow(base, exponent);
}
void Power::display(std::ostream& os) const {
    os << base << "^" << exponent;
}

/*
* Note: non-pure virtual functions must be implemented, even if they are not called
* otherwise, a linker error will be generated 
* If an implementation is not yet ready, a function stub can be used as a placeholder
*/