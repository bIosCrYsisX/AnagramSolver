///////////////////////////////////////////////////////////////////////
// Workfile: Main.cpp
// Author: Christoph Dalpiaz
// Date: 28.07.2020
// Description: test driver for AnagramSolver
// Remarks: -
// Revision: 0
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include "AnagramSolver.h"

using namespace std;

int main()
{
	try {
		string const WordsFile = "german.dic";  //file from which words become scanned
		AnagramSolver solver{ WordsFile };

		string word = "";

		while (word != "exit") {
			cout << "Type in german word: ";
			cin >> word;
			if (word != "exit") {
				solver.Solve(word);
			}
		}
	}
	catch (bad_alloc const& ex) {
		cerr << ex.what() << endl;
		return 1;
	}
	catch (std::exception const& ex) {
		cerr << ex.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "Unhandled exception!" << endl;
		return 1;
	}
	return 0;
}