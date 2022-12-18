#pragma once
#include <iostream>
#include <stdlib.h>     
#include <time.h>   

#include "Date.h"
#include "Event.h"

using namespace std;


//enum TicketType {
//	VIP, General, Invitation, Giveaway
//};

/// <summary>
/// de facut o cls cu mostenire
/// cls cu mostenire ticketsForSale
/// caracteristicilor dorite (ex: VIP, peluză, tribună, loje, etc.) + rand/loc
/// qr-code
/// </summary>

// afisare bilete disponibile matrice binara.


//mostenire biletVIP

class Tickets
{
private:
	Event eventDetails;
	//string* spectatorsName;
	string* types;
	int* price;
	unsigned int typesNumber;
	unsigned long long uniqueID;
	//static long long soldTickets;

public:
	Tickets() {
		types = nullptr;
		price = nullptr;
		typesNumber = 0;
		//spectatorsName = nullptr;
		srand(time(0));
		uniqueID = rand();
	}

	Tickets(const unsigned int typesNumber, const string* types, const int* price, Event eventObject) :Tickets() {
		if (typesNumber > 0 && types != nullptr && price != nullptr) {
			this->types = new string[typesNumber];
			this->price = new int[typesNumber];
			for (int i = 0; i < typesNumber; ++i) {
				this->types[i] = types[i];
				this->price[i] = price[i];
			}
			this->typesNumber = typesNumber;
		}
		eventDetails = eventObject;
	}

	Tickets(const Tickets& object) {
		if (object.typesNumber > 0 && object.types != nullptr && object.price != nullptr) {
			types = new string[object.typesNumber];
			price = new int[object.typesNumber];
			for (int i = 0; i < object.typesNumber; ++i) {
				types[i] = object.types[i];
				price[i] = object.price[i];
			}
			typesNumber = object.typesNumber;
			eventDetails = object.eventDetails;
		}
		else {
			types = nullptr;
			price = nullptr;
			typesNumber = 0;
		}
	}

	Tickets& operator=(const Tickets& object) {
		if (this != &object) {
			if (object.typesNumber > 0 && object.types != nullptr && object.price != nullptr) {
				if (types != nullptr) {
					delete[] types;
					typesNumber = 0;
				}
				if (price != nullptr) {
					delete[] price;
					typesNumber = 0;
				}

				types = new string[object.typesNumber];
				price = new int[object.typesNumber];

				for (int i = 0; i < object.typesNumber; ++i) {
					types[i] = object.types[i];
					price[i] = object.price[i];
				}
				typesNumber = object.typesNumber;
				eventDetails = object.eventDetails;
			}
			else {
				types = nullptr;
				price = nullptr;
				typesNumber = 0;
			}
		}
		return *this;
	}


	~Tickets() {
		if (types != nullptr) {
			delete[] types;
		}
		if (price != nullptr) {
			delete[] price;
		}
		typesNumber = 0;
	}

};



//long long Tickets::soldTickets = 0;
