#pragma once

#include "StatusBar.h"
#include "Player.h"
#include "Map.h"

#define PI 3.141592

class Game
{
private:
	double m_dWindSpeed; // �ٶ��� ���� (���� : ����, ��� : ������)
	Player *m_curPlayer;
	Player *m_Player1, *m_Player2;
	Map *m_Map;
	StatusBar *m_StatusBar;
	bool m_bIsShotting; // ���� �̻����� ��� �ִ���
	bool m_bIsPressingSpace; // �����̽��� ������ �Ŀ� �������� �ö󰡰� �ִ���
	bool m_bplayingGame;
	bool m_bBombFlag;

public:
	Game();
	
	Player* GetPlayer1();
	Player* GetPlayer2();
	Player* GetCurPlayer();
	Map* GetMap();
	StatusBar* GetStatus();

	void PressSpace();
	void ChangeTurn();
	void Shot();
	bool GetIsShotting();
	bool GetIsPressingSpace();
	void UpPowerGauge(double amount);
	void MissileFlying();

	bool GetisPlayingGame();
	bool GetisBombFlag();
	void SetBombFlag(bool flag);
	void EraseBombImg();
	void SetWindSpeed(double wind);
	double GetWindSpeed();
	void ChangWind();
	void ChangeAngle();

	~Game();
};