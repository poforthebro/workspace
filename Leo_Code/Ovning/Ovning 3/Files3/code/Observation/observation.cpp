/*
 * Source file observation.cpp contains the class implementation of WindObservation
 * member functions and the nested class WindCalibration implementation
 */


#include <iostream>
#include <format>

#include "observation.h"

/*
 * Calibration parameters for a wind-speed measurement
 * The offset is expressed in the same units as the wind speed
 */
class WindObservation::WindCalibration {
public:
    WindCalibration(double speedFactor = 1.0, double speedOffset = 0.0)
        : speedFactor{speedFactor}, speedOffset{speedOffset} {
    }

    // Return the calibrated value: measuredSpeed * factor + offset
    double correctSpeed(double measuredSpeed) const {
        return measuredSpeed * speedFactor + speedOffset;
    }

    double speedFactor;
    double speedOffset;
};

/* ********************************************************************************** */

// ADD WindObservation member functions implementation

// Function for the assignment opereator
WindObservation& WindObservation::operator=(WindObservation rhs) {
    std::swap(speed, rhs.speed);
    std::swap(unit, rhs.unit);
    std::swap(direction, rhs.direction);
    std::swap(timeStamp, rhs.timeStamp);
    calibration = new WindCalibration();
    setCalibration(rhs.calibration->speedFactor, rhs.calibration->speedOffset);
    
    return *this;
}

// Function to get the cardinal directions from the degrees (N, S, E, W) 
 std::string WindObservation::cardinalDirection() const{
    std::string cDir = "O";
    if((0.0 <= direction && direction <= 45.0) || ( 315.0 <= direction && direction <= 360.0 )) {
        cDir = "N";
    } 
    else if(46.0 < direction && direction <= 135.0) {
        cDir = "E";
    }
    else if(136.0 < direction && direction <= 225.0) {
        cDir = "S";
    }
    else if(226.0 < direction && direction <= 315.0) {
        cDir = "W";
    }
    return cDir;
 }


// Get the unit used for a function
std::string WindObservation::getUnit() const{
    return unit;
}

// Set calibration. This function can be updated with removeCalibration to be able to automatically update cuntion

void WindObservation::setCalibration(double speedF, double speedO){
    if(calibration == nullptr) {
        calibration = new WindCalibration(speedF, speedO);
    } else {
        calibration->speedFactor = speedF;
        calibration->speedOffset = speedO;
    }
    
  return; 
}

// Remove calibration
void WindObservation::removeCalibration() {
    delete calibration;
    calibration = nullptr;
}

bool WindObservation::hasCalibration() const{
    bool hasC = true;
    if(calibration == nullptr) {
        hasC = false;
    }
    return hasC;
}



double WindObservation::calibratedSpeed() const{
    return calibration->correctSpeed(speed); 

}


void WindObservation::display() const {
    std::cout << std::format("Speed: {:.2f} {}, Direction: {}, Timestamp: ", speed, unit,
                             cardinalDirection());
    timeStamp.display();
    if (hasCalibration()) {
        std::cout << std::format("Calibrated speed: {:.2f} {}\n", calibratedSpeed(), unit);
    }
}
