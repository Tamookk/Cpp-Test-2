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
    vector<string> possibleCodons;
    string* mapData;
    multimap<string, string> mappedCodons;

public:
    AlphabetFour();
    ~AlphabetFour();
    void loadMapping(string filename);
    void checkMapping();
    void mapCodons();
    void listAminoAcids();
};


#endif
