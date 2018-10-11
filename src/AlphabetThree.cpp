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
    char fileLine[256];

    // Check if the file could be opened
    if(codonMapFile.fail())
    {
        cerr << "Error opening file \"" << fileName << "\"." << endl;
        codonMapFile.close();
        exit(3);
    }

    numLines = 0;

    // Grab each line from the map file
    while(!codonMapFile.eof())
    {
        // Get the next line of data
        codonMapFile.getline(fileLine, 256);

        // Break if the eof was reached
        if (codonMapFile.eof())
            break;

        numLines++;
    }

    // Clear the eof flag and return to the start of the file
    codonMapFile.clear();
    codonMapFile.seekg(0, ios::beg);

    mapData = new string[numLines];
    for(int i = 0; i < numLines; i++)
    {
        codonMapFile.getline(fileLine, 256);
        mapData[i] = string(fileLine);
    }
}

// Check that the mapping covers all possible codons
void AlphabetThree::checkMapping()
{

}

// Map codons to amino acids
void AlphabetThree::mapCodons()
{
    for(int i = 0; i < numLines; i++)
    {
        // Extract the name of the amino acid
        string line = mapData[i];
        int pos = line.find(':');
        string name = line.substr(0, pos);

        // Cut out the name of the amino acid
        line = line.substr(pos, line.length());

        // Cut out whitespace/search for a base (any uppercase letter)
        line = line.substr(line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), line.length());

        // Reset the string position
        pos = 0;
        int numCodons = 0;

        // Count the amount of codons
        while(1)
        {
            if(line.find(',', pos) == string::npos)
            {
                numCodons++;
                break;
            }
            else
            {
                pos = line.find(',', pos) + 1;
                numCodons++;
            }
        }

        // Create an array of codons
        pos = 0;
        string* codons = new string[numCodons];
        for(int i = 0; i < numCodons; i++)
        {
            if(line.find(',', pos) == string::npos)
            {
                codons[i] = line;
                break;
            }
            // Put the codon into the array
            codons[i] = line.substr(pos, line.find(','));

            // Trim out the codon and anything that isn't a base
            pos = line.find(',') + 1;
            line = line.substr(pos, line.length());
            line = line.substr(line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), line.length());
            pos = 0;
        }

        // Insert the amino acid info into the map
        map<int, string*> codon;
        codon[numCodons] = codons;

        mappedCodons[name] = codon;
    }
}

// List the amino acids and their codons
void AlphabetThree::listAminoAcids()
{
    for(auto i = mappedCodons.begin(); i != mappedCodons.end(); i++)
    {
        cout << "Amino Acid: " << i->first << endl;
        cout << "Codons: ";
        for(auto j = i->second.begin(); j != i->second.end(); j++)
        {
            for(int k = 0; k < j->first; k++)
                cout << j->second[k] << ",";
        }
        cout << endl;
    }
}
