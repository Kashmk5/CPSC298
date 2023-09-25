#include <iostream>
#include <iomanip>
#include <cmath>

// Constants
const double fR = 16.35; // Reference Frequency (C0)
const double speedOfSound = 345.0; // Speed of sound in air (m/s)
const double cmPerMeter = 100.0; // Conversion factor from meters to centimeters

// Function to compute frequency using the given formula
double computeFrequency(int k, int v) {
    return fR * pow(2.0, v + k / 12.0);
}

// Function to compute wavelength using the given formula
double computeWavelength(double frequency) {
    return speedOfSound / frequency;
}

int main() {
    std::cout << "Speed of sound in air: " << speedOfSound << " m/s" << std::endl;

    // Notes to compute frequencies and wavelengths for
    struct Note {
        std::string name;
        int octave;
        int halfStep;
    };

    Note notes[] = {
        {"C#0", 0, 1},
        {"D0", 0, 2},
        {"D3", 3, 2},
        {"C4", 4, 0},
        {"D#7", 7, 3},
        {"C8", 8, 0}
    };

    for (const Note& note : notes) {
        double frequency = computeFrequency(note.halfStep, note.octave);
        double wavelength = computeWavelength(frequency);

        std::cout << "Note: " << note.name << std::endl;
        std::cout << "Frequency: " << std::fixed << std::setprecision(2) << frequency << " Hz" << std::endl;
        std::cout << "Wavelength: " << std::fixed << std::setprecision(2) << wavelength * cmPerMeter << " cm" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
