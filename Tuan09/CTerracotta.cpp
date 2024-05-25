#include "CTerracotta.h"

CTerracotta::CTerracotta(void) {
	m_Code = "";
	m_Name = "";
	m_Producer = "";
	m_Price = 0.0;
	m_NumOfProduct = 0;
	m_Material = "";
}

void CTerracotta::Input() {
	getline(cin, m_Code, '(');
	getline(cin, m_Name, ',');
	getline(cin, m_Producer, ',');
	getline(cin, m_Price, ',');
	getline(cin, m_Material, ',');
	cin >> m_NumOfProduct;
	cin.ignore();
}

void CTerracotta::Output() {
	string c = ",";
	cout << m_Name << c;
	cout << m_Producer << c;
	cout << m_Price << c << " ";
	cout << m_NumOfProduct << ".";
}