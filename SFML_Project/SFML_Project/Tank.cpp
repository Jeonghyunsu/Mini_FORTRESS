#include "Tank.h"

Tank::Tank()
{
	m_iSelectedMissile = 1;
}

double Tank::GetHP()
{
	return m_dHP;
}

void Tank::SetHP(double bloodDown)
{
	m_dHP -= (bloodDown * ((100 - Get_m_dDeffensivePower()) / 100));
	if (m_dHP <= 0) m_dHP = 0;
}

void Tank::DeleteMissile()
{
	delete m_Missile;
}

Missile* Tank::GetMissile()
{
	return m_Missile;
}

Sprite & Tank::GetSpTank()
{
	return m_spTank;
}

void Tank::SetSelectMissile(int selectMissile)
{
	m_iSelectedMissile = selectMissile;
}

int Tank::GetSelectMissile()
{
	return m_iSelectedMissile;
}

double Tank::Get_m_dOffensivePower()
{
	return m_dOffensivePower;
}

double Tank::Get_m_dDeffensivePower()
{
	return m_dDeffensivePower;
}

Tank::~Tank()
{

}
