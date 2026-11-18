/***************************************************************************
 * TNG033: lecture 4                                                        *
 * Implementation of class Clock                                            *
 * source file clock.cpp                                                    *
 * **************************************************************************/

#include <string>

#include "clock.h"

Clock::Clock(int h, int m, int s) : hh{h}, mm{m}, ss{s} {
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

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const Clock& c) {
    std::string s_hh = (c.hh < 10) ? "0" + std::to_string(c.hh) : std::to_string(c.hh);
    std::string s_mm = (c.mm < 10) ? "0" + std::to_string(c.mm) : std::to_string(c.mm);
    std::string s_ss = (c.ss < 10) ? "0" + std::to_string(c.ss) : std::to_string(c.ss);

    os << s_hh << ":" << s_mm << ":" << s_ss << '\n';

    return os;
}