#include "symptoms.h"
#include <fstream>
using namespace std;

void Symptoms::addValue(string key, string value) {
    symp_key[key].insert(value);
}

void Symptoms::addkey(string key) {
    symp_key[key] = set<string>();
}

vector<string> Symptoms::find(string word) {
    vector<string> keywords;
    for (auto& key_val : symp_key) {
        if (key_val.second.count(word) > 0) {
            keywords.push_back(key_val.first);
        }
    }
    return keywords;
}

void Symptoms::saveToFile(string filename) {
    ofstream outFile(filename);
    for (auto& entry : symp_key) {
        outFile << entry.first << ": ";

        for (auto& word : entry.second) {
            outFile << word << ", ";
        }

        outFile << "." << endl;
    }

    outFile.close();
}

void Symptoms::loadFromFile(string filename) {
    ifstream inFile(filename);
    string line;
    while (getline(inFile, line)) 
}