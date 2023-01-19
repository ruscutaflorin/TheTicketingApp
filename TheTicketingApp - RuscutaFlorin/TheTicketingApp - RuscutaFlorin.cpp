// TheTicketingApp - RuscutaFlorin.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "buildingStructure.h"
#include "Event.h"
#include "Helpers.h"
#include "Location.h"
#include "Tickets.h"
#include "SaleTickets.h"
#include <string>
using namespace std;

long long SaleTickets::allTimeSoldTickets = 0;
int Location::maxCapacity = 0;

void RegisterEvent(Tickets& data) {
	cin >> data;
	cout << data;
}

void BuyTicket(Tickets data, SaleTickets& info) {
	if (data.getTypes() != nullptr) {
		cin >> info;
		if (info.isEligibleForBuying() && info.getID() != "Undefined") {
			string* types = data.getTypes();
			int* distribution = data.getTicketDistribution();
			int* prices = data.getPrice();
			for (int i = 0; i < data.getTypesNumber(); ++i) {
				cout << i + 1 << ", Type: " << types[i] << ", Price: " << prices[i] << ", Distribution: " << distribution[i] << endl;
				info.setTypesPriceAndDistribution(types, prices, distribution, data.getTypesNumber());
			}
			cout << "Type the id of the ticket you wanna buy!";
			int id;
			cin >> id;
			while (id != 0) {
				for (int i = 0; i < data.getTypesNumber(); ++i) {
					if (i == id - 1) {
						if (info.isTicketAvailable(types[i])) {
							info.incrementallTimeSoldTickets(1);
							cout << "You bought 1 ticket!" << " - " << info.getAllTimeSoldTickets() * info.getUniqueID() * 10782 << endl;
							distribution[i]--;
							info.setTypesPriceAndDistribution(types, prices, distribution, data.getTypesNumber());
						}
						else {
							system("cls");
							cout << "Tickets of this type are not available, try again later!";
							return;
						}
					}
				}
				cout << "If you wanna stop, type 0, if you wanna buy more, type the ticket id: ";
				cin >> id;
			}

		}
		else {
			cout << endl << "You're too young or you entered a incorect ID!";
		}
	}
	else {
		cout << "There is no event to register!";
		return;
	}
}

int main()
{
	cout << "Bun venit in cadrul aplicatiei de bilete!";
	cout << endl << "Tastati 1 pentru inregistrarea unui EVENIMENT \nTastati 2 pentru cumpararea unui bilet!\n";
	int operatie;
	int operatie1;
	cin >> operatie;
	cin.get();
	Tickets x;
	SaleTickets info;
	if (operatie == 1) {
		RegisterEvent(x);
		system("cls");
		cout << "You wanna buy a ticket at the event? Press 2 - ";
		cin >> operatie1;
		if (operatie1 == 2)
			BuyTicket(x, info);
		else {
			return 0;
		}
	}
	else if (operatie == 2) {
		BuyTicket(x, info);
	}
}

