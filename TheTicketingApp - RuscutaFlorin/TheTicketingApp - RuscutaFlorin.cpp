// TheTicketingApp - RuscutaFlorin.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "buildingStructure.h"
#include "Event.h"
#include "Helpers.h"
#include "Location.h"
#include "Tickets.h"
#include "SaleTickets.h"
using namespace std;

long long SaleTickets::allTimeSoldTickets = 0;
int Location::maxCapacity = 0;

void RegisterEvent() {
	/*Location data;
	cin >> data;
	cout << data;*/
	/*Event data;
	cin >> data;
	cout << data;*/
	Tickets data;
	cin >> data;
	cout << data;
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
	int operatie = 0;
	cin >> operatie;
	cin.get();
	if (operatie == 1) {
		RegisterEvent();
	}
	else if (operatie == 2) {
		//BuyTicket();
	}
}

