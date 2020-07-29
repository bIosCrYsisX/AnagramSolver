///////////////////////////////////////////////////////////////////////
// Workfile: AnagramSolver.h
// Author: Christoph Dalpiaz
// Date: 28.07.2020
// Description: solver for anagrams
// Remarks: -
// Revision: 0
///////////////////////////////////////////////////////////////////////

#ifndef ANAGRAMSOLVER_H
#define ANAGRAMSOLVER_H

#include <string>		//include std::string
#include <forward_list>	//include std::forward_list
#include <array>		//include std::array

size_t const NoLetters = 26;		//number of letters in alphabet
std::string const NoCandidatesText = "Number of candidates: ";
std::string const ScanText = "Scanning Words...";

typedef std::forward_list<std::string> Words;				//type for saving scanned words
typedef std::array<unsigned char, NoLetters> LetterCounts;	//type for counting number of encounters of letter

class AnagramSolver {
private:
	Words mWords;
	std::string mFileName;

	//scan words with equal length to mWords
	void ScanWords(std::string const& anagram);

	//count number of encounters of all letters and return them
	LetterCounts CountLetters(std::string const& word) const;
public:
	//constructor with filename from which becomes scanned
	explicit AnagramSolver(std::string const& fileName);

	//finds words for the anagram and prints them to cout
	void Solve(std::string const& anagram);
};

#endif