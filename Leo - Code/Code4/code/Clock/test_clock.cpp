/*******************************************************
 * TNG033: lecture 4                                   *
 * Simple test program for class Clock                 *
 * *****************************************************/

#include <iostream>
#include <vector>

#include "clock.h"

int main() {
    Clock c1;         // default constructor is called: 00:00:00
    Clock c2{10, 5};  // constructor called: 10:05:00 -- by default the 3rd argument is zero

    std::cout << "Clock 1: ";
    c1.display();

    std::cout << "Clock 2: " << c2.get_hours() << " hours and " << c2.get_minutes()
              << " minutes and " << c2.get_seconds() << " seconds\n";

    Clock* c3{new Clock{12, 31, 50}};  // constructor called

    std::cout << "Clock 3: ";
    c3->display();

    const Clock c4{c2};  // copy constructor is called
    // only const member functions can be applied to c4

    std::cout << "Clock 4: ";
    c4.display();

    // c4.reset(); //compiler error cause Clock::reset() is not a 'const member function'

    // Increment clock c2 by 120 seconds
    for (int i = 1; i <= 120; i++) {
        c2.tick();
    }

    std::cout << "Clock 2: ";
    c2.display();  // 10:07:00

    c2.reset();

    std::cout << "Clock 2: ";
    c2.display();

    // Initialization of a vector with non-default initialized clocks
    std::vector<Clock> V1{Clock{12, 30, 0}, Clock{10, 30, 0}, Clock{11, 30, 0}, Clock{9, 30, 0}};

    std::cout << "\nAll clocks in V1: default constructor called for each of them\n";
    for (const Clock& c : V1) {  // range-based loops can be used to loop through vectors
        c.display();
    }
    /*
    for (int i = 0; i < std::ssize(V1); i++) {
        V1[i].display();
    }
    */

    std::vector<Clock> V2(4);
    // default constructor Clock() called to initialize each clock in the vector

    std::cout << "\nAll clocks in V2: default constructor called for each of them\n";
    for (const Clock& c : V2) {  // range-based loops can be used to loop through vectors
        c.display();
    }

    // Modify the clocks in V2
    std::cout << "\nModifying the clocks in V2 ...\n";
    V2[0] = c1;
    V2[1] = c2;
    V2[2] = *c3;
    V2[3] = c4;

    std::cout << "All clocks in V2 ...\n";
    for (const Clock& c : V2) {
        c.display();
    }

    Clock c6{};

    c6 = c2 = c1;  // assignment operator is called

    std::cout << "\nClock 2: ";
    c2.display();

    std::cout << "Clock 6: ";
    c6.display();
    std::cout << "\n";

    delete c3;
}
