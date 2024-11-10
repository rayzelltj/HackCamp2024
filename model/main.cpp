#include <iostream>
#include "symptoms.h"

int main() {
    Symptoms symptoms;
    std::cout << "Testing: symptoms.cpp compiled" << std::endl;
    symptoms.parseKeywords();
    symptoms.parseDefinitions();
    for (auto& entry : symptoms.symp_key) {
        std::cout << entry.first << ": ";
        for (const auto& word : entry.second) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    cout << "test";
    cout << symptoms.symp_def["tremors"] << endl;
    return 0;
}