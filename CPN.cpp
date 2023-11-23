#include <iostream>
#include <fstream>

class CentralPolygonalNumbers {
public:
  CentralPolygonalNumbers();
  CentralPolygonalNumbers(int nMax); 
  ~CentralPolygonalNumbers(); 
  void display();
  bool save(std::string strFilename);

private:
  int m_nMax;
  int* mp_iNumbers; // Pointer to an array of integers
};

// Default constructor
CentralPolygonalNumbers::CentralPolygonalNumbers() : m_nMax(0), mp_iNumbers(nullptr) {
  // Allocate the array of integers
  mp_iNumbers = new int[1];
  // Calculate values in the sequence and store in the array
  for (int n = 0; n <= m_nMax; ++n) {
    mp_iNumbers[n] = n * (n + 1) / 2 + 1; // Lazy Caterer's Sequence formula
  }
}

// Overloaded constructor
CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax) : m_nMax(nMax), mp_iNumbers(nullptr) {
  // Allocate the array of integers
  mp_iNumbers = new int[m_nMax + 1];
  // Calculate values in the sequence and store in the array
  for (int n = 0; n <= m_nMax; ++n) {
    mp_iNumbers[n] = n * (n + 1) / 2 + 1; // Lazy Caterer's Sequence formula
  }
}

// Destructor
CentralPolygonalNumbers::~CentralPolygonalNumbers() {
  // Deallocate the memory for the array
  delete[] mp_iNumbers;
  std::cout << "Central Polygonal Numbers called" << std::endl;
}

// Display function
void CentralPolygonalNumbers::display() {
  for (int n = 0; n <= m_nMax; ++n) {
    std::cout << "n: " << n << ", maximum number of pieces: " << mp_iNumbers[n] << std::endl;
  }
}

// Save function
bool CentralPolygonalNumbers::save(std::string strFilename) {
  std::ofstream ofsNumbers(strFilename);
  if (!ofsNumbers.is_open()) {
    std::cerr << "Error opening file: " << strFilename << std::endl;
    return false;
  }

  // Iterate over the array and write each number to the output file stream
  for (int n = 0; n <= m_nMax; ++n) {
    ofsNumbers << mp_iNumbers[n] << std::endl;
  }

  // Close the file
  ofsNumbers.close();
  return true;
}

int main() {
  // Create an instance of the class with maximum n set to 10
  CentralPolygonalNumbers cpn(10);
  
  // Display the sequence to standard output
  cpn.display(); 
  
  // Save the sequence to a file named "CPN"
  cpn.save("CPN");

  return 0;
}
