//
// Created by Joshua Sutton
// 11/10/2018
//

#include "../include/AlphabetFour.h"

// Constructor
AlphabetFour::AlphabetFour()
{
    // Insert the possible codons into a vector
    string listOfCodons[] = {"AAA", "AAC", "AAG", "AAT", "ACA", "ACC", "ACG", "ACT", "AGA", "AGC", "AGG", "AGT", "ATA",
                             "ATC", "ATG", "ATT", "CAA", "CAC", "CAG", "CAT", "CCA", "CCC", "CCG", "CCT", "CGA", "CGC",
                             "CGG", "CGT", "CTA", "CTC", "CTG", "CTT", "GAA", "GAC", "GAG", "GAT", "GCA", "GCC", "GCG",
                             "GCT", "GGA", "GGC", "GGG", "GGT", "GTA", "GTC", "GTG", "GTT", "TAA", "TAC", "TAG", "TAT",
                             "TCA", "TCC", "TCG", "TCT", "TGA", "TGC", "TGG", "TGT", "TTA", "TTC", "TTG", "TTT"};
    for(int i = 0; i < 64; i++)
        possibleCodons.insert(possibleCodons.end(), listOfCodons[i]);
}

// Destructor
AlphabetFour::~AlphabetFour() {}

// Set the base for the object
void AlphabetFour::setBase(char _base)
{
    base = _base;
    if(base != 'A' && base != 'C' && base != 'G' && base != 'T')
    {
        cerr << "Non-standard base found. Exiting program." << endl;
        exit(4);
    }
}

// Get the base for the object
char AlphabetFour::getBase()
{
    return base;
}

// Load the mapping data
void AlphabetFour::loadMapping(string fileName)
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
void AlphabetFour::checkMapping()
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
multimap<string, string> AlphabetFour::mapCodons()
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
            if(lineCopy.substr(i, i+1).find_first_of("BDEFHIJKLMNOPQRSUVWXY") != string::npos)
            {
                cerr << "Non-standard base found. Exiting program." << endl;
                exit(4);
            }
        }

        // Cut out whitespace/search for a base
        line = line.substr(line.find_first_of("ACGT"), line.length());

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
            line = line.substr(line.find_first_of("ACGT"), line.length());
            pos = 0;
        }
    }

    checkMapping();

    return mappedCodons;
}

// List the amino acids and their codons
void AlphabetFour::listAminoAcids()
{
    for(auto i = mappedCodons.begin(); i != mappedCodons.end(); i++)
    {
        cout << "Amino Acid: " << i->first << endl;
        cout << "Codon: " << i->second << endl;
        cout << endl;
    }
}
