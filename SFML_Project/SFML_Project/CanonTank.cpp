#include "CanonTank.h"

CanonTank::CanonTank()
{
	m_tTank.loadFromFile("images/tank_canon.png");
	m_dDeffensivePower = 30;
	m_dOffensivePower = 300;
	m_dHP = 1000;
	m_spTank.setTexture(m_tTank);
}

void CanonTank::Shot(double xPos, double yPos, double windSpeed, double powerGauge, double angle, bool sawRight, double enemyxpos, double enemyypos)
{
	if (sawRight == true) {
		if(GetSelectMissile() == CannonTankMissile1)
			m_Missile = new CanonTankMissile(MissileType::CannonTankMissile1, xPos, yPos, powerGauge * cos(angle * PI / 180), -powerGauge * sin(angle * PI / 180), 0.6, 100);
		else if(GetSelectMissile() == CannonTankMissile2)
			m_Missile = new CanonTankMissile(MissileType::CannonTankMissile2, xPos, yPos, powerGauge * cos(angle * PI / 180), -powerGauge * sin(angle * PI / 180), 2, 20);

	}
	else {
		if (GetSelectMissile() == CannonTankMissile1)
			m_Missile = new CanonTankMissile(MissileType::CannonTankMissile1, xPos, yPos, powerGauge * cos((180 - angle) * PI / 180), -powerGauge * sin(angle * PI / 180), 0.6, 100);
		else if (GetSelectMissile() == CannonTankMissile2)
			m_Missile = new CanonTankMissile(MissileType::CannonTankMissile2, xPos, yPos, powerGauge * cos((180 - angle) * PI / 180), -powerGauge * sin(angle * PI / 180), 2, 20);
	}
}

CanonTank::~CanonTank()
{
}
