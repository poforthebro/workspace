
 /* 
 * Header file observation.h contains the class declaration of WindObservation
 */

#pragma once

#include <string>

#include "../Clock/clock.h"

class WindObservation {
public:
    // We need to add constructors here
    WindObservation() = default; // Use default value. Initiates as instructed
    WindObservation(double s, std::string u, double d, Clock t) 
    : speed{s}, unit{u}, direction{d}, timeStamp{t}, calibration{nullptr} {}

    // Copy constructor
    WindObservation(const WindObservation& c) = default; 


	// ADD declaration of required member functions
    WindObservation& operator=(WindObservation rhs);
    std::string cardinalDirection() const; 
    std::string getUnit() const;
    
    // Calibration
    void setCalibration(double speedF, double speedO);
    void removeCalibration();
    bool hasCalibration() const;
    double calibratedSpeed() const;


    void display() const;

private:
    class WindCalibration;

    double speed = 0.0;
    std::string unit = "m/s";              // "m/s", "km/h", or "mph"
    double direction = 0.0;              // degrees in [0, 360)
    Clock timeStamp{12, 0, 0};
    WindCalibration* calibration = nullptr;  // nullptr means no calibration

};
