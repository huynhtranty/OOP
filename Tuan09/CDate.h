#pragma once
#include<fstream>
#include<iostream>
using namespace std;

class CDate
{
private:
	int d, m, y;
public:
	CDate(void);
	CDate(int dc, int mc, int yc) {
		d = dc;
		m = mc;
		y = yc;
	}
	friend istream& operator>>(istream& in, CDate& d);
	friend ostream& operator<<(ostream& ou, const CDate& d);
	bool operator>(CDate d);
};

