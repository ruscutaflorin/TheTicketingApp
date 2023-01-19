#define _CRT_SECURE_NO_WARNINGS
#include "Helpers.h"
#include <ctime>
string Helpers::readString() {
	string input;
	getline(cin, input);
	return input;
}

string Helpers::readString(string input) {
	getline(cin, input);
	return input;
}

string Helpers::readStringWithOnlyLetters() {
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

string Helpers::readStringWithOnlyDigits() {
	char c;
	string input;

	input = readString();

	for (int i = 0; i < input.length(); ++i) {
		c = input.at(i);
		if (!isdigit(c))
			return "Only digits accepted";
	}

	return input;
}
string Helpers::readStringWithOnlyDigits(string input) {
	char c;
	for (int i = 0; i < input.length(); ++i) {
		c = input.at(i);
		if (!isdigit(c))
			return "Only digits accepted";
	}
	return input;
}

string Helpers::readStringWithOnlyLettersUntilTrue() {
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

bool Helpers::dateIsValid(int day, int month, int year) {

	time_t t = std::time(nullptr);
	tm tm = *std::localtime(&t);
	if (year < 2023 || year >(tm.tm_year + 1900)) {
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
