
#include <iostream>
using namespace std;

class Date
{
	//friend class Event;

protected:
	int year_;
	int month_;
	int day_;
public:
	Date();
	Date(const int& day, const int& month, const int& year);

	void setDay(const int& day);
	void setMonth(const int& month);
	void setYear(const int& year);

	bool isValid(void) const;

	int day() const;
	int month() const;
	int year() const;

	// prefix
	Date operator ++();
	Date operator --();
	// postfix
	Date operator ++(int);
	Date operator --(int);

	//friend ostream& operator<<(ostream& out, Date a);
};

bool operator == (const Date&, const Date&); // comparison operators
bool operator != (const Date&, const Date&);
bool operator < (const Date&, const Date&);
bool operator > (const Date&, const Date&);
bool operator <= (const Date&, const Date&);
bool operator >= (const Date&, const Date&);

