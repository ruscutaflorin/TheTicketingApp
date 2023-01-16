#include "Location.h"
#include "Helpers.h"
#include "buildingStructure.h"
#include <cstring>
#include <vector>
Location::Location() :city("Unspecified") {
	address = "Unspecified";
	zones = nullptr;
	nrZones = 0;
	maxCapacity = 0;
}

Location::Location(const string city, const string address, const string* zones, const int nrZones, const vector<buildingStructure> object) {
	if (city != "") {
		this->city = city;
	}
	if (address != "") {
		this->address = address;
	}
	else {
		this->address = "Unspecified";
	}
	if (nrZones > 0 && zones != nullptr && !object.empty()) {
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

	if (!object.empty() && nrZones > 0) {
		obj = vector <buildingStructure>(object);
		for (auto& bs : obj)
			maxCapacity += bs.nrRows * bs.nrColumns;
		cout << endl << maxCapacity;
	}
	else {
		this->nrZones = 0;
		obj.clear();
	}
}

Location::Location(const Location& object) {
	city = object.city;
	address = object.address;
	maxCapacity = object.maxCapacity;
	if (object.zones != nullptr && object.nrZones > 0 && !object.obj.empty()) {
		zones = new string[object.nrZones];
		for (int i = 0; i < object.nrZones; ++i) {
			zones[i] = object.zones[i];
		}
		nrZones = object.nrZones;
		obj = vector < buildingStructure>(object.obj);

		maxCapacity += object.maxCapacity;

	}
	else {
		zones = nullptr;
		nrZones = 0;
		maxCapacity = 0;
	}
}

Location& Location::operator=(const Location& object) {
	if (this != &object) {
		address = object.address;
		city = object.city;
		if (object.zones != nullptr && object.nrZones > 0 && !object.obj.empty()) {
			if (zones != nullptr) {
				delete[] zones;
			}

			zones = new string[object.nrZones];
			for (int i = 0; i < object.nrZones; ++i) {
				zones[i] = object.zones[i];
			}

			nrZones = object.nrZones;

			obj = vector<buildingStructure>(object.obj); // use the assignment operator of the vector to make a deep copy
			maxCapacity = object.maxCapacity; // set maxCapacity
		}
		else {
			zones = nullptr;
			nrZones = 0;
			obj.clear();
			maxCapacity = 0;
		}
	}
	return *this;
}


Location::~Location() {

	if (zones != nullptr) {
		delete[] zones;
	}
	obj.clear();
	nrZones = 0;
	maxCapacity = 0;
}

string Location::getCity() {
	return city;
}

string Location::getAddress() {
	return address;
}

int Location::getNrZones() {
	return nrZones;
}

int Location::getMaxCapacity() {
	return maxCapacity;
}

string* Location::getZones() {
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


void Location::setCity(const string input) {
	if (input != "") {
		city = input;
	}
}

void Location::setAddress(const string input) {
	if (input != "") {
		address = input;
	}
}

void Location::setZones(const string* input, const int nr) {
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

int Location::locationCapacity(const vector<buildingStructure> object) {
	if (!object.empty()) {
		unsigned long long cnt = 0;
		for (int i = 0; i < object.size(); ++i) {
			cnt += object[i].nrColumns * object[i].nrRows;
		}
		return cnt;
	}
	return 0;
}

int** Location::maxSeatsNextToEachotherForEachSector(const vector<buildingStructure> object) {

	return nullptr;

}

Location Location::operator--() {
	maxCapacity--;
	return *this;
}

Location Location::operator--(int i) {
	Location copy = *this;
	maxCapacity--;
	return copy;
}

Location::operator string* () {
	if (zones != nullptr && nrZones > 0) {
		string* copy = new string[nrZones];
		for (int i = 0; i < nrZones; ++i) {
			copy[i] = zones[i];
		}
		return copy;
	}
	return nullptr;
}


ostream& operator<<(ostream& out, Location obj)
{
	if (obj.city != "") {
		out << endl << "The location is placed in: " << obj.city;
	}
	if (obj.address != "") {
		out << endl << "The address is: " << obj.address << endl;
	}
	if (obj.zones != nullptr && obj.nrZones > 0 && !obj.obj.empty()) {
		out << "The location has " << obj.nrZones << " sectors and its maximum capacity is: " << obj.maxCapacity << endl;;
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
	cout << "In which city is the location placed? ";
	getline(in, city);
	obj.setCity(city);
	cout << endl << "Type the address here: ";
	getline(in, address);
	obj.setAddress(address);
	cout << endl << "How many sectors your location has? (> 0) -> ";
	in >> nrZones;
	if (nrZones > 0) {
		zones = new string[nrZones];
		cout << endl << "Name your sectors: " << endl;
		getline(in, zones[0]);
		for (int i = 0; i < nrZones; ++i) {
			getline(in, zones[i]);
		}
		obj.setZones(zones, nrZones);
		buildingStructure* x = new buildingStructure[nrZones];
		for (int i = 0; i < nrZones; ++i) {
			cout << "\nSet the dimensions of the zone " << i + 1 << "! -> ";
			in >> x[i];
			obj.obj.push_back(x[i]);
			cout << endl;
			cout << obj.obj[i];
			cout << endl;
		}
	}

	return in;
}