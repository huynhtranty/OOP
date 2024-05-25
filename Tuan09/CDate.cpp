#include "CDate.h"
CDate::CDate() {
	d = y = m = 0;
}

istream& operator>>(istream& in, CDate& d) {
	char c;
	in >> d.d >> c >> d.m >> c >> d.y;
	return in;
}

ostream& operator<<(ostream& ou, const CDate& d) {
	char c = '/';
	ou << d.d << c << d.m << c << d.y;
	return ou;
}
bool CDate::operator>(CDate date) {
	if (y < date.y) {
		return 0;
	}
	if (y > date.y) {
		return 1;
	}
	if (m < date.m) {
		return 0;
	}
	if (m > date.m) {
		return 1;
	}
	if (d < date.d) {
		return 0;
	}
	if (d > date.d) {
		return 1;
	}
	return 1; 
}