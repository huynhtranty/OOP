#pragma once
#include<iostream>
#include<string>

using namespace std;
#include "CDate.h"

class CGoods {
protected:
	string m_Code;
	string m_Name;
	string m_Producer;
	string m_Price;
	int m_NumOfProduct;
public:
	CGoods(void);
	virtual void Input() = 0;
	virtual void Output() = 0;
	string getCode() {
		return this->m_Code;
	}
	void setNumOfProduct(int n) {
		this->m_NumOfProduct -= n;
	}
	string getPrice() {
		return m_Price;
	}
	string getName() {
		return m_Name;
	}
	int getNumOfProduct() {
		return m_NumOfProduct;
	}
};