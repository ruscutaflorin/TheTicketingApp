#pragma once
class buildingStructure
{
	friend class Location;

private:
	int** zoneStructure;
	int nrRows;
	int nrColumns;

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
				else {
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

};

