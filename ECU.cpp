#include <iostream>

class ElectronicControlUnit {
private:
    bool m_bActivatedHydraulicJacks;
    bool m_bActivatedBeltTires;
    bool m_bActivatedIRIllumination;

    // Private method to toggle hydraulic jacks
    void toggleHydraulicJacks() {
        m_bActivatedHydraulicJacks = !m_bActivatedHydraulicJacks;
        std::cout << "Hydraulic Jacks " << (m_bActivatedHydraulicJacks ? "activated" : "deactivated") << ".\n";
        
        // Deactivate Belt Tires if Hydraulic Jacks are activated
        if (m_bActivatedHydraulicJacks && m_bActivatedBeltTires) {
            toggleBeltTires();
        }
    }

    // Private method to toggle belt tires
    void toggleBeltTires() {
        if (!m_bActivatedHydraulicJacks) { // Only toggle Belt Tires if Hydraulic Jacks are not active
            m_bActivatedBeltTires = !m_bActivatedBeltTires;
            std::cout << "Belt Tires " << (m_bActivatedBeltTires ? "activated" : "deactivated") << ".\n";
        } else {
            std::cout << "Cannot activate Belt Tires while Hydraulic Jacks are activated.\n";
        }
    }

    // Private method to toggle IR Illumination
    void toggleIRIllumination() {
        m_bActivatedIRIllumination = !m_bActivatedIRIllumination;
        std::cout << "IR Illumination " << (m_bActivatedIRIllumination ? "activated" : "deactivated") << ".\n";
    }

public:
    // Constructor
    ElectronicControlUnit() : m_bActivatedHydraulicJacks(false), m_bActivatedBeltTires(false), m_bActivatedIRIllumination(false) {}

    // Destructor
    ~ElectronicControlUnit() {}

    // Public method to handle command inputs
    void handleCommand(char cCommand) {
        switch (cCommand) {
            case 'A': // Fall through
            case 'a':
                toggleHydraulicJacks();
                break;
            case 'B': // Fall through
            case 'b':
                toggleBeltTires();
                break;
            case 'E': // Fall through
            case 'e':
                toggleIRIllumination();
                break;
            default:
                std::cout << "Invalid command.\n";
                break;
        }
    }
};

int main() {
    ElectronicControlUnit ecu;
    char command;

    std::cout << "Control Unit Initialized. Enter command (A, B, E) or 'X' to exit:\n";

    // Main interaction loop
    while (std::cin >> command && command != 'X' && command != 'x') {
        ecu.handleCommand(command);
    }

    std::cout << "System Shutdown.\n";
    return 0;
}