#pragma once

#include <iostream>

#include "expression.h"

class Power : public Expression {
public:


	// Update 1.34! it is now completely readable!
	Power(double b = 0, int e = 0) : Expression(), base(b), exponent(e) {} // Default Contructor ( number or base)	






	~Power() = default; // Destructor that doesnt have dynamic memory so default 





	Power(const Power&) = default; // Copy, by reference and default





	Power& operator=(const Power&) = default; // Operator= assigment, allowed to be default, unlike constant





	void change_expotent(int e);





	Power* clone() const override;





	double evaluate() const override;






	void display(std::ostream& os) const override;

private: 
    double base;
	int exponent;
};  