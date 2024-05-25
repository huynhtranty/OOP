#include<iostream>
#include<fstream>
#include <chrono>
#include <ctime>

using namespace std;
#include "CSuperMarket.h"
int main() {
	CSuperMarket sup;
	cin.clear();
	freopen("INPUT.TXT", "rt", stdin);
	sup.Input();
	sup.Output();
	//sup.ViewExpDate();
	//sup.Delete();
	//sup.Output();
	sup.Buy();
	sup.Output();
	//sup.ViewQuantity();
	return 0;
}