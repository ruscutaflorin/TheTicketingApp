#include "Tickets.h"

Tickets::Tickets() {
	types = nullptr;
	price = nullptr;
	ticketDistribution = nullptr;
	typesNumber = 0;
	srand(time(0));
	uniqueID = rand();
}

Tickets::Tickets(const unsigned int typesNumber, const string* types, const int* ticketDistribution, const int* price, Event eventObject) :Tickets() {
	if (typesNumber > 0 && types != nullptr && price != nullptr) {
		this->types = new string[typesNumber];
		this->price = new int[typesNumber];
		this->ticketDistribution = new int[typesNumber];
		for (int i = 0; i < typesNumber; ++i) {
			this->types[i] = types[i];
			this->price[i] = price[i];
			this->ticketDistribution[i] = ticketDistribution[i];
		}
		this->typesNumber = typesNumber;
	}
	eventDetails = eventObject;
}

Tickets::Tickets(const Tickets& object) {
	if (object.typesNumber > 0 && object.types != nullptr && object.price != nullptr && ticketDistribution != nullptr) {
		types = new string[object.typesNumber];
		price = new int[object.typesNumber];
		ticketDistribution = new int[object.typesNumber];
		for (int i = 0; i < object.typesNumber; ++i) {
			types[i] = object.types[i];
			price[i] = object.price[i];
			ticketDistribution[i] = object.ticketDistribution[i];

		}
		typesNumber = object.typesNumber;
		eventDetails = object.eventDetails;
	}
	else {
		types = nullptr;
		price = nullptr;
		ticketDistribution = nullptr;
		typesNumber = 0;
	}
}

Tickets& Tickets::operator=(const Tickets& object) {
	if (this != &object) {
		if (object.typesNumber > 0 && object.types != nullptr && object.price != nullptr && object.ticketDistribution != nullptr) {
			if (types != nullptr) {
				delete[] types;
				typesNumber = 0;
			}
			if (price != nullptr) {
				delete[] price;
				typesNumber = 0;
			}

			if (ticketDistribution != nullptr) {
				delete[] ticketDistribution;
				typesNumber = 0;
			}

			types = new string[object.typesNumber];
			price = new int[object.typesNumber];
			ticketDistribution = new int[object.typesNumber];

			for (int i = 0; i < object.typesNumber; ++i) {
				types[i] = object.types[i];
				price[i] = object.price[i];
				ticketDistribution[i] = object.ticketDistribution[i];
			}
			typesNumber = object.typesNumber;
			eventDetails = object.eventDetails;
		}
		else {
			types = nullptr;
			price = nullptr;
			ticketDistribution = nullptr;
			typesNumber = 0;
		}
	}
	return *this;
}


Tickets::~Tickets() {
	if (types != nullptr) {
		delete[] types;
	}
	if (price != nullptr) {
		delete[] price;
	}
	if (ticketDistribution != nullptr) {
		delete[] ticketDistribution;
	}
	typesNumber = 0;
}

unsigned int Tickets::getTypesNumber() {
	return typesNumber;
}

string* Tickets::getTypes() {
	if (types != nullptr && typesNumber > 0) {
		string* copy = new string[typesNumber];
		for (int i = 0; i < typesNumber; ++i) {
			copy[i] = types[i];
		}
		return copy;
	}
	return nullptr;
}

int* Tickets::getPrice() {
	if (price != nullptr && typesNumber > 0) {
		int* copy = new int[typesNumber];
		for (int i = 0; i < typesNumber; ++i) {
			copy[i] = price[i];
		}
		return copy;
	}
	return nullptr;
}

unsigned int Tickets::getUniqueID() {
	return uniqueID;
}

int* Tickets::getTicketDistribution() {
	if (ticketDistribution != nullptr && typesNumber > 0) {
		int* copy = new int[typesNumber];
		for (int i = 0; i < typesNumber; ++i) {
			copy[i] = ticketDistribution[i];
		}
		return copy;
	}
	return nullptr;
}

void Tickets::setTypesPriceAndDistribution(const string* types, const int* price, const int* ticketDistribution, const unsigned int nr) {
	if (types != nullptr && price != nullptr && ticketDistribution != nullptr && nr > 0) {
		if (this->types != nullptr) {
			delete[] this->types;
			this->typesNumber = 0;
		}
		if (this->price != nullptr) {
			delete[] this->price;
			this->typesNumber = 0;
		}
		if (this->ticketDistribution != nullptr) {
			delete[] this->ticketDistribution;
			this->typesNumber = 0;
		}
		this->types = new string[typesNumber];
		this->price = new int[typesNumber];
		this->ticketDistribution = new int[typesNumber];
		for (int i = 0; i < typesNumber; ++i) {
			this->types[i] = types[i];
			this->price[i] = price[i];
			this->ticketDistribution[i] = ticketDistribution[i];
		}
		this->typesNumber = nr;
	}
}

int Tickets::revenueAfterOneEvent() {
	if (typesNumber > 0) {
		int sum = 0;
		for (int i = 0; i < typesNumber; ++i) {
			sum += price[i] * ticketDistribution[i];
		}
		return sum;
	}
	return 0;
}

int Tickets::maxRevenueAfterAllEvents(Tickets* obj, int nr) {
	if (obj != nullptr && nr > 0) {
		int sum = 0;
		for (int i = 0; i < nr; ++i) {
			sum += obj[i].revenueAfterOneEvent();
		}
		return sum;
	}
	return 0;
}

int Tickets::operator[](const string ticketType) {
	if (typesNumber > 0 && types != nullptr) {
		for (int i = 0; i < typesNumber; ++i) {
			if (ticketType == types[i])
				return price[i];
		}
	}
	return 0;
}
//Tickets a;
// int* x = (int*)a => preturile la bilete ale obiectului a.
explicit  Tickets::operator int* () {
	if (price != nullptr && typesNumber > 0) {
		int* copy = new int[typesNumber];
		for (int i = 0; i < typesNumber; ++i) {
			copy[i] = price[i];
		}
		return copy;
	}
	return nullptr;
}


ostream& operator<<(ostream& out, Tickets obj)
{
	out << obj.eventDetails;
	if (obj.typesNumber > 0) {
		out << endl << "There are " << obj.typesNumber << " ticket types.";
		for (int i = 0; i < obj.typesNumber; ++i) {
			out << obj.types[i] << " " << obj.ticketDistribution[i] << " Tickets, Price: " << obj.price[i] << endl;
		}
	}
	return out;
}

istream& operator>>(istream& in, Tickets& obj)
{
	int typesNr;
	in >> obj.eventDetails;
	cout << "How many ticket types you wanna sell? " << endl;
	in >> typesNr;
	if (typesNr > 0) {
		obj.typesNumber = typesNr;
		obj.types = new string[typesNr];
		obj.price = new int[typesNr];
		obj.ticketDistribution = new int[typesNr];
		for (int i = 0; i < typesNr; ++i) {
			cout << endl << "Introduce the ticket name: ";
			getline(in, obj.types[i]);
			cout << endl << "Introduce the number of tickets: ";
			in >> obj.ticketDistribution[i];
			cout << endl << "Introduce the ticket price: ";
			in >> obj.price[i];
		}
	}
	return in;
}

