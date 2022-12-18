using namespace std;
#include <iostream>
#include <cstring>
#include "Location.h"
#include "Helpers.h"

class Event
{
	friend class Tickets;

private:
	string date, day, year, month;
	Location location;
	char* eventName;
	string* eventOrganizers;
	int organizersNumber;
	string* eventParticipants;
	int participantsNumber;
	string* eventSponsors;
	int sponsorsNumber;
	long long eventSoldTickets;
	int maxSpectators;
	const int ageRestricted;
	// de facut verificari cu location.maxCapacity si maxSpectators in main

public:

	Event() :ageRestricted(18) {
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
	}

	Event(const string day, const string month, const string year, const char* eventName, const string* eventOrganizers, const  int organizersNumber, const string* eventParticipants, const  int participantsNumber, const string* eventSponsors, const  int sponsorsNumber, const long long eventSoldTickets, const  int maxSpectators, const  int ageRestricted, const Location locationObject) :ageRestricted(ageRestricted) {};

	Event(const Event& object) :ageRestricted(object.ageRestricted) {};

	Event& operator=(const Event& object);

	~Event();

	char* getEventName();

	string getDate();

	string* getEventOrganizers();

	string* getEventParticipants();

	string* getEventParticipants();

	int getDay();
	int getMonth();
	int getYear();
	int getOrganizersNumber();
	int getParticipantsNumber();
	int getSponsorsNumber();
	int getMaxSpectators();
	int getRestrictedAge();

	long long getSoldTickets();

	void setDate(const int day, const int month, const int year);

	void setEventName(const char* input);

	void setEventOrganizers(const string* input, int nr);

	void setEventParticipants(const string* input, int nr);

	void setEventSponsors(const string* input, int nr);

	int sellTickets(int nr);

	int totalSoldTickets(const Event* obj, int nr);

	string eventWithMostSoldTickets(const  Event* obj, int nr);

	// daca exista sau nu nr max de spectatori.
	bool operator!();

	Event operator++();

	Event operator++(int i);

	friend ostream& operator<<(ostream& out, Event obj);
	friend istream& operator>>(istream& in, Event& obj);

};

ostream& operator<<(ostream& out, Event obj);
istream& operator>>(istream& in, Event& obj);
