#include <iostream>
#include "symptoms.h"

int main() {
    Symptoms symptoms;
    map<string, string> top3 = symptoms.findSymptoms("ill dizzy vertigo");

    for (auto& lookup: top3) {
        cout << lookup.first << ": " << lookup.second << endl;
    }
    
    return 0;
}