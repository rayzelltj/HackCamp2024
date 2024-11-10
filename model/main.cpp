#include <iostream>
#include "symptoms.h"

int main() {
    Symptoms symptoms;
    std::cout << "Testing: symptoms.cpp compiled" << std::endl;
    symptoms.loadFromFile("symptoms_keywords.txt");
    for (auto& entry : symptoms.symp_key) {
        std::cout << entry.first << ": ";
        for (const auto& word : entry.second) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}