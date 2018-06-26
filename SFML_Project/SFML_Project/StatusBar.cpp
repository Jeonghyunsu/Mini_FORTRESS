#include "StatusBar.h"
#include "Game.h"
#include <math.h>

StatusBar::StatusBar(Player& m_rPlayer)
{
	SetImg(m_tStatus, m_spStatus, 0, 500, 1, 1, "images/statusbar.png");
	SetImg(m_tPowerGauge, m_spPowerGauge, 210, 555, 0, 1, "images/bar_gauge.png");
	SetImg(m_tHPGauge, m_spHPGauge, 210, 522, 16, 1, "images/bar_gauge.png");
	SetImg(m_tMissile[1], m_spMissile[1], 650, 555, 1, 1, "images/missile_canon_1.png");
	SetImg(m_tMissile[2], m_spMissile[2], 700, 555, 1, 1, "images/missile_canon_2.png");
	SetImg(m_tBomb, m_spBomb, 3000, 3000, 1, 1, "images/bomb.png");
	SetImg(m_tWind, m_spWind, 70, 575, 0, 0, "images/wind_gauge.png");

	m_tDir.loadFromFile("images/missile_selector.png");
	m_spDir.setTexture(m_tDir);
	m_spDir.setPosition(648, 565);
	m_spDir.setScale(0.5, 0.5);

	line[0] = sf::Vertex(sf::Vector2f(70 + 80 * cos(45 * PI / 180) , 570 - 80 * sin(45 * PI / 180)));
	line[0].color = sf::Color::Black;
	line[1] = sf::Vertex(sf::Vector2f(70, 570));
	line[1].color = sf::Color::Black;
}

void StatusBar::SetImg(Texture & t, Sprite & sp, int xpos, int ypos, int xscale, int yscale, char *fileName)
{
	t.loadFromFile(fileName);
	sp.setTexture(t);
	sp.setPosition(xpos, ypos);
	sp.setScale(xscale, yscale);
}

Texture & StatusBar::GettFinal()
{
	return m_tFinal;
}
Sprite & StatusBar::GetSpFinal()
{
	return m_spFinal;
}

Vertex* StatusBar::GetSpLine()
{
	return line;
}

Sprite & StatusBar::GetSpWind()
{
	return m_spWind;
}
Sprite & StatusBar::GetSpBomb()
{
	return m_spBomb;
}


Sprite & StatusBar::GetSpStatus()
{
	return m_spStatus;
}

Sprite & StatusBar::GetSpHPGauge()
{
	return m_spHPGauge;
}

Sprite & StatusBar::GetSpPowerGauge()
{
	return m_spPowerGauge;
}

Sprite & StatusBar::GetSpMissile1()
{
	return m_spMissile[1];
}
Sprite & StatusBar::GetSpMissile2()
{
	return m_spMissile[2];
}
Sprite & StatusBar::GetDir(Player* m_rPlayer)
{
	if (m_rPlayer->GetTank()->GetSelectMissile() == Missile1) m_spDir.setPosition(648, 565);
	else if(m_rPlayer->GetTank()->GetSelectMissile() == Missile2) m_spDir.setPosition(700, 565);

	return m_spDir;
}

void StatusBar::Update(Player & m_rPlayer)
{
	char *img1, *img2;
	if (m_rPlayer.GetPlayerNum() == PLAYER1) {
		m_tMissile[1].loadFromFile("images/missile_canon_1.png");
		m_tMissile[2].loadFromFile("images/missile_canon_2.png");
	}
	else if (m_rPlayer.GetPlayerNum() == PLAYER2) {
		m_tMissile[1].loadFromFile("images/missile_missile_1.png");
		m_tMissile[2].loadFromFile("images/missile_missile_2.png");
	}
	m_spMissile[1].setTexture(m_tMissile[1]);
	m_spMissile[1].setPosition(650, 555);
	m_spMissile[2].setTexture(m_tMissile[2]);
	m_spMissile[2].setPosition(700, 555);

	m_spPowerGauge.setScale(m_rPlayer.GetPowerGauge() / ((double)100 / (double)16), 1);
	if(m_rPlayer.GetHP() > 0) m_spHPGauge.setScale( 16 *  m_rPlayer.GetHP() / 1000, 1);
	else m_spHPGauge.setScale(0, 1);
}


StatusBar::~StatusBar()
{
}
