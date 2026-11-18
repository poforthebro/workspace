/***************************************************************************
 * TNG033: lecture 4                                                        *
 * Implementation of class Clock                                            *
 * source file clock.cpp                                                    *
 * **************************************************************************/

#include <string>

#include "clock.h"

#define DEBUG 1  // set to 0 to make debugging statements invisible to the compiler

Clock::Clock(int h, int m, int s) : hh{h}, mm{m}, ss{s} {
}

// Destructor
Clock::~Clock() {
#if DEBUG       // if DEBUG is set to 1 then the following statements are visible to the compiler
    display();  // display the clock
    std::cout << " destroyed!!" << '\n';
#endif
}

/*
// Copy constructor
// Not needed - compiler generated copy constructor does the same
// Shallow copy done by default
Clock::Clock(const Clock& c) : hh{c.hh}, mm{c.mm}, ss{c.ss} {
}
*/

/*
//Assignment operator
//Not needed - compiler generated assignment operator does the same
Clock& Clock::operator=(const Clock& C) {
    //shallow copy by default
    hh = C.hh;
    mm = C.mm;
    ss = C.ss;

    return *this;
}
*/

void Clock::display(bool write_sec) const {
    std::string s_hh = (hh < 10) ? "0" + std::to_string(hh) : std::to_string(hh);
    std::string s_mm = (mm < 10) ? "0" + std::to_string(mm) : std::to_string(mm);
    std::string s_ss = (ss < 10) ? "0" + std::to_string(ss) : std::to_string(ss);

    if (write_sec) {
        std::cout << s_hh << ":" << s_mm << ":" << s_ss << '\n';
    } else {
        std::cout << s_hh << ":" << s_mm << '\n';
    }
}

void Clock::reset() {
    hh = mm = ss = 0;
}

void Clock::tick() {
    ss = (ss + 1) % 60;
    if (ss == 0) {
        mm = (mm + 1) % 60;
        if (mm == 0) {
            hh = (hh + 1) % 24;
        }
    }
}
