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
    Symptoms(ifstream definitions, ifstream keywords);

private:

    // Helper functions to help with the parsing done by the constructor
    void parseDefinitions(ifstream definitions);
    void parseKeywords(ifstream keywords);

    // Stores the name of the symptoms and keywords associated with it
    map<string, set<string>> symp_key; 

    // Stores the name of the symptoms and definition associated with it
    map<string, string> symp_def;

};

#endif 