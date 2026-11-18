/*
 *  Source file clock.cpp
 */

#include <string>

#include "clock.h"


Clock::Clock(int h, int m, int s) : hh{h}, mm{m}, ss{s} {
}


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