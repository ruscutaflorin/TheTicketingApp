#include "Event.h"
#include "Helpers.h"
#include "Location.h"
#include <string>

using namespace std;

Event::Event() :ageRestricted(18) {
	date = "Undefined";
	eventName = nullptr;
	eventOrganizers = nullptr;
	organizersNumber = 0;
	eventParticipants = nullptr;
	participantsNumber = 0;
	eventSponsors = nullptr;
	sponsorsNumber = 0;
	eventSoldTickets = 0;
	maxSpectators = 0;
};


Event::Event(const string day, const string month, const string year, const char* eventName, const string* eventOrganizers, const  int organizersNumber, const string* eventParticipants, const  int participantsNumber, const string* eventSponsors, const  int sponsorsNumber, const long long eventSoldTickets, const int maxSpectators, const int ageRestricted, const Location locationObject)
	:ageRestricted(ageRestricted)
{

	this->day = day;
	this->month = month;
	this->year = year;
	date = day + '-' + month + '-' + year;

	if (eventName != nullptr) {
		this->eventName = new char[strlen(eventName) + 1];
		strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
	}
	else {
		this->eventName = nullptr;
	}
	if (eventOrganizers != nullptr && organizersNumber > 0) {
		this->eventOrganizers = new string[organizersNumber];
		for (int i = 0; i < organizersNumber; ++i) {
			this->eventOrganizers[i] = eventOrganizers[i];
		}
		this->organizersNumber = organizersNumber;
	}
	else {
		this->eventOrganizers = nullptr;
		this->organizersNumber = 0;
	}
	if (eventParticipants != nullptr && participantsNumber > 0) {
		this->eventParticipants = new string[participantsNumber];
		for (int i = 0; i < participantsNumber; ++i) {
			this->eventParticipants[i] = eventParticipants[i];
		}
		this->participantsNumber = participantsNumber;
	}
	else {
		this->eventParticipants = nullptr;
		this->participantsNumber = 0;
	}
	if (eventSponsors != nullptr && sponsorsNumber > 0) {
		this->eventSponsors = new string[sponsorsNumber];
		for (int i = 0; i < sponsorsNumber; ++i) {
			this->eventSponsors[i] = eventSponsors[i];
		}
		this->sponsorsNumber = sponsorsNumber;
	}
	else {
		this->eventSponsors = nullptr;
		this->sponsorsNumber = 0;
	}
	this->eventSoldTickets = eventSoldTickets;
	this->maxSpectators = maxSpectators;

	location = locationObject;

}

Event::Event(const Event& object) :ageRestricted(object.ageRestricted) {

	date = object.date;
	location = object.location;

	if (object.eventName != nullptr) {
		eventName = new char[strlen(object.eventName) + 1];
		strcpy_s(eventName, strlen(object.eventName) + 1, object.eventName);
	}
	else {
		eventName = nullptr;
	}
	if (object.eventOrganizers != nullptr && object.organizersNumber > 0) {
		eventOrganizers = new string[object.organizersNumber];
		for (int i = 0; i < object.organizersNumber; ++i) {
			eventOrganizers[i] = object.eventOrganizers[i];
		}
		organizersNumber = object.organizersNumber;
	}
	else {
		eventOrganizers = nullptr;
		organizersNumber = 0;
	}
	if (object.eventParticipants != nullptr && object.participantsNumber > 0) {
		eventParticipants = new string[object.participantsNumber];
		for (int i = 0; i < object.participantsNumber; ++i) {
			eventParticipants[i] = object.eventParticipants[i];
		}
		participantsNumber = object.participantsNumber;
	}
	else {
		eventParticipants = nullptr;
		participantsNumber = 0;
	}
	if (object.eventSponsors != nullptr && object.sponsorsNumber > 0) {
		eventSponsors = new string[object.sponsorsNumber];
		for (int i = 0; i < object.sponsorsNumber; ++i) {
			eventSponsors[i] = object.eventSponsors[i];
		}
		sponsorsNumber = object.sponsorsNumber;
	}
	else {
		eventSponsors = nullptr;
		sponsorsNumber = 0;
	}

	eventSoldTickets = object.eventSoldTickets;
	maxSpectators = object.maxSpectators;
}

Event& Event::operator=(const Event& object) {
	if (this != &object) {

		date = object.date;
		location = object.location;

		if (object.eventName != nullptr) {
			if (eventName != nullptr) {
				delete[] eventName;
			}
			eventName = new char[strlen(object.eventName) + 1];
			strcpy_s(eventName, strlen(object.eventName) + 1, object.eventName);
		}
		else {
			eventName = nullptr;
		}
		if (object.eventOrganizers != nullptr && object.organizersNumber > 0) {
			if (eventOrganizers != nullptr) {
				delete[] eventOrganizers;
				organizersNumber = 0;
			}
			eventOrganizers = new string[object.organizersNumber];
			for (int i = 0; i < object.organizersNumber; ++i) {
				eventOrganizers[i] = object.eventOrganizers[i];
			}
			organizersNumber = object.organizersNumber;
		}
		else {
			eventOrganizers = nullptr;
			organizersNumber = 0;
		}
		if (object.eventParticipants != nullptr && object.participantsNumber > 0) {
			if (eventParticipants != nullptr) {
				delete[] eventParticipants;
				participantsNumber = 0;
			}
			eventParticipants = new string[object.participantsNumber];
			for (int i = 0; i < object.participantsNumber; ++i) {
				eventParticipants[i] = object.eventParticipants[i];
			}
			participantsNumber = object.participantsNumber;
		}
		else {
			eventParticipants = nullptr;
			participantsNumber = 0;
		}
		if (object.eventSponsors != nullptr && object.sponsorsNumber > 0) {
			if (eventSponsors != nullptr) {
				delete[] eventSponsors;
				sponsorsNumber = 0;
			}
			eventSponsors = new string[object.sponsorsNumber];
			for (int i = 0; i < object.sponsorsNumber; ++i) {
				eventSponsors[i] = object.eventSponsors[i];
			}
			sponsorsNumber = object.sponsorsNumber;
		}
		else {
			eventSponsors = nullptr;
			sponsorsNumber = 0;
		}

		eventSoldTickets = object.eventSoldTickets;
		maxSpectators = object.maxSpectators;


	}
	return *this;
}


Event::~Event() {
	if (eventName != nullptr) {
		delete[] eventName;
	}
	if (eventOrganizers != nullptr) {
		delete[] eventOrganizers;
	}
	if (eventParticipants != nullptr) {
		delete[] eventParticipants;
	}
	if (eventSponsors != nullptr) {
		delete[] eventSponsors;
	}
	organizersNumber = 0;
	participantsNumber = 0;
	sponsorsNumber = 0;
	eventSoldTickets = 0;
	maxSpectators = 0;

}


string Event::getDate() {
	return date;
}
char* Event::getEventName() {
	if (eventName != nullptr) {
		char* copy = new char[strlen(eventName) + 1];
		strcpy_s(copy, strlen(eventName) + 1, eventName);
		return copy;
	}
	return nullptr;
}

string* Event::getEventOrganizers() {
	if (eventOrganizers != nullptr && organizersNumber > 0) {
		string* copy = new string[organizersNumber];
		for (int i = 0; i < organizersNumber; ++i) {
			copy[i] = eventOrganizers[i];
		}
		return copy;
	}
	return nullptr;
}


string* Event::getEventParticipants() {
	if (eventSponsors != nullptr && sponsorsNumber > 0) {
		string* copy = new string[sponsorsNumber];
		for (int i = 0; i < sponsorsNumber; ++i) {
			copy[i] = eventSponsors[i];
		}
		return copy;
	}
	return nullptr;
}

int Event::getDay() {
	return stoi(day);
}
int Event::getMonth() {
	return stoi(month);
}
int Event::getYear() {
	return stoi(year);
}
int Event::getOrganizersNumber() {
	return organizersNumber;
}
int Event::getParticipantsNumber() {
	return participantsNumber;
}
int Event::getSponsorsNumber() {
	return sponsorsNumber;
}
int Event::getMaxSpectators() {
	return maxSpectators;
}
int Event::getRestrictedAge() {
	return ageRestricted;
}
long long Event::getSoldTickets() {
	return eventSoldTickets;
}



void Event::setDate(const int day, const int month, const int year) {
	Helpers helper;
	if (helper.dateIsValid(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
		date = to_string(day) + '-' + to_string(month) + '-' + to_string(year);
	}
}

void Event::setEventName(const char* input) {
	if (input != nullptr) {
		this->eventName = new char[strlen(input) + 1];
		strcpy_s(this->eventName, strlen(input) + 1, input);
	}
}

void Event::setEventOrganizers(const string* input, int nr) {
	if (input != nullptr && nr > 0) {
		if (eventOrganizers != nullptr) {
			delete[] eventOrganizers;
			organizersNumber = 0;
		}
		eventOrganizers = new string[nr];
		for (int i = 0; i < nr; ++i) {
			eventOrganizers[i] = input[i];
		}
		organizersNumber = nr;
	}
}

void Event::setEventParticipants(const string* input, int nr) {
	if (input != nullptr && nr > 0) {
		if (eventParticipants != nullptr) {
			delete[] eventParticipants;
			participantsNumber = 0;
		}
		eventParticipants = new string[nr];
		for (int i = 0; i < nr; ++i) {
			eventParticipants[i] = input[i];
		}
		participantsNumber = nr;
	}
}

void Event::setEventSponsors(const string* input, int nr) {
	if (input != nullptr && nr > 0) {
		if (eventSponsors != nullptr) {
			delete[] eventSponsors;
			sponsorsNumber = 0;
		}
		eventSponsors = new string[nr];
		for (int i = 0; i < nr; ++i) {
			eventSponsors[i] = input[i];
		}
		sponsorsNumber = nr;
	}
}

void Event::sellTickets(int nr) {
	eventSoldTickets += nr;

}

int Event::totalSoldTickets(const Event* obj, int nr) {
	if (obj != nullptr && nr > 0) {
		unsigned int cnt = 0;
		for (int i = 0; i < nr; ++i) {
			cnt += obj[i].eventSoldTickets;
		}
		return cnt;
	}
	return 0;
}

string Event::eventWithMostSoldTickets(const  Event* obj, int nr) {
	if (obj != nullptr && nr > 0) {
		unsigned int maxValue = 0;
		string answer;
		for (int i = 0; i < nr; ++i) {
			if (obj[i].eventSoldTickets > maxValue) {
				maxValue = obj[i].eventSoldTickets;
				answer = obj[i].eventName;
			}
		}
		return answer;
	}
	return "Undefined";
}

// daca exista sau nu nr max de spectatori.
bool Event::operator!() {
	return maxSpectators <= 0;
}

Event Event::operator++() {
	eventSoldTickets++;
	return *this;
}

Event Event::operator++(int i) {
	Event copy = *this;
	eventSoldTickets++;
	return copy;
}



ostream& operator<<(ostream& out, Event obj)
{
	out << "The event is taking place on: " << obj.date << endl;
	out << obj.location;
	if (obj.eventName != nullptr) {
		string x = obj.eventName;
		out << endl << x;
	}
	if (obj.eventOrganizers != nullptr && obj.organizersNumber > 0) {
		out << endl << "The event organizers are: ";
		for (int i = 0; i < obj.organizersNumber; ++i) {
			out << " " << obj.eventOrganizers[i] << " ";
		}
	}
	if (obj.eventParticipants != nullptr && obj.participantsNumber > 0) {
		out << endl << "The event participants are: ";
		for (int i = 0; i < obj.participantsNumber; ++i) {
			out << " " << obj.eventParticipants[i] << " ";
		}
	}
	if (obj.eventSponsors != nullptr && obj.sponsorsNumber > 0) {
		out << endl << "The event sponsors are: ";
		for (int i = 0; i < obj.sponsorsNumber; ++i) {
			out << " " << obj.eventSponsors[i] << " ";
		}
	}

	if (obj.eventSoldTickets > 0) {
		out << endl << "The event sold " << obj.eventSoldTickets << " tickets!";
	}

	out << "The event will have maximum " << obj.maxSpectators << " spectators!" << endl;
	out << "The age restriction is: " << obj.ageRestricted << endl;

	return out;
}

istream& operator>>(istream& in, Event& obj)
{
	int day, year, month;
	Location object;
	string eName;
	int orgNr, partNr, sponsNr;
	string* evOrg;
	string* evPart;
	string* evSpons;
	int maxSpectators;
	cout << "Enter the date of the event DD MM YYYY:" << endl;
	in >> day >> year >> month;
	obj.setDate(day, year, month);
	in >> object;
	cout << "Enter the name of the event: ";
	getline(in, eName);
	obj.setEventName(eName.c_str());
	cout << endl << "How many event organizers are? - ";
	in >> orgNr;
	if (orgNr > 0) {
		cout << endl << "Name the organizers one by one: ";
		evOrg = new string[orgNr];
		for (int i = 0; i < orgNr; ++i) {
			getline(in, evOrg[i]);
			cout << endl;
		}
		obj.setEventOrganizers(evOrg, orgNr);
	}
	cout << endl << "How many event participants are? - ";
	in >> partNr;
	if (partNr > 0) {
		cout << endl << "Name the participants one by one: ";
		evPart = new string[partNr];
		for (int i = 0; i < partNr; ++i) {
			getline(in, evPart[i]);
			cout << endl;

		}
		obj.setEventOrganizers(evPart, partNr);
	}
	cout << endl << "How many event sponsors are? - ";
	in >> sponsNr;
	if (sponsNr > 0) {
		cout << endl << "Name the sponsors one by one: ";
		evSpons = new string[sponsNr];
		for (int i = 0; i < sponsNr; ++i) {
			getline(in, evSpons[i]);
			cout << endl;
		}
		obj.setEventOrganizers(evSpons, sponsNr);
	}
	cout << "Now introduce the maximum number of spectators(not greather than: " << object.getMaxCapacity() << ") - ";
	in >> maxSpectators;
	if (maxSpectators <= object.getMaxCapacity()) {
		obj.maxSpectators = maxSpectators;
	}
	return in;
}
