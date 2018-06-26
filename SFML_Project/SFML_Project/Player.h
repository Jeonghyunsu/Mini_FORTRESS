#pragma once

#include <SFML/Graphics.hpp>
#include "Tank.h"

using namespace sf;

// Item은 추후에 클래스화를 하는 것을 목표로 합니다
enum Item {
	DoubleShot = 1,
	PowerShot = 2
};

enum PLAYER_NUM {
	PLAYER1 = 1,
	PLAYER2 = 2
};

class Player
{
private:
	int m_iPlayerNum;

	Tank *m_Tank; // 플레이어의 탱크
	double m_dHP; // 플레이어의 HP
	double m_dGauge; // 플레이어의 파워 게이지
	double m_dXpos; // x좌표
	double m_dYpos; // y좌표

	bool m_bIsSawRight; // 오른쪽을 보고 있는지 아닌지
	double m_dAngle; // 현재의 각도
	Item m_Items[4]; // 현재 가지고 있는 아이템

	void UpdateTank();
	void SetIsSawRight(bool isSawRight);
public:
	Player(double xPos, double yPos, bool sawRight, int playerNum);

	void MoveTank(double amount);
	double GetPowerGauge();
	void SetAngle(int pAngle);
	double GetAngle();
	double GetXPos();
	double GetYPos();
	bool GetIsSawRight();
	Tank* GetTank();
	void SetPowerGauge(double gauge);
	Sprite& GetSpTank();
	int GetPlayerNum();
	double GetHP();
	void SetHP(double bloodDown);
	~Player();
};

