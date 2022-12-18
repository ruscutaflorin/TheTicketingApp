#pragma once

#include <iostream>
#include <cstring>
#include "Event.h"
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

	Location() :city("Unspecified") {};
	Location(const string city, const string address, const string* zones, const int nrZones, buildingStructure* object);

	Location(const Location& object);

	Location& operator=(const Location& object);

	~Location();

	string getCity();

	string getAddress();

	int getNrZones();

	int getMaxCapacity();

	string* getZones();

	void setCity(const string input);

	void setAddress(const string input);

	void setZones(const string* input, const int nr);

	static int locationCapacity(buildingStructure* object, int objectNumber);

	int** maxSeatsNextToEachotherForEachSector(buildingStructure* object, int objectNumber);

	Location operator--();

	Location operator--(int i);

	operator string* ();

	friend ostream& operator<<(ostream& out, Location obj);
	friend istream& operator>>(istream& in, Location& obj);

};

ostream& operator<<(ostream& out, Location obj);

istream& operator>>(istream& in, Location& obj);