#pragma once
#include "CGoods.h"
class CElectronic: public CGoods
{
private:
	string m_Warranty;
	string m_ElectricPower;
public:
	CElectronic(void);
	//float getElectricPower();
	void Input();
	void Output();
};

