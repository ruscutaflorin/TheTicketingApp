#pragma once

#include <iostream>
#include "Tickets.h"

using namespace std;


class SaleTickets :
	public Tickets
{
private:
	unsigned int clientAge;
	string clientName;
	string identityDocumentNumber;
	unsigned int purchasedTickets; // in interiorul unui singur eveniment
	static long long allTimeSoldTickets; // in total, la toate evenimentele

public:

	SaleTickets();

	SaleTickets(const string clientName, const string identityDocumentNumber, const unsigned int clientAge, const unsigned int purchasedTickets, const unsigned int typesNumber, const string* types, const int* ticketDistribution, const int* price, Event eventObject) : Tickets(typesNumber, types, ticketDistribution, price, eventObject) {};

	static long long averageTicketSales(const SaleTickets* tickets, const unsigned int nrObjects);

	static long long getAllTimeSoldTickets();

	static void incrementallTimeSoldTickets(const int nr);

};

long long SaleTickets::allTimeSoldTickets = 0;
