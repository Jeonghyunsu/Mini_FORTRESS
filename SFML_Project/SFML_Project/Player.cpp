#include "Player.h"
#include "Map.h"
#include "CanonTank.h"
#include "MissileTank.h"

Player::Player(double xPos, double yPos, bool sawRight, int playerNum)
{
	switch (playerNum)
	{
	case PLAYER1:
		m_Tank = new CanonTank();
		break;
	case PLAYER2:
		m_Tank = new MissileTank();
		break;
	}

	m_iPlayerNum = playerNum;
	m_dHP = m_Tank->GetHP();
	m_dXpos = xPos;
	m_dYpos = yPos;
	m_bIsSawRight = sawRight;
	m_dGauge = 0;

	m_dAngle = 45;

	UpdateTank();
}

void Player::UpdateTank()
{
	if (m_bIsSawRight == true) {
		m_Tank->GetSpTank().setScale(-1, 1);
		m_Tank->GetSpTank().setPosition(m_dXpos + (m_Tank->GetSpTank().getTexture()->getSize().x / 2), m_dYpos - (m_Tank->GetSpTank().getTexture()->getSize().y / 2));
		
	}
	else {
		m_Tank->GetSpTank().setScale(1, 1);
		m_Tank->GetSpTank().setPosition(m_dXpos - (m_Tank->GetSpTank().getTexture()->getSize().x / 2), m_dYpos - (m_Tank->GetSpTank().getTexture()->getSize().y / 2));
	}
}

void Player::SetIsSawRight(bool isSawRight)
{
	m_bIsSawRight = isSawRight;
	UpdateTank();
}

void Player::MoveTank(double amount)
{
	if (amount > 0) {
		SetIsSawRight(true);
		if (m_dXpos < Map::GetMapWidth()-20) {
			m_dXpos += amount;
		}
	}
	else if (amount < 0) {
		SetIsSawRight(false);
		if (m_dXpos > 20) {
			m_dXpos += amount;
		}
	}

	UpdateTank();
}

double Player::GetPowerGauge()
{
	return m_dGauge;
}

void Player::SetAngle(int pAngle)
{
	if(pAngle > 0 && m_dAngle < 60)
		m_dAngle += pAngle;
	else if(pAngle < 0 && m_dAngle > 30)
		m_dAngle += pAngle;
}

double Player::GetAngle()
{
	return m_dAngle;
}

double Player::GetXPos()
{
	return m_dXpos;
}

double Player::GetYPos()
{
	return m_dYpos;
}

bool Player::GetIsSawRight()
{
	return m_bIsSawRight;
}

Tank* Player::GetTank()
{
	return m_Tank;
}

void Player::SetPowerGauge(double gauge)
{
	m_dGauge = gauge;
}

Sprite & Player::GetSpTank()
{
	return m_Tank->GetSpTank();
}

double Player::GetHP()
{
	return m_dHP;
}

void Player::SetHP(double bloodDown)
{
	m_Tank->SetHP(bloodDown);
	m_dHP = m_Tank->GetHP();
}

Player::~Player()
{
	delete m_Tank;
}

int Player::GetPlayerNum()
{
	return m_iPlayerNum;
}