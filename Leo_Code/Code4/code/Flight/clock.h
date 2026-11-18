/***************************************************************************
 * TNG033: lecture 4                                                        *
 * Defines a class Clock to represent a clock as hh:mm:ss                   *
 * header file clock.h                                                      *
 * **************************************************************************/

#pragma once

#include <iostream>

class Clock {
public:
    // constructor -- can be used as default constructor
    Clock(int h = 0, int m = 0, int s = 0);

    Clock(const Clock& c) = default;

    Clock& operator=(const Clock& C) = default;

    ~Clock() = default;

    int get_hours() const {
        return hh;
    }
    int get_minutes() const {
        return mm;
    }
    int get_seconds() const {
        return ss;
    }

    void reset();  // resets the clock to 00:00:00

    // To add 1s more to the clock
    void tick();  // does not allow cascading

    // Overloaded stream insertion operator -- lecture 7
    friend std::ostream& operator<<(std::ostream& os, const Clock& c);

private:
    // represent time as hh:mm:ss
    int hh;  // 0-23
    int mm;  // 0-59
    int ss;  // 0-59
};
