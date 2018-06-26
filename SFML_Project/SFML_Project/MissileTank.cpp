#include "MissileTank.h"

MissileTank::MissileTank()
{
	m_tTank.loadFromFile("images/tank_missile.png");
	m_dDeffensivePower = 40;
	m_dOffensivePower = 200;
	m_dHP = 1000;
	m_spTank.setTexture(m_tTank);
}

void MissileTank::Shot(double xPos, double yPos, double windSpeed, double powerGauge, double angle, bool sawRight, double enemyxpos, double enemyypos)
{
	if (sawRight == true) {
		if (GetSelectMissile() == MissileTankMissile1)
			m_Missile = new MissileTankMissile(MissileType::MissileTankMissile1, xPos, yPos, powerGauge * cos(angle * PI / 180), -powerGauge * sin(angle * PI / 180), 1.2, 40, enemyxpos, enemyypos, sawRight);
		else if (GetSelectMissile() == MissileTankMissile2)
			m_Missile = new MissileTankMissile(MissileType::MissileTankMissile2, xPos, yPos, powerGauge * cos(angle * PI / 180), -powerGauge * sin(angle * PI / 180), 0.3, 20, enemyxpos, enemyypos, sawRight);

		m_Missile->GetSpMissile().setScale(1, 1);
	}
	else {
		if (GetSelectMissile() == MissileTankMissile1)
			m_Missile = new MissileTankMissile(MissileType::MissileTankMissile1, xPos, yPos, powerGauge * cos( (180 - angle) * PI / 180), -powerGauge * sin(angle * PI / 180), 1.2, 40, enemyxpos, enemyypos, sawRight);
		else if (GetSelectMissile() == MissileTankMissile2)
			m_Missile = new MissileTankMissile(MissileType::MissileTankMissile2, xPos, yPos, powerGauge * cos( (180 - angle) * PI / 180), -powerGauge * sin(angle * PI / 180), 0.3, 20, enemyxpos, enemyypos, sawRight);

		m_Missile->GetSpMissile().setScale(-1, 1);
	}
}

MissileTank::~MissileTank()
{
}
