#include <iostream>
#include <string>
#include "SaleTickets.h"
#include "Helpers.h"
using namespace std;

SaleTickets::SaleTickets() {
	clientAge = 0;
	identityDocumentNumber = "Undefined";
	clientName = "Undefined";
	purchasedTickets = 0;
}

SaleTickets::SaleTickets(const string clientName, const string identityDocumentNumber, const unsigned int clientAge, const unsigned int purchasedTickets, const unsigned int typesNumber, const string* types, const int* ticketDistribution, const int* price, Event eventObject) : Tickets(typesNumber, types, ticketDistribution, price, eventObject) {
	this->clientName = clientName;
	this->identityDocumentNumber = identityDocumentNumber;
	this->clientAge = clientAge;
	this->purchasedTickets = purchasedTickets;

	allTimeSoldTickets += purchasedTickets;
}

SaleTickets::~SaleTickets() {
	if (types != nullptr)
		delete[] types, types = nullptr;
	if (price != nullptr)
		delete[] price, price = nullptr;
}

unsigned int SaleTickets::getClientAge() {
	return clientAge;
}

string SaleTickets::getClientName() {
	return clientName;
}

string SaleTickets::getID() {
	return identityDocumentNumber;
}

long long SaleTickets::averageTicketSales(const SaleTickets* tickets, const unsigned int nrObjects) {
	if (tickets != nullptr && nrObjects > 0) {
		long long answer = 0;
		for (int i = 0; i < nrObjects; ++i) {
			answer += tickets[i].purchasedTickets;
		}
		return answer / nrObjects;
	}
	else {
		return 0;
	}
}

long long SaleTickets::getAllTimeSoldTickets() {
	return allTimeSoldTickets;
}

void SaleTickets::incrementallTimeSoldTickets(const int nr) {
	allTimeSoldTickets = allTimeSoldTickets + nr;
}

int SaleTickets::getTotalCost(const string ticketType, const int purchasedTickets) {
	int totalCost = 0;
	for (int i = 0; i < typesNumber; i++) {
		if (types[i] == ticketType) {
			totalCost += purchasedTickets * price[i];
			break;
		}
	}
	return totalCost;
}

bool SaleTickets::isTicketAvailable(const string ticketType) {
	for (int i = 0; i < typesNumber; i++) {
		if (types[i] == ticketType && ticketDistribution[i] > 0) {
			return true;
		}
	}
	return false;
}

void SaleTickets::decreaseTicketDistribution(const string ticketType, const int nr) {
	for (int i = 0; i < typesNumber; i++) {
		if (types[i] == ticketType) {
			ticketDistribution[i] -= nr;
			break;
		}
	}
}

void SaleTickets::increaseTicketDistribution(const string ticketType, const int nr) {
	for (int i = 0; i < typesNumber; i++) {
		if (types[i] == ticketType) {
			ticketDistribution[i] += nr;
			break;
		}
	}
}

void SaleTickets::displayTicketInformation(const string ticketType) {
	cout << "Event: " << eventDetails << endl;
	cout << "Ticket type: " << ticketType << endl;
	for (int i = 0; i < typesNumber; i++) {
		if (types[i] == ticketType) {
			cout << "Price: " << price[i] << " RON, Available: " << ticketDistribution[i] << endl;
			break;
		}
	}
}


bool SaleTickets::isEligibleForBuying() {
	if (clientAge >= 18)
		return 1;
	return 0;
}

ostream& operator<<(ostream& out, SaleTickets obj)
{
	out << "Client Name is: " << obj.clientName;
	out << endl << "Client Age is: " << obj.clientAge;
	out << endl << "CNP: " << obj.identityDocumentNumber;
	out << endl << "The client purchased " << obj.purchasedTickets << " number of tickets!";
	out << endl;
	return out;
}

istream& operator>>(istream& in, SaleTickets& obj) {
	Helpers h;
	cout << "Type your age: ";
	in >> obj.clientAge;
	cout << "Type your ID: ";
	in.ignore();
	char c;
	string x = "";
	for (int i = 0; i < 13; ++i) {
		cin >> c;
		x += c;
	}
	if (h.readStringWithOnlyDigits(x) != "Only digits accepted")
		obj.identityDocumentNumber = x;
	else
		obj.identityDocumentNumber = "Undefined";
	return in;
}
