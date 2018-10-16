//
// Created by Joshua Sutton
// 11/10/2018
//

#include "../include/Container.h"

// The objects the container stores are either A3 or A4
// Check overall length of datafile - number of characters.
// Stop if not a factor of 3 or 4
// Stop if a character is wrong
// Distribution of symbols - a count of how many of each letter there are
// Print out the whole sequence
// Display all of the encoded active amino acid chains

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
    
}

// Get the distribution of symbols in the data file
template <typename T>
void Container<T>::getSymbolDistribution()
{

}

// List the contents of the data file
template <typename T>
void Container<T>::listDataContents()
{

}

// Process the codons within the data file
template <typename T>
void Container<T>::processCodons()
{

}
