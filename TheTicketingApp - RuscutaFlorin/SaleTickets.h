#pragma once

#ifndef SALETICKETS_H
#define SALETICKETS_H

#include <iostream>
#include "Tickets.h"

using namespace std;

class SaleTickets :
	public Tickets
{
	// public Tickets::(campurile)
private:
	unsigned int clientAge;
	string clientName;
	string identityDocumentNumber;
	unsigned int purchasedTickets; // in interiorul unui singur eveniment
	static long long allTimeSoldTickets; // in total, la toate evenimentele
public:

	SaleTickets();

	SaleTickets(const string clientName, const string identityDocumentNumber, const unsigned int clientAge, const unsigned int purchasedTickets, const unsigned int typesNumber, const string* types, const int* ticketDistribution, const int* price, Event eventObject);

	~SaleTickets();

	unsigned int getClientAge();

	string getClientName();

	string getID();

	static long long averageTicketSales(const SaleTickets*, const unsigned int);

	static long long getAllTimeSoldTickets();

	static void incrementallTimeSoldTickets(const int);

	int getTotalCost(const string, const int);

	bool isTicketAvailable(const string);

	void decreaseTicketDistribution(const string, const int);

	void increaseTicketDistribution(const string, const int);

	void displayTicketInformation(const string);

	bool isEligibleForBuying();


	friend ostream& operator<<(ostream& out, SaleTickets obj);
	friend istream& operator>>(istream& in, SaleTickets& obj);
};

ostream& operator<<(ostream& out, SaleTickets obj);

istream& operator>>(istream& in, SaleTickets& obj);

//constructur de copiere ClasType v3 = v2;
//operator = Clastype v3; v3 = v1;

#endif