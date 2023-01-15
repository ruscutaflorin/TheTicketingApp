#include "buildingStructure.h"
#include <string>

buildingStructure::buildingStructure() {
	zoneStructure = nullptr;
	nrRows = 0;
	nrColumns = 0;
}

buildingStructure::buildingStructure(const int** zoneStructure, const int nrRows, const int nrColumns) {
	if (nrRows > 0 && nrColumns > 0 && zoneStructure != nullptr) {
		this->zoneStructure = new int* [nrRows];
		for (int j = 0; j < nrRows; ++j) {
			this->zoneStructure[j] = new int[nrColumns];
		}
		this->nrRows = nrRows;
		this->nrColumns = nrColumns;
	}
	else {
		this->zoneStructure = nullptr;
		this->nrRows = 0;
		this->nrColumns = 0;
	}
}

//buildingStructure::buildingStructure(const buildingStructure& object) {
//	if (object.nrRows > 0 && object.nrColumns > 0 && object.zoneStructure != nullptr) {
//		zoneStructure = new int* [object.nrRows];
//		for (int i = 0; i < object.nrRows; ++i) {
//			zoneStructure[i] = new int[object.nrColumns];
//		}
//
//		for (int i = 0; i < object.nrRows; ++i) {
//			for (int j = 0; j < object.nrColumns; ++j) {
//				zoneStructure[i][j] = object.zoneStructure[i][j];
//			}
//		}
//		nrRows = object.nrRows;
//		nrColumns = object.nrColumns;
//	}
//	else {
//		nrRows = 0;
//		nrColumns = 0;
//		zoneStructure = nullptr;
//	}
//}

buildingStructure::buildingStructure(const buildingStructure& object) {
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


buildingStructure& buildingStructure::operator=(const buildingStructure& object) {
	if (this != &object) {
		if (object.nrColumns > 0 && object.nrRows > 0 && object.zoneStructure != nullptr) {
			if (zoneStructure != nullptr) { //Unhandled exception thrown: read access violation.; this was nullptr
				for (int i = 0; i < nrRows; ++i) {
					delete[] zoneStructure[i];
				}
				delete[] zoneStructure;
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
			setEmptyZone(nrRows, nrColumns);
		}
		else {
			if (zoneStructure != nullptr) {
				for (int i = 0; i < nrRows; ++i) {
					delete[] zoneStructure[i];
				}
				delete[] zoneStructure;
			}
			nrRows = 0;
			nrColumns = 0;
			zoneStructure = nullptr;
		}
	}
	return *this;
}

buildingStructure::~buildingStructure() {
	if (zoneStructure != nullptr) {
		for (int i = 0; i < nrRows; ++i) {
			delete[] zoneStructure[i];
		}
		delete[] zoneStructure;
		zoneStructure = nullptr;
		nrRows = 0;
		nrColumns = 0;
	}
	nrRows = 0;
	nrColumns = 0;
}

int** buildingStructure::getZoneStructure() {
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

int buildingStructure::getNrRows() {
	return nrRows;
}

int buildingStructure::getNrColumns() {
	return nrColumns;
}

void buildingStructure::setEmptyZone(const int nrRows, const int nrColumns) {
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

//void buildingStructure::setEmptyZone(const int nrRows, const int nrColumns) {
//	if (nrColumns > 0 && nrRows > 0) {
//		// Delete the previous array, if it exists
//		if (this->zoneStructure != nullptr) {
//			for (int i = 0; i < this->nrRows; ++i) {
//				delete[] this->zoneStructure[i];
//			}
//			delete[] this->zoneStructure;
//		}
//
//		// Allocate a new array
//		this->zoneStructure = new int* [nrRows];
//		for (int i = 0; i < nrRows; ++i) {
//			this->zoneStructure[i] = new int[nrColumns];
//			// Check if memory allocation was successful
//			if (this->zoneStructure[i] == nullptr) {
//				// Memory allocation failed, handle error here
//				// (e.g. throw an exception)
//			}
//		}
//
//		// Initialize the elements of the array to 0
//		for (int i = 0; i < nrRows; ++i) {
//			for (int j = 0; j < nrColumns; ++j) {
//				this->zoneStructure[i][j] = 0;
//			}
//		}
//
//		// Update the class variables
//		this->nrRows = nrRows;
//		this->nrColumns = nrColumns;
//
//		// Return success
//		cout << endl << "succes" << endl;
//
//	}
//	// Return failure if nrColumns or nrRows are not positive
//
//}


void buildingStructure::setZoneStructure(const int** zoneStructure, const int nrRows, const int nrColumns) {
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
//void buildingStructure::setZoneStructure(const int** zoneStructure, const int nrRows, const int nrColumns) {
//	// Check for self-assignment
//	if (this->zoneStructure == zoneStructure) {
//		return;
//	}
//
//	// Check that nrRows and nrColumns match the dimensions of zoneStructure
//	bool validZoneStructure = true;
//	if (nrColumns > 0 && nrRows > 0 && zoneStructure != nullptr) {
//		for (int i = 0; i < nrRows; ++i) {
//			if (zoneStructure[i] == nullptr) {
//				validZoneStructure = false;
//				break;
//			}
//		}
//	}
//	else {
//		validZoneStructure = false;
//	}
//
//	if (!validZoneStructure) {
//		return;
//	}
//
//	// Deallocate the old zoneStructure and allocate new memory
//	if (this->zoneStructure != nullptr) {
//		for (int i = 0; i < this->nrRows; ++i) {
//			delete[] this->zoneStructure[i];
//		}
//		delete[] this->zoneStructure;
//		this->nrRows = 0;
//		this->nrColumns = 0;
//	}
//
//	this->zoneStructure = new int* [nrRows];
//	for (int i = 0; i < nrRows; ++i) {
//		this->zoneStructure[i] = new int[nrColumns];
//	}
//
//	// Copy values from zoneStructure to this->zoneStructure
//	for (int i = 0; i < nrRows; ++i) {
//		for (int j = 0; j < nrColumns; ++j) {
//			this->zoneStructure[i][j] = zoneStructure[i][j];
//		}
//	}
//	this->nrRows = nrRows;
//	this->nrColumns = nrColumns;
//}

int buildingStructure::availableCapacity() {
	return nrRows * nrColumns;
}

string buildingStructure::generateSeatID(const int zoneNumber, const int row, const int column) {
	string x = to_string(zoneNumber) + to_string(row) + to_string(column);
	return x;
}


ostream& operator<<(ostream& out, buildingStructure obj)
{
	if (obj.zoneStructure != nullptr && obj.nrRows > 0 && obj.nrColumns > 0) {
		out << endl << 0 << "   ";
		for (int i = 1; i <= obj.nrColumns; ++i) {
			out << i << " ";
		}
		out << endl << endl;
		for (int i = 0; i < obj.nrRows; ++i) {
			for (int j = 0; j < obj.nrColumns; ++j) {
				if (j == 0) {
					out << i + 1 << "   ";
				}
				out << obj.zoneStructure[i][j] << " ";
			}
			out << endl;
		}
		out << "Total available capacity is: " << obj.availableCapacity();
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
	cout << endl << "Columns Number: ";
	in >> columns;
	obj.setEmptyZone(rows, columns);


	return in;
}