//
// Created by Joshua Sutton
// 11/10/2018
//

#ifndef ALPHABETTHREE_H
#define ALPHABETTHREE_H

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class AlphabetThree
{
private:
    int numLines;
    char base;
    vector<string> possibleCodons;
    string* mapData;
    multimap<string, string> mappedCodons;

public:
    AlphabetThree();
    ~AlphabetThree();
    void setBase(char _base);
    char getBase();
    void loadMapping(string fileName);
    void checkMapping();
    multimap<string, string> mapCodons();
    void listAminoAcids();
};


#endif
