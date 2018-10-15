//
// Created by Joshua Sutton
// 11/10/2018
//

#ifndef CONTAINER_H
#define CONTAINER_H

// "This class is for storing an ordered list of objects associated with the nucleotides."
// What type are the objects? What does this mean?
// > Store an ordered list - vector, map, etc.
// > The list is of a type "object". This "object" is associated with the nucleotides.
//   - i.e., AlphabetThree and AlphabetFour
// > So, typename<T> is replaced by AlphabetThree or AlphabetFour

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

template <typename T>

class Container
{
public:
    Container();
};


#endif
