//
// Created by Joshua Sutton
// 11/10/2018
//


// Alphabets are fixed! ACTG for A4, ABC for A3
// The objects the container stores are either A3 or A4
// Check overall length of datafile - number of characters.
    // Stop if not a factor of 3 or 4
    // Stop if a character is wrong
// Distribution of symbols - a count of how many of each letter there are
// Print out the whole sequence
// Display all of the encoded active amino acid chains

#include "../include/AlphabetThree.h"

// Constructor
AlphabetThree::AlphabetThree()
{
    // Insert the possible codons into a vector
    string listOfCodons[] = {"AAA", "AAB", "AAC", "ABA", "ABB", "ABC", "ACA", "ACB", "ACC", "BAA", "BAB", "BAC",
                             "BBA", "BBB", "BBC", "BCA", "BCB", "BCC", "CAA", "CAB", "CAC", "CBA", "CBB", "CBC",
                             "CCA", "CCB", "CCC"};
    for(int i = 0; i < 27; i++)
        possibleCodons.insert(possibleCodons.end(), listOfCodons[i]);
}

// Destructor
AlphabetThree::~AlphabetThree() {}

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
    for(auto item : mappedCodons)
    {
        if((find(possibleCodons.begin(), possibleCodons.end(), item.second)) != possibleCodons.end())
        {
            possibleCodons.erase(find(possibleCodons.begin(), possibleCodons.end(), item.second));
        }
    }

    if(possibleCodons.size() != 0)
    {
        cerr << "Not all possible codons provided in mapping file. Exiting program." << endl;
        exit(5);
    }
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

        string lineCopy = line;

        // Check if a character is not one of the three bases
        for(int i = 0; i < line.length(); i++)
        {
            if(lineCopy.substr(i, i+1).find_first_of("DEFGHIJKLMNOPQRSTUVWXY") != string::npos)
            {
                cerr << "Non-standard base found. Exiting program." << endl;
                exit(4);
            }
        }

        // Cut out whitespace/search for a base
        line = line.substr(line.find_first_of("ABC"), line.length());

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

        // Add the codons to the multimap
        pos = 0;
        for(int i = 0; i < numCodons; i++)
        {
            if (line.find(',', pos) == string::npos) {
                mappedCodons.insert(pair<string, string>(name, line));
                break;
            }

            // Put the codon into the multimap
            mappedCodons.insert(pair<string, string>(name, line.substr(pos, line.find(','))));

            // Trim out the codon and anything that isn't a base
            pos = line.find(',') + 1;
            line = line.substr(pos, line.length());
            line = line.substr(line.find_first_of("ABC"), line.length());
            pos = 0;
        }
    }
}

// List the amino acids and their codons
void AlphabetThree::listAminoAcids()
{
    for(auto i = mappedCodons.begin(); i != mappedCodons.end(); i++)
    {
        cout << "Amino Acid: " << i->first << endl;
        cout << "Codon: " << i->second << endl;
        cout << endl;
    }
}
