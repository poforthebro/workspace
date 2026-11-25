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

