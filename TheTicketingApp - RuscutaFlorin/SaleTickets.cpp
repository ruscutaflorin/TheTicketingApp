//#include "SaleTickets.h"
//
//SaleTickets::SaleTickets() {
//	clientAge = 0;
//	identityDocumentNumber = "Undefined";
//	clientName = "Undefined";
//	purchasedTickets = 0;
//}
//
//SaleTickets::SaleTickets(const string clientName, const string identityDocumentNumber, const unsigned int clientAge, const unsigned int purchasedTickets, const unsigned int typesNumber, const string* types, const int* ticketDistribution, const int* price, Event eventObject) : Tickets(typesNumber, types, ticketDistribution, price, eventObject) {
//	this->clientName = clientName;
//	this->identityDocumentNumber = identityDocumentNumber;
//	this->clientAge = clientAge;
//	this->purchasedTickets = purchasedTickets;
//
//	allTimeSoldTickets += purchasedTickets;
//}
//
//long long SaleTickets::averageTicketSales(const SaleTickets* tickets, const unsigned int nrObjects) {
//	if (tickets != nullptr && nrObjects > 0) {
//		int answer = 0;
//		for (int i = 0; i < nrObjects; ++i) {
//			answer += tickets[i].purchasedTickets;
//		}
//		return answer / nrObjects;
//	}
//	else {
//		return 0;
//	}
//}
//
//long long SaleTickets::getAllTimeSoldTickets() {
//	return allTimeSoldTickets;
//}
//
//void SaleTickets::incrementallTimeSoldTickets(const int nr) {
//	SaleTickets::allTimeSoldTickets = allTimeSoldTickets + nr;
//}
//
//
//long long SaleTickets::allTimeSoldTickets = 0;