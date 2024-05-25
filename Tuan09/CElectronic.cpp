#include "CElectronic.h"

CElectronic::CElectronic(void) {
	m_Code = "";
	m_Name = "";
	m_Producer = "";
	m_Price = 0.0;
	m_Warranty = "";
	m_ElectricPower = "";
	m_NumOfProduct = 0;
}

void CElectronic::Input() {
	getline(cin, m_Code, '(');
	getline(cin, m_Name, ',');
	getline(cin, m_Producer, ',');
	getline(cin, m_Price, ',');
	getline(cin, m_Warranty, ',');
	getline(cin, m_ElectricPower, ',');
	cin >> m_NumOfProduct;
	cin.ignore();
}

void CElectronic::Output() {
	string c = ",";
	cout << m_Name << c;
	cout << m_Producer << c;
	cout << m_Price << c << " ";
	cout << m_NumOfProduct << ".";
}