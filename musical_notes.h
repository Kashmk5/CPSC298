
#ifndef MUSICAL_NOTES_H
#define MUSICAL_NOTES_H

#include <string>

// Constants
const double k_dFrequencyRef = 16.35; // Reference Frequency (C0)
const double k_dSpeedOfSound = 345.0; // Speed of sound in air (m/s)
const double k_dCmPerMeter = 100.0; // Conversion factor from meters to centimeters

// Function to compute frequency using the given formula
// Precondition: k must be a non-negative integer and v must be an integer
double computeFrequency(int k, int v);

// Function to compute wavelength using the given formula
// Precondition: frequency must be a positive number
double computeWavelength(double frequency);

// Function to get the name of the note given its octave number and halftone index value
// Precondition: octave must be a positive integer and halfStep must be an integer between 0 and 11
std::string getNoteName(int octave, int halfStep);

#endif
