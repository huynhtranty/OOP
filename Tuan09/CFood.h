#pragma once
#include "CGoods.h"
class CFood: public CGoods
{
private:
	CDate m_MfgDate;
	CDate m_ExpDate;
public:
	CFood(void);
	void Input();
	void Output();
	CDate getFoodDate();
	void PrintFood();
};

