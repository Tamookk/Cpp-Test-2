//
// Created by Joshua Sutton
// 11/10/2018
//

#ifndef ALPHABETFOUR_H
#define ALPHABETFOUR_H


class AlphabetFour
{
private:
    char* symbols[4];

public:
    AlphabetFour();
    ~AlphabetFour();
    void loadMapping();
    void checkMapping();
    void mapCodons();
};


#endif
