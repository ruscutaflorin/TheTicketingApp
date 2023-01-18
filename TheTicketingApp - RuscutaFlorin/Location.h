#pragma once

#include <cstring>
#include "buildingStructure.h"


class Location
{
	friend class Event;

private:
	string city;
	string address;
	string* zones;
	int nrZones;
	static int maxCapacity;
	vector<buildingStructure> obj;

public:

	Location();

	Location(const string, const string, const string*, const int, const vector<buildingStructure>);

	Location(const Location&);

	Location& operator=(const Location&);

	~Location();

	string getCity();

	string getAddress();

	int getNrZones();

	static int getMaxCapacity();

	string* getZones();

	void setCity(const string);

	void setAddress(const string);

	void setZones(const string*, const int);

	static int freeCapacity(const vector<buildingStructure>);

	static int returnMaxCapacity(const vector<buildingStructure>);

	Location operator--();

	Location operator--(int i);

	operator string* ();

	friend ostream& operator<<(ostream& out, Location obj);
	friend istream& operator>>(istream& in, Location& obj);

};

ostream& operator<<(ostream& out, Location obj);

istream& operator>>(istream& in, Location& obj);
