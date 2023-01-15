#include <iostream>
#include "SaleTickets.h"
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

long long SaleTickets::averageTicketSales(const SaleTickets* tickets, const unsigned int nrObjects) {
	if (tickets != nullptr && nrObjects > 0) {
		int answer = 0;
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
	SaleTickets::allTimeSoldTickets = allTimeSoldTickets + nr;
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

/*
#include <iostream>
#include "SaleTickets.h"
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

long long SaleTickets::averageTicketSales(const SaleTickets* tickets, const unsigned int nrObjects) {
	if (tickets != nullptr && nrObjects > 0) {
		int answer = 0;
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
	SaleTickets::allTimeSoldTickets = allTimeSoldTickets + nr;
}

int SaleTickets::getTotalCost() {
	// Calculate the total cost of the tickets purchased
	int totalCost = 0;
	for (int i = 0; i < typesNumber; i++) {
		if (types[i] == ticketType) {
			totalCost += purchasedTickets * price[i];
			break;
		}
	}
	return totalCost;
}

bool SaleTickets::isTicketAvailable(const string& ticketType) {
	// Check if the requested ticket type is still available
	for (int i = 0; i < typesNumber; i++) {
		if (types[i] == ticketType && ticketDistribution[i] > 0) {
			return true;
		}
	}
	return false;
}

void SaleTickets::updateTicketDistribution(const string& ticketType, const int nr) {
	// Update the ticket distribution for the requested ticket type
	for (int i = 0; i < typesNumber; i++) {
		if (types[i] == ticketType) {
			ticketDistribution[i] -= nr;
			break;
		}
	}
}

void SaleTickets::displayTicketInformation() {
	// Display the ticket information (e.g., event name, ticket type, price)
	cout << "Event: " << eventObject.getEventName() << endl;
	cout << "Ticket type: " << ticketType << endl;
	for (int i = 0; i < typesNumber; i++) {
		if (types[i] == ticketType) {
			cout << "Price: " << price[i] << " RON" << endl;
			break;
		}
	}
}

bool SaleTickets::hasPurchasedTickets(const string& identityDocumentNumber) {
	// Check if the customer has already purchased tickets by comparing the identity document number
	return this->identityDocumentNumber == identityDocumentNumber;
}

void SaleTickets::displaySummary() {
	// Display a summary of the ticket sales (e.g., total number of tickets sold, total revenue)
	cout << "Total number of tickets sold: " << purchasedTickets << endl;
	cout << "Total revenue: " << getTotalCost() << " RON" << endl;
}

bool SaleTickets::isEligibleForDiscount(const string& discountType) {
	// Check if the customer is eligible for a discount (e.g., based on age or membership status)
	if (discountType == "age") {
		return clientAge < 18 || clientAge > 65;
	}
	else if (discountType == "membership") {
		return clientName[0] == 'A'; // assuming that customers with names starting with 'A' are eligible for a discount
	}
	else {
		return false;
	}
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
*/