#pragma once
#include "Tank.h"


class CanonTank : public Tank
{
private:
public:
	CanonTank();
	virtual void Shot(double xPos, double yPos, double windSpeed, double powerGauge, double angle, bool sawRight, double enemyxpos, double enemyypos);
	~CanonTank();
};

class CanonTankMissile : public Missile
{
private:
public:
	CanonTankMissile(MissileType type, double xPos, double yPos, double xPower, double yPower, double Attack, double Range) : Missile(type, xPos, yPos, xPower, yPower, Attack, Range)
	{
		switch (type)
		{
		case CannonTankMissile1:
			m_tMissile.loadFromFile("images/missile_canon_1.png");
			break;
		case CannonTankMissile2:
			m_tMissile.loadFromFile("images/missile_canon_2.png");
			break;
		default:
			break;
		}

		m_spMissile.setTexture(m_tMissile);
		UpdateMissile();
	}
};