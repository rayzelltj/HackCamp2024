#include "symptoms.h"
#include <fstream>
#include <sstream>
using namespace std;

Symptoms::Symptoms() {
    // loadFromFile("");
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

// void Symptoms::saveToFile(string filename) {
//     ofstream outFile(filename);
//     for (auto& entry : symp_key) {
//         outFile << entry.first << ": ";

//         for (auto& word : entry.second) {
//             outFile << word << " ";
//         }

//         outFile << endl;
//     }

//     outFile.close();
// }

void Symptoms::loadFromFile(const string& filename) {
    ifstream inFile(filename);
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