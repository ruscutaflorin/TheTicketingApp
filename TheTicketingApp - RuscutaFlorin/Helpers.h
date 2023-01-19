#pragma once
#include <iostream>
#include <string>

#ifndef HELPERS_H
#define HELPERS_H

using namespace std;

class Helpers
{
	friend class Location;

public:

	string readString();

	string readString(string);

	string readStringWithOnlyLetters();

	string readStringWithOnlyDigits();

	string readStringWithOnlyDigits(string);

	string readStringWithOnlyLettersUntilTrue();

	bool dateIsValid(int day, int month, int year);


};

#endif