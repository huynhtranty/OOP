#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;
#include "CDate.h"
#include "CGoods.h"
#include "CTerracotta.h"
#include "CFood.h"
#include "CElectronic.h"

class CSuperMarket
{
private:
	vector<CGoods*> SuperMarket;
private:
	CDate getDate() {
		auto now = std::chrono::system_clock::now();

		std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

		std::tm* now_tm = std::localtime(&now_time_t);

		int year = now_tm->tm_year + 1900;
		int month = now_tm->tm_mon + 1;
		int dayy = now_tm->tm_mday;
		CDate expDate(dayy, month, year);
		return expDate;
	}
private:
	static string ToTalMoney(float n, string price) {
		int p = stoi(price);
		float res = n * p;
		// change to long long
		long long ress = res * 1;
		
		return to_string(ress);
	}
	static string sumTwoString(string a, string b) {
		long long aa = stoi(a);
		long long bb = stoi(b);
		long long res = aa + bb;
		return to_string(res);
	}
	static bool checkTotal(string total) {
		long long t = stoi(total);
		if (t > 5000000) {
			return true;
		}
		return false;
	}
public:
	void Input();
	void Output();
	void ViewExpDate();
	void Delete();
	void Buy();
	void ViewQuantity();
};

