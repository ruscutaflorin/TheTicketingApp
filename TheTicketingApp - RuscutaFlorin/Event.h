using namespace std;
//#include <iostream>
//#include <cstring>
#include "Location.h"

class Event
{
	//friend class Tickets;
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

	Event();

	Event(const string, const string, const string, const char*, const string*, const  int, const string*, const  int, const string*, const  int, const long long, const int maxSpectators, const  int, const Location);

	Event(const Event&);

	Event& operator=(const Event&);

	~Event();

	char* getEventName();

	string getDate();

	string* getEventOrganizers();

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

	void setDate(const int, const int, const int);

	void setEventName(const char*);

	void setEventOrganizers(const string*, int);

	void setEventParticipants(const string*, int);

	void setEventSponsors(const string*, int);

	void sellTickets(int);

	int totalSoldTickets(const Event*, int);

	string eventWithMostSoldTickets(const  Event*, int);

	// daca exista sau nu nr max de spectatori.
	bool operator!();

	Event operator++();

	Event operator++(int);

	friend ostream& operator<<(ostream&, Event);
	friend istream& operator>>(istream&, Event&);

};

ostream& operator<<(ostream& out, Event obj);
istream& operator>>(istream& in, Event& obj);
