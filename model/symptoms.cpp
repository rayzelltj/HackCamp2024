#include "symptoms.h"
#include <fstream>
#include <sstream>
using namespace std;

Symptoms::Symptoms() {
    parseKeywords();
    parseDefinitions();
}

void Symptoms::addValue(string key, string value) {
    symp_key[key].insert(value);
}

void Symptoms::addkey(string key) {
    symp_key[key] = set<string>();
}

vector<string> Symptoms::findWord(string word) {
    vector<string> keywords;
    for (auto& key_val : symp_key) {
        if (key_val.second.count(word) > 0) {
            keywords.push_back(key_val.first);
        }
    }
    return keywords;
}

void Symptoms::parseKeywords() {
    ifstream inFile("symptoms_keywords.txt");
    string line;

    while (getline(inFile, line)) {
        line.erase(line.find_last_not_of(" \t\n") + 1);

        size_t colonPos = line.find(':');
        if (colonPos != string::npos) {
            // Extract the keyword (everything before the colon)
            string keyword = line.substr(0, colonPos);

            // Extract the words string (everything after the colon)
            string wordsStr = line.substr(colonPos + 1);

            // Remove leading spaces from words string
            wordsStr.erase(0, wordsStr.find_first_not_of(" \t"));

            // Use stringstream to split the words by spaces
            stringstream ss(wordsStr);
            string word;
            while (getline(ss, word, ' ')) {
                // Remove leading and trailing spaces from each word
                word.erase(0, word.find_first_not_of(" \t"));
                word.erase(word.find_last_not_of(" \t") + 1);

                if (!word.empty()) {
                    addValue(keyword, word);
                }
            }
        }
    }

    inFile.close();
}

void Symptoms::parseDefinitions() {
    ifstream inFile("symptoms_definitions.txt");
    string line;

    while (getline(inFile, line)) {
        line.erase(line.find_last_not_of(" \t\n") + 1);  // Remove trailing spaces and newlines

        size_t colonPos = line.find(':');
        if (colonPos != string::npos) {
            // Extract the keyword (everything before the colon)
            string keyword = line.substr(0, colonPos);

            // Extract the definition string (everything after the colon)
            string definitionStr = line.substr(colonPos + 1);

            // Remove leading spaces from definition string
            definitionStr.erase(0, definitionStr.find_first_not_of(" \t"));

            symp_def[keyword] = definitionStr;
        }
    }

    inFile.close();
}