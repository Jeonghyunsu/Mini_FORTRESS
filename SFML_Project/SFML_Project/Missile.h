#pragma once

#include <SFML/Graphics.hpp>

#define PI 3.141592

using namespace sf;

enum MissileType {
	Missile1 = 1,
	Missile2 = 2,
	CannonTankMissile1 = 1,
	CannonTankMissile2 = 2,
	MissileTankMissile1 = 1,
	MissileTankMissile2 = 2
};

// 추후에 Missile을 base로 하여 상속받는 형태로 구현하는 것을 추천합니다
// ex. class CanonTankMissile1 : public Missile

class Missile
{ 
protected:
	double m_dXpos, m_dYpos, m_dXPower, m_dYPower;
	double m_dAttack;
	double m_dRange;
	Texture m_tMissile;
	Sprite m_spMissile;
public:
	Missile(MissileType type, double xPos, double yPos, double xPower, double yPower, double Attack, double Range);
	virtual void UpdateMissile();
	virtual void NextStep(double windSpeed, double gravity);
	double GetYPos();
	double GetXPos();
	double GetAttack();
	double GetRange();
	Sprite& GetSpMissile();

	~Missile();
};