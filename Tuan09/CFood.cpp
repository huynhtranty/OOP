#include "CFood.h"
CFood::CFood(void) {
	m_Code = "";
	m_Name = "";
	m_Producer = "";
	m_Price = 0.0;
	m_NumOfProduct = 0;
}

void CFood::Input() {
	getline(cin, m_Code, '(');
	getline(cin, m_Name, ',');
	getline(cin, m_Producer, ',');
	getline(cin, m_Price, ',');
	cin >> m_MfgDate;
	cin.ignore();
	cin >> m_ExpDate;
	cin.ignore();
	cin >> m_NumOfProduct;
	cin.ignore();
}

void CFood::Output() {
	string c = ",";
	cout << m_Name << c;
	cout << m_Producer << c;
	cout << m_Price << c << " ";
	cout << m_NumOfProduct << ".";
}
CDate CFood::getFoodDate() {
	return m_ExpDate;
}
void CFood::PrintFood() {
	string c = ", ";
	string codee = m_Code.substr(0, m_Code.length() - 1);
	cout << codee << c;
	cout << m_Name << c;	
	cout << m_NumOfProduct << c;
	cout << m_ExpDate << ".";
}