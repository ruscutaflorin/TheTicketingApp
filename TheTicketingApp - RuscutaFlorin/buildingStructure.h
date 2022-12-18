#pragma once
#include <string>
class buildingStructure
{
	friend class Location;

private:
	int** zoneStructure;
	int nrRows;
	int nrColumns;

public:

	buildingStructure() {
		zoneStructure = nullptr;
		nrRows = 0;
		nrColumns = 0;
	}

	buildingStructure(const int** zoneStructure, const int nrRows, const int nrColumns) :buildingStructure() {
		if (nrRows > 0 && nrColumns > 0 && zoneStructure != nullptr) {
			this->zoneStructure = new int* [nrRows];
			for (int j = 0; j < nrRows; ++j) {
				this->zoneStructure[j] = new int[nrColumns];
			}
			this->nrRows = nrRows;
			this->nrColumns = nrColumns;
		}
	}

	buildingStructure(const buildingStructure& object) {
		if (object.nrRows > 0 && object.nrColumns > 0 && object.zoneStructure != nullptr) {
			zoneStructure = new int* [object.nrRows];
			for (int i = 0; i < object.nrRows; ++i) {
				zoneStructure[i] = new int[object.nrColumns];
			}

			for (int i = 0; i < object.nrRows; ++i) {
				for (int j = 0; j < object.nrColumns; ++j) {
					zoneStructure[i][j] = object.zoneStructure[i][j];
				}
			}
			nrRows = object.nrRows;
			nrColumns = object.nrColumns;
		}
		else {
			nrRows = 0;
			nrColumns = 0;
			zoneStructure = nullptr;
		}
	}
	buildingStructure& operator=(const buildingStructure& object) {
		if (this != &object) {
			if (object.nrColumns > 0 && object.nrRows > 0 && object.zoneStructure != nullptr) {
				if (zoneStructure != nullptr) {
					for (int i = 0; i < nrRows; ++i) {
						delete[] zoneStructure[i];
					}
					delete[] zoneStructure;
					nrRows = 0;
					nrColumns = 0;
				}

				zoneStructure = new int* [object.nrRows];
				for (int i = 0; i < object.nrRows; ++i) {
					zoneStructure[i] = new int[object.nrColumns];
				}

				for (int i = 0; i < object.nrRows; ++i) {
					for (int j = 0; j < object.nrColumns; ++j) {
						zoneStructure[i][j] = object.zoneStructure[i][j];
					}
				}
				nrRows = object.nrRows;
				nrColumns = object.nrColumns;

			}
			else {
				nrRows = 0;
				nrColumns = 0;
				zoneStructure = nullptr;
			}
		}
		return *this;
	}


	~buildingStructure() {
		if (zoneStructure != nullptr) {
			for (int i = 0; i < nrRows; ++i) {
				delete[] zoneStructure[i];
			}
			delete[] zoneStructure;
			nrRows = 0;
			nrColumns = 0;
		}
		nrRows = 0;
		nrColumns = 0;
	}


	/// TODO dezaloc in main	/// </summary>
	int** getZoneStructure() {
		if (zoneStructure != nullptr && nrRows > 0 && nrColumns > 0) {
			int** copy;
			copy = new int* [nrRows];
			for (int i = 0; i < nrRows; ++i) {
				copy[i] = new int[nrColumns];
			}

			for (int i = 0; i < nrRows; ++i) {
				for (int j = 0; j < nrColumns; ++j) {
					copy[i][j] = zoneStructure[i][j];
				}
			}
			return copy;
		}
		else {
			return 0;
		}
	}

	int getNrRows() {
		return nrRows;
	}

	int getNrColumns() {
		return nrColumns;
	}

	void setEmptyZone(const int nrColumns, const int nrRows) {
		if (nrColumns > 0 && nrRows > 0) {
			if (this->zoneStructure != nullptr) {
				for (int i = 0; i < this->nrRows; ++i) {
					delete[] this->zoneStructure[i];
				}
				delete[] this->zoneStructure;
				this->nrRows = 0;
				this->nrColumns = 0;
			}

			this->zoneStructure = new int* [nrRows];
			for (int i = 0; i < nrRows; ++i) {
				this->zoneStructure[i] = new int[nrColumns];
			}

			for (int i = 0; i < nrRows; ++i) {
				for (int j = 0; j < nrColumns; ++j) {
					this->zoneStructure[i][j] = 0;
				}
			}
			this->nrRows = nrRows;
			this->nrColumns = nrColumns;

		}
	}

	void setZoneStructure(const int** zoneStructure, const int nrColumns, const int nrRows) {
		if (nrColumns > 0 && nrRows > 0 && zoneStructure != nullptr) {
			if (this->zoneStructure != nullptr) {
				for (int i = 0; i < this->nrRows; ++i) {
					delete[] this->zoneStructure[i];
				}
				delete[] this->zoneStructure;
				this->nrRows = 0;
				this->nrColumns = 0;
			}

			this->zoneStructure = new int* [nrRows];
			for (int i = 0; i < nrRows; ++i) {
				this->zoneStructure[i] = new int[nrColumns];
			}

			for (int i = 0; i < nrRows; ++i) {
				for (int j = 0; j < nrColumns; ++j) {
					this->zoneStructure[i][j] = zoneStructure[i][j];
				}
			}
			this->nrRows = nrRows;
			this->nrColumns = nrColumns;

		}
	}

	int availableCapacity() {
		return nrRows * nrColumns;
	}

	string generateSeatID(const int zoneNumber, const int row, const int column) {
		string x = to_string(zoneNumber) + to_string(row) + to_string(column);
		return x;
	}

	friend ostream& operator<<(ostream& out, buildingStructure obj);
	friend istream& operator>>(istream& in, buildingStructure& obj);

};

ostream& operator<<(ostream& out, buildingStructure obj)
{
	if (obj.zoneStructure != nullptr && obj.nrRows > 0 && obj.nrColumns > 0) {
		out << 0 << " ";
		for (int i = 1; i <= obj.nrColumns; ++i) {
			out << i << " ";
		}
		out << endl;
		for (int i = 0; i < obj.nrRows; ++i) {
			for (int j = 0; j < obj.nrColumns; ++j) {
				if (j == 0) {
					out << j + 1 << " ";
				}
				out << obj.zoneStructure[i][j] << " ";
			}
			out << endl;
		}
		out << "Total available capacity is: " << obj.availableCapacity();
	}
	else {
		out << "There is nothing into the object!";
	}

	return out;
}

istream& operator>>(istream& in, buildingStructure& obj)
{
	int rows, columns;
	int** structure;
	cout << "Rows Number: ";
	in >> rows;
	cout << endl << "Columns Number: ";
	in >> columns;
	obj.setEmptyZone(rows, columns);

	return in;
}
