//
// Created by Joshua Sutton
// 11/10/2018
//

#ifndef ALPHABETTHREE_H
#define ALPHABETTHREE_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>

using namespace std;

class AlphabetThree
{
private:
    char symbols[3] = {'A', 'B', 'C'};
    int numLines;
    string* mapData;
    map<string, map<int, string*>> mappedCodons;

public:
    AlphabetThree();
    ~AlphabetThree();
    void loadMapping(string fileName);
    void checkMapping();
    void mapCodons();
    void listAminoAcids();
};


#endif
