#pragma once

//#include <iostream>
#include <cstring>
#include "buildingStructure.h"

using namespace std;

class Location
{

	friend class Event;

private:
	string city;
	string address;
	string* zones;
	int nrZones;
	int maxCapacity;
	buildingStructure* obj;

public:

	Location();

	Location(const string, const string, const string*, const int, buildingStructure*);

	Location(const Location&);

	Location& operator=(const Location&);

	~Location();

	string getCity();

	string getAddress();

	int getNrZones();

	int getMaxCapacity();

	string* getZones();

	void setCity(const string);

	void setAddress(const string);

	void setZones(const string*, const int);

	static int locationCapacity(buildingStructure*, int);

	int** maxSeatsNextToEachotherForEachSector(buildingStructure* object, int);

	Location operator--();

	Location operator--(int i);

	operator string* ();

	friend ostream& operator<<(ostream& out, Location obj);
	friend istream& operator>>(istream& in, Location& obj);

};

ostream& operator<<(ostream& out, Location obj);

istream& operator>>(istream& in, Location& obj);