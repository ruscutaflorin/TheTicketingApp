using namespace std;
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Location.h"
/// <summary>
/// zi luna an string daca folosesc pt validari
/// vector de preturi pe zone
/// </summary>
class Event
{
	friend class Tickets;

private:
	Date date;
	Location location;
	char* eventName;
	string* eventOrganizers;
	unsigned int organizersNumber;
	string* eventParticipants;
	unsigned int participantsNumber;
	string* eventSponsors;
	unsigned int sponsorsNumber;
	long long eventSoldTickets;
	unsigned int maxSpectators;
	// de facut verificari cu location.maxCapacity si maxSpectators
	Event() {
		eventName = nullptr;
		eventOrganizers = nullptr;
		organizersNumber = 0;
		eventParticipants = nullptr;
		participantsNumber = 0;
		eventSponsors = nullptr;
		sponsorsNumber = 0;
		eventSoldTickets = 0;
		maxSpectators = 0;
	}

	Event(const char* eventName, const string* eventOrganizers, const unsigned int organizersNumber, const string* eventParticipants, const unsigned int participantsNumber, const string* eventSponsors, const unsigned int sponsorsNumber, const long long eventSoldTickets, const unsigned int maxSpectators, const Date dateObject, const Location locationObject) :Event() {
		if (eventName != nullptr) {
			this->eventName = new char[strlen(eventName) + 1];
			strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		}
		if (eventOrganizers != nullptr && organizersNumber > 0) {
			this->eventOrganizers = new string[organizersNumber];
			for (int i = 0; i < organizersNumber; ++i) {
				this->eventOrganizers[i] = eventOrganizers[i];
			}
			this->organizersNumber = organizersNumber;
		}
		if (eventParticipants != nullptr && participantsNumber > 0) {
			this->eventParticipants = new string[participantsNumber];
			for (int i = 0; i < participantsNumber; ++i) {
				this->eventParticipants[i] = eventParticipants[i];
			}
			this->participantsNumber = participantsNumber;
		}
		if (eventSponsors != nullptr && sponsorsNumber > 0) {
			this->eventSponsors = new string[sponsorsNumber];
			for (int i = 0; i < sponsorsNumber; ++i) {
				this->eventSponsors[i] = eventSponsors[i];
			}
			this->sponsorsNumber = sponsorsNumber;
		}

		this->eventSoldTickets = eventSoldTickets;
		this->maxSpectators = maxSpectators;

		if ((dateObject.isValid())) {
			date.setDay(dateObject.day());
			date.setMonth(dateObject.month());
			date.setYear(dateObject.month());
		}

		location = locationObject;

	}

	Event(const Event& object) {

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

	Event& operator=(const Event& object) {
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


	~Event() {
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
};

