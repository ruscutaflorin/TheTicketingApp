#pragma once
#include <iostream>
#include <string>
using namespace std;
class buildingStructure
{
	friend class Location;

private:
	int** zoneStructure;
	int nrRows;
	int nrColumns;

public:

	buildingStructure();

	buildingStructure(const int** zoneStructure, const int nrRows, const int nrColumns) :buildingStructure() {};

	buildingStructure(const buildingStructure& object);

	buildingStructure& operator=(const buildingStructure& object);

	~buildingStructure();

	/// TODO dezaloc in main
	int** getZoneStructure();

	int getNrRows();

	int getNrColumns();

	void setEmptyZone(const int nrColumns, const int nrRows);

	void setZoneStructure(const int** zoneStructure, const int nrColumns, const int nrRows);

	int availableCapacity();

	string generateSeatID(const int zoneNumber, const int row, const int column);

	friend ostream& operator<<(ostream& out, buildingStructure obj);
	friend istream& operator>>(istream& in, buildingStructure& obj);

};

ostream& operator<<(ostream& out, buildingStructure obj);

istream& operator>>(istream& in, buildingStructure& obj);

