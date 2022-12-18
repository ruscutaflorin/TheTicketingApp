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
	const string city;
	string address;
	string* zones;
	unsigned int nrZones;
	unsigned int maxCapacity;
	buildingStructure* obj;

	Location() :city("Unspecified") {
		address = "Unspecified";
		zones = nullptr;
		nrZones = 0;
		maxCapacity = 0;
	}

	Location(const string city, const string address, const string* zones, const unsigned int nrZones, buildingStructure* object) :city(city) {
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

	Location(const Location& object) :city(object.city) {
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
			if (object.zones != nullptr && object.nrZones > 0 && object.obj != nullptr) {
				if (zones != nullptr) {
					delete[] zones;
					nrZones = 0;
				}
				else {
					zones = new string[nrZones];
					for (int i = 0; i < object.nrZones; ++i) {
						zones[i] = object.zones[i];
					}

					nrZones = object.nrZones;
				}
				// de verificat daca tre sa distrug si campurile din zonestructure
				if (obj != nullptr) {
					delete[] obj;
				}
				else {
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
		/// <summary>
		/// DACA E OBIECT, destructurez si campurile lui sau?
		/// </summary>
		if (obj != nullptr) {
			delete[] obj;
		}
		nrZones = 0;
		maxCapacity = 0;

	}

};

