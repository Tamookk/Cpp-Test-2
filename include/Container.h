//
// Created by Joshua Sutton
// 11/10/2018
//

#ifndef CONTAINER_H
#define CONTAINER_H

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

// TODO: If the end of the data is reached without a stop instruction, this should be reported

using namespace std;

template <class T>
class Container
{
private:
    vector<T> bases;
    string mapFileName;
    string dataFileName;
    string data;
    map<char, int> baseDistribution;
    multimap<string, string> mappedCodons;

public:
    Container(string _mapFileName, string _dataFileName);
    T generateAlphabet(char base);
    void validateLengthOfData();
    void getSymbolDistribution();
    void listDataContents();
    void processCodons();
};


// -- Function definitions are required in the header file, otherwise the program will not compile -- //
// Constructor
template <typename T>
Container<T>::Container(string _mapFileName, string _dataFileName)
{
    mapFileName = _mapFileName;
    dataFileName = _dataFileName;
}

// Generate an AlphabetFour or AlphabetThree class
template <typename T>
T Container<T>::generateAlphabet(char base)
{
    T alphabet = T();
    alphabet.setBase(base);
    return alphabet;
}

// Validate the length of the data in the data file
template <typename T>
void Container<T>::validateLengthOfData()
{
    char ch;

    // Open the map file
    ifstream dataFile(dataFileName);

    // Check if the file could be opened
    if(dataFile.fail())
    {
        cerr << "Error opening file \"" << dataFileName << "\"." << endl;
        dataFile.close();
        exit(3);
    }

    // Grab each character from the map file
    while(dataFile >> noskipws >> ch)
    {
        if(ch == '\n')
        {
            continue;
        }
        else
        {
            data += ch;
        }
    }

    // Check if the data file has a correct amount of characters
    if(data.length() % 3 != 0)
    {
        cerr << "Data file has incorrect amount of characters. Amount must be a multiple of 3." << endl;
        dataFile.close();
        exit(5);
    }

    // Close the data file
    dataFile.close();
}

// Get the distribution of symbols in the data file
template <typename T>
void Container<T>::getSymbolDistribution()
{
    bool codonsMapped = false;

    // Loop through each character in the data
    for(char &c : data)
    {
        // Check if the base is already in the map
        map<char, int>::iterator it = baseDistribution.find(c);
        if(it != baseDistribution.end())
        {
            // Add one to the count
            it->second = it->second + 1;
        }
        else
        {
            // Otherwise insert the base into the map
            baseDistribution.insert(pair<char, int>(c, 1));
        }

        bases.push_back(generateAlphabet(c));

        // Add an object for the base to the base list
        if(!codonsMapped)
        {
            codonsMapped = true;
            bases[0].loadMapping(mapFileName);
            mappedCodons = bases[0].mapCodons();
        }

    }

    // Print out the base distribution
    cout << "==Base Distribution==" << endl;
    for(auto c : baseDistribution)
    {
        cout << c.first << ": " << c.second << endl;
    }
    cout << endl;
}

// List the contents of the data file
template <typename T>
void Container<T>::listDataContents()
{
    int charNum = 0;

    cout << "==Data of File==" << endl;

    // Print out each character of the data, 60 characters per line
    for(char &c : data)
    {
        if(charNum > 59)
        {
            cout << endl;
            charNum = 0;
        }
        cout << c;
        charNum++;
    }
    cout << endl << endl;
}

// Process the codons within the data file
template <typename T>
void Container<T>::processCodons()
{
    int charNum = 0;
    int sequenceNum = 1;
    string aminoAcid;
    int skippedCodons = 0;
    int codonsProcessed = 0;
    bool hasStarted = false;

    string codon;

    cout << endl << "==Codon Processing==" << endl;

    // Search for a start codon
    for(auto base : bases)
    {
        // Match the codon against the mapped ones
        if(charNum >= 3)
        {
            for(auto it = mappedCodons.begin(); it != mappedCodons.end(); it++)
            {
                if(it->second == codon)
                {
                    if(!hasStarted && it->first == "Start")
                    {
                        hasStarted = true;
                        cout << skippedCodons << " codons skipped." << endl;
                        skippedCodons = 0;
                        cout << endl << "=Sequence " << sequenceNum << "=" << endl;
                        cout << it->first;
                    }
                    else if(hasStarted && it->first == "Stop")
                    {
                        hasStarted = false;
                        cout << "-Stop" << endl;
                        cout << "Contains " << codonsProcessed  << " amino acids." << endl << endl;
                        codonsProcessed = 0;
                        sequenceNum++;
                    }
                    else if(hasStarted)
                    {
                        cout << "-" << it->first;
                        if(it->first != "Start")
                            codonsProcessed++;
                    }
                    else
                    {
                        skippedCodons++;
                    }
                    break;
                }
            }
            charNum = 0;
            codon = "";
        }

        // Add the char to the codon string
        codon += base.getBase();
        charNum++;
    }

    if(hasStarted)
    {
        cout << "End of data reached without encountering a \"Stop\" instruction" << endl;
    }

    if(skippedCodons > 0)
    {
        cout << skippedCodons + 1 << " codons skipped." << endl << endl;
    }
    cout << "End of data." << endl;
}

#endif
