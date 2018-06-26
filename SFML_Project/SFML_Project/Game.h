#pragma once

#include "StatusBar.h"
#include "Player.h"
#include "Map.h"

#define PI 3.141592

class Game
{
private:
	double m_dWindSpeed; // 바람의 세기 (음수 : 왼쪽, 양수 : 오른쪽)
	Player *m_curPlayer;
	Player *m_Player1, *m_Player2;
	Map *m_Map;
	StatusBar *m_StatusBar;
	bool m_bIsShotting; // 지금 미사일을 쏘고 있는지
	bool m_bIsPressingSpace; // 스페이스를 눌러서 파워 게이지가 올라가고 있는지
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