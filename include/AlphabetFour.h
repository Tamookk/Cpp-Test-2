//
// Created by Joshua Sutton
// 11/10/2018
//

#ifndef ALPHABETFOUR_H
#define ALPHABETFOUR_H

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class AlphabetFour
{
private:
    int numLines;
    char base;
    vector<string> possibleCodons;
    string* mapData;
    multimap<string, string> mappedCodons;

public:
    AlphabetFour();
    ~AlphabetFour();
    void setBase(char _base);
    char getBase();
    void loadMapping(string filename);
    void checkMapping();
    multimap<string, string> mapCodons();
    void listAminoAcids();
};


#endif
