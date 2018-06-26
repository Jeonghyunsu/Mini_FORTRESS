#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

#define PI 3.141592

using namespace sf;

class StatusBar
{
private:
	Sprite m_spStatus;
	Sprite m_spHPGauge;
	Sprite m_spPowerGauge;
	Sprite m_spAngleGauge;
	Sprite m_spWindGauge;

	Sprite m_spItems[4];
	Sprite m_spMissile[3];
	Sprite m_spDir;
	Sprite m_spBomb;
	Sprite m_spWind;

	Texture m_tStatus;
	Texture m_tHPGauge;
	Texture m_tPowerGauge;
	Texture m_tAngleGauge;
	Texture m_tWindGauge;

	Texture m_tItems[4];
	Texture m_tMissile[3];
	Texture m_tDir;
	Texture m_tBomb;
	Texture m_tWind;

	Vertex line[2];
	Sprite m_spLine;

	Sprite m_spFinal;
	Texture m_tFinal;


public:
	StatusBar(Player& m_rPlayer);
	void SetImg(Texture & t, Sprite & sp, int xpos, int ypos, int xscale, int yscale, char *fileName);
	Sprite &GetSpStatus();
	Sprite &GetSpHPGauge();
	Sprite &GetSpPowerGauge();
	Sprite & GetSpMissile1();
	Sprite & GetSpMissile2();
	Sprite & GetDir(Player* m_rPlayer);
	Sprite & GetSpBomb();
	Sprite & GetSpWind();
	Vertex* GetSpLine();
	Sprite & GetSpFinal();
	Texture & GettFinal();
	void Update(Player& m_rPlayer);
	~StatusBar();
};

