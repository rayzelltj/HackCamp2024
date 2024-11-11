#include <iostream>
#include "symptoms.h"

int main() {
    Symptoms symptoms;
    vector<string> top3 = symptoms.findSymptoms("Burning");

    for (string symptom: top3) {
        cout << symptom << endl;
    }
    
    return 0;
}