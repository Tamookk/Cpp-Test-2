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
// Class needs to:
// > Report on and validate the length of the content
//   - Must be a multiple of 3
// > Report on the symbol distribution for the container
//   - Whatever that means
// > List the complete content of the container.
//   - 60 elements per line, like the sample files
// > Display all the encoded active amino acid chains
//   - Read and process codons from the data sequence (3 symbols at a time)
//   - When we reach a start instruction:
//     1. Output the amino acids using their their names separated by dashes
//     2. Keep going until a stop instruction is reached
//     3. The number of amino acids in each chain should be reported
//   - If the end of the data is reached without a stop instruction, this should be reported
//   - Report the number of codons NOT displayed between start and stop instructions, and at the beginning + end as appropriate

using namespace std;

template <typename T>

class Container
{
private:
    T alphabet;
    int numBases;
    string dataFileName;
    string data;
    map<char, int> baseDistribution;

public:
    Container(int _numBases, string _dateFileName);
    void validateLengthOfData();
    void getSymbolDistribution();
    void listDataContents();
    void processCodons();
};


// -- Function definitions are required in the header file, otherwise the program will not compile -- //
// Constructor
template <typename T>
Container<T>::Container(int _numBases, string _dataFileName)
{
    alphabet = T();
    numBases = _numBases;
    dataFileName = _dataFileName;
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
    if(data.length() % numBases != 0)
    {
        cerr << "Data file has incorrect amount of characters. Amount must be a multiple of " << numBases << "." << endl;
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

}

#endif
