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

using namespace std;

class AlphabetThree
{
private:
    char* symbols;
    map<string, map<int, string*>> mappedCodons;

public:
    AlphabetThree();
    ~AlphabetThree();
    void loadMapping(string fileName);
    void checkMapping();
    void mapCodons();
};


#endif
