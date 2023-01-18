#pragma once

#ifndef BUILDINGSTRUCTURE_H
#define BUILDINGSTRUCTURE_H

#include <iostream>
#include <vector>

using namespace std;
class buildingStructure
{
	friend class Location;
	friend class Event;

private:
	vector<vector<int>> zoneStructure;
	int nrRows;
	int nrColumns;

public:

	buildingStructure();

	buildingStructure(const vector<vector<int>>, const int, const int);

	buildingStructure(const buildingStructure&);

	buildingStructure& operator=(const buildingStructure&);

	~buildingStructure();

	/// TODO dezaloc in main
	vector<vector<int>> getZoneStructure();

	int getNrRows();

	int getNrColumns();

	void setEmptyZone(const int, const int);

	void setZoneStructure(const vector<vector<int>>, const int, const int);

	int availableCapacity();

	string generateSeatID(const int, const int, const int);

	friend ostream& operator<<(ostream& out, buildingStructure obj);
	friend istream& operator>>(istream& in, buildingStructure& obj);

};

ostream& operator<<(ostream& out, buildingStructure obj);

istream& operator>>(istream& in, buildingStructure& obj);

#endif