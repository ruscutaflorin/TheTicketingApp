#pragma once
//#include <iostream>
#include <stdlib.h>     
#include <time.h>   
#include "Event.h" // daca o scot dispare eroarea cu class type redefinition
using namespace std;

class Tickets
{
	friend class Event;
	friend class Location;
	friend class buildingStructure;
	//friend class SafeTickets;

private:
	Event eventDetails;
	string* types;
	int* price;
	unsigned int typesNumber;
	unsigned long long uniqueID;
	int* ticketDistribution;
	//in ticket distribution stabilesc cate bilete din fiecare se ofera spre vanzare.
	// validare in main ca distributia sa nu depaseasca nrMaximSpectatori

public:

	Tickets();

	Tickets(const unsigned int, const string*, const int*, const int*, Event);

	Tickets(const Tickets& object);

	Tickets& operator=(const Tickets& object);

	~Tickets();

	string* getTypes();

	int* getPrice();

	unsigned int getTypesNumber();

	unsigned int getUniqueID();

	int* getTicketDistribution();

	void setTypesPriceAndDistribution(const string* types, const int* price, const int* ticketDistribution, const unsigned int nr);

	int revenueAfterOneEvent();

	int maxRevenueAfterAllEvents(Tickets* obj, int nr);

	int operator[](const string ticketType);

	//Tickets a;
	// int* x = (int*)a => preturile la bilete ale obiectului a.
	explicit operator int* ();

	friend ostream& operator<<(ostream& out, Tickets obj);
	friend istream& operator>>(istream& in, Tickets& obj);

};

ostream& operator<<(ostream& out, Tickets obj);

istream& operator>>(istream& in, Tickets& obj);

