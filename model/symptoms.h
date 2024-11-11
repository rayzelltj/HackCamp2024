#ifndef SYMPTOMS_H
#define SYMPTOMS_H

#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <new>
#include <utility>
#include <map>

using namespace std;

/*
This will be class the contains the dictionary that maps the inaccurrate 
description of symptoms to medical terms for the symptoms
*/

class Symptoms {
public:

    // Constructor that initializes the private fields
    Symptoms();


    map<string, string> findSymptoms(string sentence);


private:
    // functions to add new keys or values
    void addValue(string key, string value);

    // HELPER FUNCTIONS

    // Helper functions to help with the parsing done by the constructor
    void parseDefinitions();
    void parseKeywords();
    void parseCommonWords();
    void saveToFile(string filename);

    // Converts sentence to lower case and removes punctuation
    string simplifySentence(string sentence);

    // Filters out the common words
    set<string> filterSentence(string sentence);

    // Finds the top 3 symptoms and returns it
    map<string, string> top3symptoms(map<string, int> symptomCount); 

    // FIELDS

    // Stores the name of the symptoms and keywords associated with it
    map<string, set<string>> symp_key;

    // Stores the name of the symptoms and definition associated with it
    map<string, string> symp_def;

    // Stores the common words that we should lookout for
    set<string> common;

    

};

#endif 