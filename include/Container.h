//
// Created by Joshua Sutton
// 11/10/2018
//

#ifndef CONTAINER_H
#define CONTAINER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
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

public:
    Container(int _numBases, string _dateFileName);
    void validateLengthOfData();
    void getSymbolDistribution();
    void listDataContents();
    void processCodons();
};


#endif
