#include "Missile.h"

Missile::Missile(MissileType type, double xPos, double yPos, double xPower, double yPower, double Attack, double Range)
{
	m_dXPower = xPower;
	m_dYPower = yPower;
	m_dXpos = xPos;
	m_dYpos = yPos;
	m_dAttack = Attack;
	m_dRange = Range;
}

void Missile::UpdateMissile()
{
	m_spMissile.setPosition(m_dXpos - (m_tMissile.getSize().x / 2), m_dYpos - (m_tMissile.getSize().y / 2));
}

void Missile::NextStep(double windSpeed, double gravity)
{
	m_dXpos += (m_dXPower - windSpeed) / 4;
	m_dYpos += m_dYPower / 4;
	m_dYPower -= gravity;
	UpdateMissile();
}

double Missile::GetYPos()
{
	return m_dYpos;
}

double Missile::GetXPos()
{
	return m_dXpos;

}
Sprite & Missile::GetSpMissile()
{
	return m_spMissile;
}

double Missile::GetAttack()
{
	return m_dAttack;
}
double Missile::GetRange()
{
	return m_dRange;
}

Missile::~Missile()
{
}
