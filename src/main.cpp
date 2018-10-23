//
// Created by Joshua Sutton
// 11/10/2018
//

#include <cstdlib>
#include <iostream>

#include "../include/AlphabetThree.h"
#include "../include/AlphabetFour.h"
#include "../include/Container.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Check if the right amount of arguments have been entered
    if(argc != 4)
    {
        cerr << "Not enough arguments given." << endl;
        cerr << "./Genetics [n] [codon file] [data file]" << endl << endl;
        cerr << "[n] - A number, 3 or 4, to distinguish whether we are dealing with an AlphabetThree or AlphabetFour case" << endl;
        cerr << "[codon file] - Text file describing the mapping of codons to amino acids." << endl;
        cerr << "[data file] - Text file containing the data to operate on." << endl;
        return 1;
    }

    // Get the alphabet number
    int alphabetNum = atoi(argv[1]);
    // Check if the alphabet number is either 3 or 4
    if(alphabetNum != 3 && alphabetNum != 4)
    {
        cerr << "Incorrect Alphabet number given." << endl;
        cerr << alphabetNum << " was entered, should be 3 or 4." << endl;
        return 2;
    }

    // Grab the file names for the 2 required text files
    string codonFileName = string(argv[2]);
    string dataFileName = string(argv[3]);

    // Make an AlphabetThree or AlphabetFour class depending on the CL argument
    // and do the required processing on the codon mapping and data file.
    if(alphabetNum == 3)
    {
        Container<AlphabetThree> cont(codonFileName, dataFileName);
        cont.validateLengthOfData();
        cont.getSymbolDistribution();
        cont.listDataContents();
        cont.processCodons();
    }
    else if(alphabetNum == 4)
    {
        Container<AlphabetFour> cont(codonFileName ,dataFileName);
        cont.validateLengthOfData();
        cont.getSymbolDistribution();
        cont.listDataContents();
        cont.processCodons();
    }

    return 0;
}
