#include <iostream>
#include <fstream>
#include <map>
#include "json.hpp" 
#include "symptoms.h"

using json = nlohmann::json;

int main() {
    
    // Reading from json
    Symptoms symptoms;
    string path = "../app/input.json";
    ifstream file(path);
    string input;
    getline(file, input);

    map<string, string> top3 = symptoms.findSymptoms(input);

    for (auto& lookup: top3) {
        cout << lookup.first << ": " << lookup.second << endl;
    }

    // write to json

    json j;
    
    // Populate the JSON object with the map’s key-value pairs
    for (const auto& pair : top3) {
        j[pair.first] = pair.second;
    }

    string filename = "../app/src/symptoms.json";

    // Write JSON to file
    ofstream output(filename);
    if (output.is_open()) {
        output.write(j.dump(4).c_str(), j.dump(4).size());
        output.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
    
    return 0;
}