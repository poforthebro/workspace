/*********************************************************
 * Class Expression member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include <cmath>

#include "expression.h"

// Initialize the counter of the total number of existing Expressions
std::size_t Expression::count_expressions = 0;

/*
 *  Return number of existing instances of class Expression
 *  Used only for debug purposes
 */
std::size_t Expression::get_count_expressions() {
    return Expression::count_expressions;
}

/* ************************* */



std::string to_string() {
    std::string outString;

    return outString; // Change to appropriate
}


double evaluate(double x) {
    double y = 0;

    return y;
}

bool is_root(double x); {

    return false; // Update
}

std::ostream& operator<<(std::ostream& os, const Expression& E) {

    return os;
}

Expression* clone() {
    Expression* theClone = Expression();


}