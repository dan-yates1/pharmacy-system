#include "medication.h"

Medication::Medication() {
    // read in medication csv file
    std::ifstream medications_file("../medications.csv");

    while(medications_file.good()) {
        std::string line;
        getline(medications_file, line, ',');
        std::cout << line << std::endl;
    }
}
