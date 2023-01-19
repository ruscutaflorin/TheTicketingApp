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

void BuyTicket(Tickets& data, SaleTickets& info) {
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
						cout << "You bought 1 ticket!" << " - " << info.getAllTimeSoldTickets() << endl;
						distribution[i]--;
						info.setTypesPriceAndDistribution(types, prices, distribution, data.getTypesNumber());
					}
					else {
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
		cout << endl << "You have to grow a little bit more!";
	}
}

int main()
{
	/*buildingStructure a;
	Location b;
	Event c;
	string asd[] = { "normal", "vip", "test" };
	int x[4];
	x[0] = 100;
	x[1] = 200;
	x[2] = 300;

	Tickets d(3, asd, x, x, c);
	SaleTickets e;
	cout << endl << a;
	cout << endl << b;
	cout << endl << c;
	cout << endl << d;
	cout << endl << e;

	int* x1 = (int*)d;
	cout << d.getTypesNumber() << endl;
	for (int i = 0; i < d.getTypesNumber(); ++i)
		cout << x1[i] << endl;*/

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

