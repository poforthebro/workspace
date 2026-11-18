/***************************************************************************
 * TNG033: lecture 4                                                        *
 * Implementation of class Flight                                           *
 * source file flight.cpp                                                   *
 * **************************************************************************/

#include "flight.h"

Flight::Flight(int n)
    : number{n}  // default constructor is called for for clocks "dep" and "arrival"
//: number{ n }, dep{ }, arr{ }
{ }

Flight::Flight(int n, const Clock& d, const Clock& a) : number{n}, dep{d}, arr{a} {
}

// Overloaded stream insertion operator -- lecture 7
std::ostream& operator<<(std::ostream& os, const Flight& f) {
    os << "Flight " << f.number << " departs at " << f.dep << " and arrives at " << f.arr;

    return os;
}
