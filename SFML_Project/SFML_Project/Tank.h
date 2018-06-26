#pragma once
#include <SFML/Graphics.hpp>
#include "Missile.h"
using namespace sf;

class Tank
{
protected:
	Texture m_tTank;
	Sprite m_spTank;
	Missile* m_Missile;
	double m_dDeffensivePower;
	double m_dOffensivePower;
	double m_dHP;

	int m_iSelectedMissile; // 선택된 미사일
public:
	Tank();
	double GetHP();
	void SetHP(double bloodDown);
	virtual void Shot(double xPos, double yPos, double windSpeed, double powerGauge, double angle, bool sawRight, double enemyxpos, double enemyypos) = 0;
	void DeleteMissile();
	Missile* GetMissile();
	Sprite &GetSpTank();
	void SetSelectMissile(int selectMissile);
	int GetSelectMissile();
	double Get_m_dOffensivePower();
	double Get_m_dDeffensivePower();
	virtual ~Tank();
};