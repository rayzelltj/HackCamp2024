#include "symptoms.h"
#include <fstream>
using namespace std;

void Symptoms::addValue(string key, string value) {
    terms[key].insert(value);
}

void Symptoms::addkey(string key) {
    terms[key] = set<string>();
}

vector<string> Symptoms::find(string word) {
    vector<string> keywords;
    for (auto& key_val : terms) {
        if (key_val.second.count(word) > 0) {
            keywords.push_back(key_val.first);
        }
    }
    return keywords;
}

vector<string> Symptoms::countKeys(string word) {

}

void Symptoms::saveToFile(string filename) {
    ofstream outFile(filename);
    for (auto& entry : terms) {
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