//
// Created by Joshua Sutton
// 11/10/2018
//

#include "../include/AlphabetThree.h"

// Constructor
AlphabetThree::AlphabetThree()
{
    symbols = new char[3];
}

// Destructor
AlphabetThree::~AlphabetThree()
{
    delete [] symbols;
}

// Load the mapping data
void AlphabetThree::loadMapping(string fileName)
{
    // Open the map file
    ifstream codonMapFile(fileName);
    char map[256];

    // Check if the file could be opened
    if(codonMapFile.fail())
    {
        cerr << "Error opening file \"" << fileName << "\"." << endl;
        codonMapFile.close();
        exit(3);
    }

    // Grab each line from the map file
    while(!codonMapFile.eof())
    {
        // Get the next line of data
        codonMapFile.getline(map, 256);

        // Break if the eof was reached
        if(codonMapFile.eof())
            break;

        string line = string(map);
        int pos = line.find(':');
        string name = line.substr(0, pos);
        cout << "Name of Codon: " << name << endl;
    }
}

// Check that the mapping covers all possible codons
void AlphabetThree::checkMapping()
{

}

// Map codons to amino acids
void AlphabetThree::mapCodons()
{

}
