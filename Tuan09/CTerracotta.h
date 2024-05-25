#pragma once
#include "CGoods.h"
class CTerracotta: public CGoods
{
private:
	string m_Material;
public:
	CTerracotta(void);
	void Input();
	void Output();
};

