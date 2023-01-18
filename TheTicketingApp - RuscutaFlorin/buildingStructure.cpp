#include "buildingStructure.h"
#include <string>
#include <algorithm>

buildingStructure::buildingStructure() {
	nrRows = 0;
	nrColumns = 0;
}

buildingStructure::buildingStructure(const vector<vector<int>> zoneStructure, const int nrRows, const int nrColumns) {
	if (nrRows > 0 && nrColumns > 0 && !zoneStructure.empty() && !zoneStructure[0].empty()) {
		this->zoneStructure.resize(nrRows);
		for (int i = 0; i < nrRows; i++) {
			this->zoneStructure[i].resize(nrColumns);
			for (int j = 0; j < nrColumns; j++) {
				this->zoneStructure[i][j] = zoneStructure[i][j];
			}
		}
		this->nrRows = zoneStructure.size();
		this->nrColumns = zoneStructure[0].size();
	}
	else {
		this->nrRows = 0;
		this->nrColumns = 0;
	}
}



buildingStructure::buildingStructure(const buildingStructure& object) {
	if (object.nrRows > 0 && object.nrColumns > 0) {
		this->zoneStructure.resize(object.nrRows);
		for (int i = 0; i < object.nrRows; i++) {
			this->zoneStructure[i].resize(object.nrColumns);
			for (int j = 0; j < object.nrColumns; j++) {
				this->zoneStructure[i][j] = object.zoneStructure[i][j];
			}
		}
		this->nrRows = object.nrRows;
		this->nrColumns = object.nrColumns;
	}
	else {
		nrRows = 0;
		nrColumns = 0;
	}
}


buildingStructure& buildingStructure::operator=(const buildingStructure& object) {
	if (this != &object) {
		if (object.nrRows > 0 && object.nrColumns > 0) {
			this->zoneStructure.resize(object.nrRows);
			for (int i = 0; i < object.nrRows; i++) {
				this->zoneStructure[i].resize(object.nrColumns);
				for (int j = 0; j < object.nrColumns; j++) {
					this->zoneStructure[i][j] = object.zoneStructure[i][j];
				}
			}
			this->nrRows = object.nrRows;
			this->nrColumns = object.nrColumns;
		}
		else {
			this->nrRows = 0;
			this->nrColumns = 0;
		}
	}
	return *this;
}

buildingStructure::~buildingStructure() {
	nrRows = 0;
	nrColumns = 0;
}

vector<vector<int>> buildingStructure::getZoneStructure() {
	if (nrRows > 0 && nrColumns > 0) {
		vector<vector<int>> copy;
		copy = zoneStructure;
		return copy;
	}
	else {
		return vector<vector<int>>();
	}
}

int buildingStructure::getNrRows() {
	return nrRows;
}

int buildingStructure::getNrColumns() {
	return nrColumns;
}

void buildingStructure::setEmptyZone(const int nrRows, const int nrColumns) {
	if (nrRows > 0 && nrColumns > 0) {
		this->nrRows = nrRows;
		this->nrColumns = nrColumns;
		this->zoneStructure.resize(nrRows, vector<int>(nrColumns, 0));
	}
}

void buildingStructure::setZoneStructure(const vector<vector<int>> zoneStructure, const int nrRows, const int nrColumns) {
	if (nrRows > 0 && nrColumns > 0 && zoneStructure.size() == nrRows && zoneStructure[0].size() == nrColumns) {
		this->nrRows = nrRows;
		this->nrColumns = nrColumns;
		this->zoneStructure = zoneStructure;
	}
}

int buildingStructure::availableCapacity() {
	return nrRows * nrColumns;
}

string buildingStructure::generateSeatID(const int zoneNumber, const int row, const int column) {
	if (zoneNumber < 1 || row < 0 || column < 0 || row >= nrRows || column >= nrColumns)
		return "Invalid seat coordinates\n";
	string x = to_string(zoneNumber) + to_string(row) + to_string(column);
	return x;
}


ostream& operator<<(ostream& out, buildingStructure obj)
{
	out << "Total available capacity is: " << obj.availableCapacity() << endl;

	if (obj.nrRows > 0 && obj.nrColumns > 0) {
		out << endl << 0 << "  ";
		for (int i = 1; i <= obj.nrColumns; ++i) {
			out << i << " ";
		}
		out << endl << endl;
		for (int i = 0; i < obj.nrRows; ++i) {
			for (int j = 0; j < obj.nrColumns; ++j) {
				if (j == 0) {
					out << i + 1 << "  ";
				}
				out << obj.zoneStructure[i][j] << " ";
			}
			out << endl;
		}
		out << endl;
	}
	else {
		out << "There is nothing into the object!" << endl;
	}

	return out;
}

istream& operator>>(istream& in, buildingStructure& obj)
{
	int rows, columns;
	cout << "\nRows Number: ";
	in >> rows;
	cout << "Columns Number: ";
	in >> columns;
	obj.setEmptyZone(rows, columns);

	return in;
}