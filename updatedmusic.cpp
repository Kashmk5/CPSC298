#include "musical notes.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

// Constants
const double k_dFrequencyRef = 16.35; // Reference Frequency (C0)
const double k_dSpeedOfSound = 345.0; // Speed of sound in air (m/s)
const double k_dCmPerMeter = 100.0; // Conversion factor from meters to centimeters

// Function to compute frequency using the given formula
double computeFrequency(int k, int v) {
    return k_dFrequencyRef * std::pow(2.0, v + k / 12.0);
}

// Function to compute wavelength using the given formula
double computeWavelength(double frequency) {
    return k_dSpeedOfSound / frequency;
}

// Function to get the name of the note given its octave number and halftone index value
std::string getNoteName(int octave, int halfStep) {
    const std::string noteNames[] = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
    };

    int index = (octave - 1) * 12 + halfStep;
    if (index >= 0 && index < 88) {
        return noteNames[index];
    }

    return "Unknown";
}

int main() {
    std::cout << "Speed of sound in air: " << k_dSpeedOfSound << " m/s" << std::endl;

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
        std::cout << "Wavelength: " << std::fixed << std::setprecision(2) << wavelength * k_dCmPerMeter << " cm" << std::endl;
        std::cout << "Note Name: " << getNoteName(note.octave, note.halfStep) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
