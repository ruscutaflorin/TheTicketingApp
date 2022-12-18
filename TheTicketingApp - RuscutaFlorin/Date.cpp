#include "Date.h"


Date::Date(const int& d, const int& m, const int& y) {
	day_ = d;
	month_ = m;
	year_ = y;
}

Date::Date() { year_ = 0; month_ = 0; day_ = 0; }

int Date::day() const { return day_; }
int Date::month() const { return month_; }
int Date::year() const { return year_; }

void Date::setDay(const int& day) {
	Date::day_ = day;
}

void Date::setMonth(const int& month) {
	Date::month_ = month;
};

void Date::setYear(const int& year) {
	Date::year_ = year;
};

bool Date::isValid() const {
	if (year_ < 0) return false;
	if (month_ > 12 || month_ < 1) return false;
	if (day_ > 31 || day_ < 1) return false;
	if ((day_ == 31 &&
		(month_ == 2 || month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)))
		return false;
	if (day_ == 30 && month_ == 2) return false;
	return true;
}


bool operator == (const Date& d1, const Date& d2) {
	// check for equality
	if (!d1.isValid()) { return false; };
	if (!d2.isValid()) { return false; };
	if ((d1.day() == d2.day())
		&& (d1.month() == d2.month())
		&& (d1.year() == d2.year())) {
		return true;
	};
	return false;
}

bool operator !=(const Date& d1, const Date& d2) {
	return !(d1 == d2);
}

bool operator < (const Date& d1, const Date& d2) {
	if (!d1.isValid()) { return false; } // not meaningful, return anything
	if (!d2.isValid()) { return false; } // should really be an exception, but ?
	if (d1.year() < d2.year()) { return true; }
	else if (d1.year() > d2.year()) { return false; }
	else { // same year
		if (d1.month() < d2.month()) { return true; }
		else if (d1.month() > d2.month()) { return false; }
		else { // same month
			if (d1.day() < d2.day()) { return true; }
			else { return false; }
		}
	}
	return false;
}

bool operator > (const Date& d1, const Date& d2) {
	if (d1 == d2) { return false; } // this is strict inequality
	if (d1 < d2) { return false; }
	return true;
}

bool operator <=(const Date& d1, const Date& d2) {
	if (d1 == d2) { return true; }
	return (d1 < d2);
}

bool operator >=(const Date& d1, const Date& d2) {
	if (d1 == d2) { return true; }
	return (d1 > d2);
}

inline Date next_date(const Date& d) {
	Date ndat;
	if (!d.isValid()) { return ndat; }
	ndat = Date((d.day() + 1), d.month(), d.year()); if (ndat.isValid()) return ndat;
	ndat = Date(1, (d.month() + 1), d.year()); if (ndat.isValid()) return ndat;
	ndat = Date(1, 1, (d.year() + 1)); return ndat;
}
inline Date previous_date(const Date& d) {
	Date ndat;
	if (!d.isValid()) { return ndat; }; // return zero
	ndat = Date((d.day() - 1), d.month(), d.year()); if (ndat.isValid()) return ndat;
	ndat = Date(31, (d.month() - 1), d.year()); if (ndat.isValid()) return ndat;
	ndat = Date(30, (d.month() - 1), d.year()); if (ndat.isValid()) return ndat;
	ndat = Date(29, (d.month() - 1), d.year()); if (ndat.isValid()) return ndat;
	ndat = Date(28, (d.month() - 1), d.year()); if (ndat.isValid()) return ndat;
	ndat = Date(31, 12, (d.year() - 1)); return ndat;
};
Date Date::operator ++(int) { // postfix operator
	Date d = *this;
	*this = next_date(d);
	return d;
}
Date Date::operator ++() { // prefix operator
	*this = next_date(*this);
	return *this;
}
Date Date::operator --(int) { // postfix operator, return current value
	Date d = *this;
	*this = previous_date(*this);
	return d;
}
Date Date::operator --() { // prefix operator, return new value
	*this = previous_date(*this);
	return *this;
};
inline long long_date(const Date& d) {
	if (d.isValid()) { return d.year() * 10000 + d.month() * 100 + d.day(); };
	return 0;
};
ostream& operator << (ostream& os, const Date& d) {
	if (d.isValid() > 0) { os << " " << long_date(d) << " "; }
	else { os << " invalid date "; };
	return os;
}
