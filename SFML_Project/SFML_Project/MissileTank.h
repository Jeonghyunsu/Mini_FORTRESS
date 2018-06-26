#pragma once
#include "Tank.h"
#include "Missile.h"

class MissileTank : public Tank
{
private:
public:
	MissileTank();
	virtual void Shot(double xPos, double yPos, double windSpeed, double powerGauge, double angle, bool sawRight, double enemyxpos, double enemyypos);
	~MissileTank();
};

class MissileTankMissile : public Missile
{
private:
	MissileType type;
	int flyingCnt;
	double enemyxpos;
	double enemyypos;
	bool sawRight;
public:
	
	MissileTankMissile(MissileType type, double xPos, double yPos, double xPower, double yPower, double Attack, double Range, double enemyxpos, double enemyypos, bool sawRight) : Missile(type, xPos, yPos, xPower, yPower, Attack, Range)
	{
		switch (type)
		{
		case MissileTankMissile1:
			m_tMissile.loadFromFile("images/missile_missile_1.png");
			break;
		case MissileTankMissile2:
			m_tMissile.loadFromFile("images/missile_missile_2.png");
			break;
		default:
			break;
		}

		this->type = type;
		flyingCnt = 0;
		this->enemyxpos = enemyxpos;
		this->enemyypos = enemyypos;
		this->sawRight = sawRight;
	
		m_spMissile.setTexture(m_tMissile);
		UpdateMissile(0, false);
	}
	
	virtual void UpdateMissile(double angle, bool flag)
	{
		m_spMissile.setRotation(0);
		m_spMissile.setPosition(m_dXpos - (m_tMissile.getSize().x / 2), m_dYpos - (m_tMissile.getSize().y / 2));

		if (flag) {
			if (sawRight)
				m_spMissile.setRotation(angle);
			else
				m_spMissile.setRotation(-angle);
		}
		else {
			if (angle < 90)
			{
				if (sawRight)
					m_spMissile.setRotation(angle);
				else
					m_spMissile.setRotation(-angle);
			}
			else
			{
				if (sawRight)
					m_spMissile.setRotation(90);
				else
					m_spMissile.setRotation(-90);
			}
		}
		
	
	}
	void NextStep(double windSpeed, double gravity)
	{	
		double angle = 0;
		double xlength = m_dXpos - enemyxpos;
		double ylength = m_dYpos - enemyypos;
		double x2y2length = sqrt(xlength*xlength + ylength*ylength);
		
		if (type == MissileTankMissile2) {
			if (flyingCnt < 45) {
				m_dXpos += (m_dXPower - windSpeed) / 4;
				m_dYpos += m_dYPower / 4;
				m_dYPower -= gravity;	

				angle = 0.7 * flyingCnt;
				UpdateMissile(angle, false);
			}
			else {			
				if (xlength < 0) {
					m_dXpos -= 15 * cos(xlength / x2y2length * PI);
					m_dYpos -= 15 * sin(ylength / x2y2length * PI);
					m_dYPower -= gravity;
				}
				else if(xlength > 0){
					m_dXpos += 15 * cos(xlength / x2y2length * PI);	
					m_dYpos -= 15 * sin(ylength / x2y2length * PI);
					m_dYPower -= gravity;
				}
				
				angle = xlength / x2y2length;
				if(!sawRight && angle < 0)UpdateMissile(180 - angle, true);
				else if (sawRight && angle < 0)UpdateMissile(angle, true);
				else if (!sawRight && angle > 0)UpdateMissile(angle, true);
				else if (sawRight && angle > 0)UpdateMissile(180 + angle, true);
			}			
			
		}
		else {
			m_dXpos += (m_dXPower - windSpeed) / 4;
			m_dYpos += m_dYPower / 4;
			m_dYPower -= gravity;
			angle = 0.7 * flyingCnt;
			UpdateMissile(angle, false);
		}
		flyingCnt++;
	}
};

