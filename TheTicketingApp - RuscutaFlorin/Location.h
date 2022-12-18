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

	Location() :city("Unspecified") {
		address = "Unspecified";
		zones = nullptr;
		nrZones = 0;
		maxCapacity = 0;
	}

	Location(const string city, const string address, const string* zones, const int nrZones, buildingStructure* object) {
		if (city != "") {
			this->city = city;
		}
		if (address != "") {
			this->address = address;
		}
		else {
			this->address = "Unspecified";
		}
		if (nrZones > 0 && zones != nullptr) {
			delete[] this->zones;
			this->zones = new string[nrZones];
			for (int i = 0; i < nrZones; ++i) {
				this->zones[i] = zones[i];
			}
			this->nrZones = nrZones;
		}
		else {
			this->zones = nullptr;
			this->nrZones = 0;
		}

		if (object != nullptr && nrZones > 0) {
			for (int i = 0; i < nrZones; ++i) {
				obj[i].zoneStructure = new int* [object[i].nrRows];
				maxCapacity += object[i].nrRows * object[i].nrColumns;
				for (int j = 0; j < nrZones; ++j) {
					obj[i].zoneStructure[j] = new int[object[i].nrColumns];
				}
			}
		}
		else {
			this->nrZones = 0;
			obj = nullptr;
		}
	}

	Location(const Location& object) {
		city = object.city;
		address = object.address;
		if (object.zones != nullptr && object.nrZones > 0 && object.obj != nullptr) {
			zones = new string[nrZones];
			for (int i = 0; i < object.nrZones; ++i) {
				zones[i] = object.zones[i];
			}

			nrZones = object.nrZones;
			for (int i = 0; i < nrZones; ++i) {
				obj[i].zoneStructure = new int* [object.obj[i].nrRows];
				maxCapacity += object.obj[i].nrRows * object.obj[i].nrColumns;
				for (int j = 0; j < nrZones; ++j) {
					obj[i].zoneStructure[j] = new int[object.obj[i].nrColumns];
				}
			}
			for (int k = 0; k < nrZones; ++k) {
				for (int i = 0; i < nrZones; ++i) {
					for (int j = 0; j < nrZones; ++i) {
						obj[k].zoneStructure[i][j] = object.obj[k].zoneStructure[i][j];
					}

				}
			}
		}
		else {
			zones = nullptr;
			nrZones = 0;
			obj = nullptr;
			maxCapacity = 0;
		}
	}

	Location& operator=(const Location& object) {
		if (this != &object) {
			address = object.address;
			city = object.city;
			if (object.zones != nullptr && object.nrZones > 0 && object.obj != nullptr) {
				if (zones != nullptr) {
					delete[] zones;
					nrZones = 0;
				}

				zones = new string[nrZones];
				for (int i = 0; i < object.nrZones; ++i) {
					zones[i] = object.zones[i];
				}

				nrZones = object.nrZones;

				if (obj != nullptr) {
					delete[] obj;
				}

				for (int i = 0; i < nrZones; ++i) {
					obj[i].zoneStructure = new int* [object.obj[i].nrRows];
					maxCapacity += object.obj[i].nrRows * object.obj[i].nrColumns;
					for (int j = 0; j < nrZones; ++j) {
						obj[i].zoneStructure[j] = new int[object.obj[i].nrColumns];
					}
				}
				for (int k = 0; k < nrZones; ++k) {
					for (int i = 0; i < nrZones; ++i) {
						for (int j = 0; j < nrZones; ++i) {
							obj[k].zoneStructure[i][j] = object.obj[k].zoneStructure[i][j];
						}

					}
				}

			}
			else {
				zones = nullptr;
				nrZones = 0;
				obj = nullptr;
				maxCapacity = 0;
			}
		}
		return *this;
	}


	~Location() {

		if (zones != nullptr) {
			delete[] zones;
		}
		if (obj != nullptr) {
			delete[] obj;
		}
		nrZones = 0;
		maxCapacity = 0;

	}

	string getCity() {
		return city;
	}

	string getAddress() {
		return address;
	}

	int getNrZones() {
		return nrZones;
	}

	int getMaxCapacity() {
		return maxCapacity;
	}

	string* getZones() {
		if (zones != nullptr && nrZones > 0) {
			string* copy = new string[nrZones];
			for (int i = 0; i < nrZones; ++i) {
				copy[i] = zones[i];
			}
			return copy;
		}
		else {
			return nullptr;
		}
	}

	/*buildingStructure* getBuildingStructure() {
		if (obj != nullptr && nrZones > 0) {
			buildingStructure* object = new buildingStructure[nrZones];
			cin >> object;
			plm;

		}
		else {
			return nullptr;
		}
	}*/

	void setCity(const string input) {
		if (input != "") {
			city = input;
		}
	}

	void setAddress(const string input) {
		if (input != "") {
			address = input;
		}
	}

	void setZones(const string* input, const int nr) {
		if (input != nullptr && nr > 0) {
			if (zones != nullptr && nrZones > 0) {
				delete[] zones;
				nrZones = 0;
			}
			zones = new string[nr];
			for (int i = 0; i < nr; ++i) {
				zones[i] = input[i];
			}
			nrZones = nr;
		}
	}

	/*void setBuildingStructure(const buildingStructure* object, const string* zones, const int nr) {
		if (object != nullptr && nr == nrZones && nr > 0 && zones != nullptr) {
			if (this->zones != nullptr && nrZones > 0) {
				delete[] this->zones;
				nrZones = 0;
			}
			this->zones = new string[nr];
			for (int i = 0; i < nr; ++i) {
				this->zones[i] = zones[i];
			}
			nrZones = nr;

			if (obj != nullptr) {
				delete[] obj;
			}
			for (int i = 0; i < nr; ++i) {
				obj[i].setZoneStructure(object[i].zoneStructure, object[i].nrColumns, object[i].nrRows);
			}


		}
	}*/

	static int locationCapacity(buildingStructure* object, int objectNumber) {
		if (object != nullptr && objectNumber > 0) {
			unsigned long long cnt = 0;
			for (int i = 0; i < objectNumber; ++i) {
				cnt += object[i].availableCapacity();
			}
			return cnt;
		}
		return 0;
	}

	int** maxSeatsNextToEachotherForEachSector(buildingStructure* object, int objectNumber) {
		if (object != nullptr && objectNumber > 0) {
			int** result = new int* [objectNumber];
			for (int i = 0; i < objectNumber; ++i) {
				result[i] = new int[2];
			}
			for (int i = 0; i < objectNumber; ++i) {
				result[i][0] = i;
				result[i][1] = object[i].nrRows;
			}
			return result;
		}
		return nullptr;

	}

	Location operator--() {
		maxCapacity--;
		return *this;
	}

	Location operator--(int i) {
		Location copy = *this;
		maxCapacity--;
		return copy;
	}

	operator string* () {
		if (zones != nullptr && nrZones > 0) {
			string* copy = new string[nrZones];
			for (int i = 0; i < nrZones; ++i) {
				copy[i] = zones[i];
			}
			return copy;
		}
		return nullptr;
	}

	friend ostream& operator<<(ostream& out, Location obj);
	friend istream& operator>>(istream& in, Location& obj);

};

ostream& operator<<(ostream& out, Location obj)
{
	if (obj.city != "") {
		out << "The location is placed in: " << obj.city;
	}
	if (obj.address != "") {
		out << endl << "The address is: " << obj.address;
	}
	if (obj.zones != nullptr && obj.nrZones > 0) {
		out << "The location has " << obj.nrZones << " sectors and its maximum capacity is: " << obj.maxCapacity << endl;
		for (int i = 0; i < obj.nrZones; ++i) {
			out << i + 1 << " - " << obj.zones[i] << endl;
		}
	}

	return out;
}

istream& operator>>(istream& in, Location& obj)
{


	Helpers helper;

	string city;
	string address;
	int nrZones;
	string* zones;
	buildingStructure* object = new buildingStructure[nrZones];
	cout << "In which city is the location placed? ";
	getline(in, city);
	obj.setCity(city);
	cout << endl << "Type the address here: ";
	getline(in, address);
	obj.setAddress(address);
	cout << endl << "How many sectors your location has? (> 0)";
	in >> nrZones;
	if (nrZones > 0) {
		buildingStructure* object = new buildingStructure[nrZones];
		zones = new string[nrZones];
		cout << endl << "Name your sectors: " << endl;
		for (int i = 0; i < nrZones; ++i) {
			getline(in, zones[i]);
			cout << zones[i] << endl;
		}
		obj.setZones(zones, nrZones);
		for (int i = 0; i < nrZones; ++i) {
			cin >> object[i];
		}
	}

	return in;
}