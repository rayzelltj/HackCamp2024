#include <iostream>
#include <fstream>
#include "symptoms.h"

int main() {
    Symptoms symptoms;
    string path = "app/input.json";
    ifstream file(path);
    string input;
    getline(file, input);

    map<string, string> top3 = symptoms.findSymptoms(input);

    return 0;
}