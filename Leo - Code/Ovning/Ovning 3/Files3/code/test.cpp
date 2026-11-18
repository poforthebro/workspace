/*
 * Test program for the WindObservation class with optional calibration information
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Observation/observation.h"

/*
 * Read wind observations from stream is (file)
 * Return a vector with the wind observations read
 */
std::vector<WindObservation> readObservationsFile(std::ifstream& is) {
    std::vector<WindObservation> observations;
    double speed;
    double direction;
    std::string unit;
    std::string time;

    while (is >> speed >> unit >> direction >> time) {
        // break time into its components
        int hh;
        int mm;
        int ss;
        char c;
        std::istringstream iss{time};
        iss >> hh >> c >> mm >> c >> ss;

        observations.push_back(WindObservation{speed, unit, direction, Clock{hh, mm, ss}});
    };
    return observations;
}

int main() {
    std::cout << "Phase 0: reading wind observations from file\n";

    // Create and open a stream for file reading
    std::ifstream inFil("../code/wind_observations.txt");  // modify this path, if needed

    if (!inFil) {  // test if the streams is in bad state
        std::cout << "Wind data file could not be opened!!\n";
        return 0;
    }

    // Read wind observations from file
    std::vector<WindObservation> observations = readObservationsFile(inFil);

    if (observations.empty()) {
        std::cout << "No wind observations were read from the file.\n";
        return 0;
    }

    // Display the wind observations
    std::cout << "\nWind observations:\n";
    for (const auto& obs : observations) {
        obs.display();
        std::cout << '\n';
    }

    /* ********************************** */
    std::cout << "Phase 1: manual calibration\n";

    // Add a calibration with a factor of 1.1 and an offset of 0.5 to the first observation
    observations[0].setCalibration(1.1, 0.5);

    // Remove calibration from the second observation
    if (observations.size() > 1) {
        observations[1].removeCalibration();
    }

    // Display the wind observations
    std::cout << "\nWind observations with calibration:\n";
    for (const auto& obs : observations) {
        obs.display();
        std::cout << '\n';
    }

    /* ********************************** */
    std::cout << "Phase 2: copy constructor\n";

    // Create a copy of the first observation and modify its calibration factors
    WindObservation copiedObservation = observations[0];  // copy
    copiedObservation.setCalibration(1.25, -0.2);         // modify calibration

    std::cout << "\nCopied observation with modified calibration:\n";
    copiedObservation.display();
    std::cout << '\n';

    // Display the original observation to show that it is unchanged
    std::cout << "\nOriginal observation (unchanged):\n";
    observations[0].display();
    std::cout << '\n';

    // Delete the calibration from the copied observation
    copiedObservation.removeCalibration();

    // Display the copied observation after removing calibration
    std::cout << "\nCopied observation after removing calibration:\n";
    copiedObservation.display();

    // Display the original observation to show that it is unchanged
    std::cout << "\nOriginal observation (unchanged):\n";
    observations[0].display();
    std::cout << '\n';

    /* ****************************** */
    std::cout << "Phase 3: assignment operator\n";

    // Add a calibration with a factor of 1.2 and an offset of -0.3 to the third observation
    if (observations.size() > 2) {
        observations[2].setCalibration(1.2, -0.3);
    }
  

    // Display the copied observation
    std::cout << "\nCopied observation with calibration:\n";
    copiedObservation.display();

    // Remove the calibration from observations[2]
    if (observations.size() > 2) {
        observations[2].removeCalibration();
    }

    // Display the original observation
    std::cout << "\nOriginal observation after removing calibration:\n";
    observations[2].display();
    std::cout << '\n';

    // Display the copied observation
    std::cout << "Copied observation:\n";
    copiedObservation.display();
    std::cout << '\n';
}