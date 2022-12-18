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
				return "Only letters accepted";
		}

		return input;
	}

	string readStringWithOnlyLettersUntilTrue() {
		unsigned int cnt = 0;
		string input;
		while (cnt < 5) {
			++cnt;
			input = readStringWithOnlyLetters();
			if (input != "Only letters accepted")
				return input;

		}
		return "Contains Numbers";
	}

	bool dateIsValid(int day, int month, int year) {
		if (year < 0) {
			return false;
		}
		if (month > 12 || month < 1) {
			return false;
		}
		if (day > 31 || day < 1) {
			return false;
		}
		if ((day == 31 &&
			(month == 2 || month == 4 || month == 6 || month == 9 || month == 11))) {

			return false;
		}
		if (day == 30 && month == 2) {
			return false;
		}
		return true;
	}


};

