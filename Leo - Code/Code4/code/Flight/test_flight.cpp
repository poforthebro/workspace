/**********************************************************
 * TNG033: lecture 4                                      *
 * Simple test program for class Flight                   *
 * ********************************************************/

#include <iostream>
#include <vector>

#include "flight.h"

int main() {
    Clock departure{10, 30};
    Clock arrival{18, 30};

    Flight F1{112, departure, arrival};
    Flight F2{501};

    std::cout << F1 << '\n';
    std::cout << F2 << '\n';

    // Test if it's possible to create a vector of flights
    // std::vector<Flight> sto_airport(4);
}
