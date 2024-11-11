#include "symptoms.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


// Constructor for the symptoms class
Symptoms::Symptoms() {
    parseKeywords();
    parseDefinitions();
    parseCommonWords();
}

// Finds symptoms the patient is describing, and return a map of 
// the symptom name with the number of times it was mentioned by keywords

vector<string> Symptoms::findSymptoms(string sentence) {
    set<string> words = filterSentence(simplifySentence(sentence));
    map<string, int> symptomCount;
    for (string word: words) {
        for (auto& key_val : symp_key) {
            if (key_val.second.count(word) > 0) {
                symptomCount[key_val.first] += 1;
            }
        }
    }
    
    return top3symptoms(symptomCount);
}

// HELPER FUNCTIONS
//
//
//

// Gets the top 3 symptoms and returns it
vector<string> Symptoms::top3symptoms(map<string, int> symptomCount) {
    vector<string> top3;
    if (symptomCount.size() == 0) {
        top3.push_back("No Matches Found");
        return top3;
    }

    // Sort the symptoms by occurrence
    vector<pair<string, int>> symptomCountModified(symptomCount.begin(), symptomCount.end());
    sort(symptomCountModified.begin(), symptomCountModified.end(), [](const auto&a, const auto&b) {
        return a.second > b.second;
    });

    // get the top 3 and return it
    for (int i = 0; i < 3; i++) {
        top3.push_back(symptomCountModified[i].first);
    }

    return top3;
}

// Removes punctuation from sentence and converts letters to lower case, keep spaces
set<string> Symptoms::filterSentence(string sentence) {
    // Add a space to the end of sentence for proper termination
    sentence += " ";

    set<string> words;
    // Iterate through each character in the sentence
    string word;
    for (char ch : sentence) {
    
        // If the character is not a space, add it to the current word
        if (ch != ' ') {
            word += ch;
        }
        // If the character is a space or we've reached the end of the sentence
        else if (!word.empty()) {

            if (common.count(word) == 0) {
                words.insert(word);  // Insert the current word into the set
            }
            word.clear();          // Clear the current word for the next one
        }
    }

    return words;
}

// Another helper that removes the punctuation and makes lower case
string Symptoms::simplifySentence(string sentence) {

    string result;
    
    // Loop through each character of the input string
    for (char ch : sentence) {
        // If the character is a letter or space, process it
        if (std::isalpha(ch)) {
            result += std::tolower(ch);  // Convert to lowercase and add to result
        } else if (ch == ' ') {
            result += ' ';  // Keep spaces
        }
    }
    
    return result;
}

// Put common words into vector
void Symptoms::parseCommonWords() {
    ifstream inFile("common_words.txt");
    string word;

    while (getline(inFile, word)) {
        common.insert(word);
    }

    
}
 
// Puts the symptom name and its corresponding keywords into the map
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

// Put the symptom name and their corresponding definitions the map
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

// Adds the keyword to the symptom key
void Symptoms::addValue(string key, string value) {
    symp_key[key].insert(value);
}