#pragma once
#include <iostream>
#include <string>
using namespace std;

class Helpers
{
public:
	string readString() {
		string input;
		getline(cin, input);
		return input;
	}

	string readStringWithOnlyLetters() {
		char c;
		string input;

		input = readString();

		for (int i = 0; i < input.length(); ++i) {
			c = input.at(i);
			if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
				throw invalid_argument("Only letters accepted");
		}

		return input;
	}

	// de verificat ca probabil sigur n o sa mearga
	// throw exception inlocuieste un return deci nu prea i pont
	string readStringWithOnlyLettersUntilTrue() {
		unsigned int cnt = 0;
		string input;
		while (cnt < 5) {
			++cnt;
			try {
				return input = readStringWithOnlyLetters();
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl;
			}
		}
		return 0;
	}
};

