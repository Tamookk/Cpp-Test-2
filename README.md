# C++ Test 2

Learning C++ pls ignore: Part 2.

This program is all about learning generic programming in C++. It is simple, all it does it map codons to amino acids (this data is provided in one of the files passed as a command line argument), and print out active amino acid chains from the data found in the other file passed as a command line argument. See the example files for examples of files that are expected as input to the program.

This program loads the mapping between codons and amino acids, provided from the mapping text file, checks that this mapping covers all possible codons, and maps the codons to their associated amino acids.

The program then opens the data file and validates its character length, which must be a multiple of 3. The program gives a distribution of bases and lists the complete content of the data, with 60 bases per line.

Finally, the program will display all of the encoded active amino acid chains, starting on a 'Start' instruction and stopping on a 'Stop' instruction. The program reports how many amino acids are in each chain, excluding 'Start' and 'Stop', and reports how many amino acids were skipped.

## Getting Started

Dunno why you want to but okay.

### Prerequisites

* A compiler (C++ 11)
* Computer
* Eyes

### Installing

Only a few files - compiling should be easy. Use C++11 or newer though, due to the use of various C++11 features.

The program is run as follows:

`./Genetics [n] [mapping file] [data file]`

With `n` being the amount of bases in the alphabet for the given mapping/data files, `mapping file` being the .txt file containing the mapping information, and `data file` containing the data to be processed.

The program will quit if the amount of characters in the data file is not a multiple of 3, as all of the amino acids are encoded in sequences of 3 bases.

## Author

* Me

## Todo

* Pretty sure I'm done, so I dunno.

## Acknowledgments

* My compsci professor for teaching me C++ and setting this assignment.

## Changelog
### 16-10-2018
* Added checking the mapping of codons.

* Added the AlphabetFour class.

* Started coding the container class.

* Added finding the base distribution of the data file.

* Added printing the data from the data file.

* Added processing of the data file.

* Report when the end of the data file is reached without encountering a stop instruction.

* Update README file.

### 15-10-2018
* Make the program exit if the base is not one of the 3 (or 4) types it has to be.

### 11-10-2018
* Extract codons and amino acids from the file.

* Get the names of amino acids.

* Started work on the Container class.

* Add command line argument checking.

* Added the sample data files and started coding the classes.

* Project created, initial commit made.

* .gitignore and README.md files created.
