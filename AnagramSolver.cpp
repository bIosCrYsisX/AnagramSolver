///////////////////////////////////////////////////////////////////////
// Workfile: AnagramSolver.cpp
// Author: Christoph Dalpiaz
// Date: 28.07.2020
// Description: solver for anagrams
// Remarks: -
// Revision: 0
///////////////////////////////////////////////////////////////////////

#include <iostream>			//include IO library
#include <fstream>			//include filestream library
#include "AnagramSolver.h"	//include module header

using namespace std;	//resolve std namespace

//constructor with filename from which becomes scanned
AnagramSolver::AnagramSolver(std::string const& fileName) : mFileName{ fileName } {}

//finds words for the anagram and prints them to cout
void AnagramSolver::Solve(std::string const& anagram) {
	if (!mWords.empty() && mWords.cbegin()->size() != anagram.size() || mWords.empty()) {  //only scan words if the length is different or empty
		mWords.clear();			
		cout << ScanText << endl;
		ScanWords(anagram);
	}
	cout << NoCandidatesText << distance(mWords.cbegin(), mWords.cend()) << endl;	//print number of words with correct length

	LetterCounts lcAnagram = CountLetters(anagram);  //count encounters of letters of anagram

	//print all words with same number of encounters of letters
	copy_if(mWords.cbegin(), mWords.cend(), ostream_iterator<string>{cout, "\n"}, [&](string const& str) { return lcAnagram == CountLetters(str); });
}

//scan words with equal length to mWords
void AnagramSolver::ScanWords(string const& anagram) {
	ifstream inFile{ mFileName };  //define input filestream

	if (!inFile.is_open()) {  //check if opening file worked
		return;
	}

	//save all words with equal number of letters
	copy_if(istream_iterator<string>{inFile}, istream_iterator<string>{}, front_inserter(mWords), [&](string const& str) { return str.size() == anagram.size(); });

	inFile.close();
}

//count number of encounters of all letters and return them
LetterCounts AnagramSolver::CountLetters(std::string const& word) const {
	LetterCounts lc = { 0 };

	for_each(word.cbegin(), word.cend(), [&](char const c) { if (c >= 'A' && c <= 'Z') { lc[c - 'A']++; }  //increment correct counter
															 else if (c >= 'a' && c <= 'z') { lc[c - 'a']++; } } );
	return lc;  //return counter array
}