#include "Game.h"
#include "Headers.h"
#include<iostream>
#include <ctime>

Game::Game()
{
	m_Player1 = new Player(120, 390, true, 1);
	m_Player2 = new Player(680, 390, false, 2);
	m_curPlayer = m_Player1;
	m_Map = new Map(MapName::SkyBridge);
	m_StatusBar = new StatusBar(*m_curPlayer);
	m_bIsShotting = false;
	m_bIsPressingSpace = false;
	m_dWindSpeed = 0;
	m_bplayingGame = true;
	m_bBombFlag = false;
}

bool Game::GetisBombFlag()
{
	return m_bBombFlag;
}

void Game::SetBombFlag(bool flag)
{
	m_bBombFlag = flag;

}

void Game::EraseBombImg()
{
	m_StatusBar->GetSpBomb().setPosition(3000, 3000);
}

bool Game::GetisPlayingGame()
{
	return m_bplayingGame;
}

Player * Game::GetPlayer1()
{
	int a[3];
	int * b = a;
	
	return m_Player1;
}

Player * Game::GetPlayer2()
{
	return m_Player2;
}

Player * Game::GetCurPlayer()
{
	return m_curPlayer;
}

Map * Game::GetMap()
{
	return m_Map;
}

StatusBar * Game::GetStatus()
{
	return m_StatusBar;
}

void Game::PressSpace()
{
	if (m_bIsPressingSpace == false) {
		m_bIsPressingSpace = true;
	}
	else {
		m_bIsPressingSpace = false;
		Shot();
		m_bIsShotting = true;
	}
}

void Game::ChangeTurn()
{
	m_StatusBar->Update(*m_curPlayer);

	if (m_curPlayer->GetHP() <= 0)
	{
		
		m_bplayingGame = false;
		if(m_curPlayer->GetPlayerNum() == 1)m_StatusBar->GettFinal().loadFromFile("images/2pwin.png");
		else if (m_curPlayer->GetPlayerNum() == 2)m_StatusBar->GettFinal().loadFromFile("images/1pwin.png");

		m_StatusBar->GetSpFinal().setTexture(m_StatusBar->GettFinal());
		m_StatusBar->GetSpFinal().setPosition(250, 100);
	}

	if (m_curPlayer == m_Player1) {	
		m_curPlayer = m_Player2;
	}
	else {
		m_curPlayer = m_Player1;
	}

	if (m_curPlayer->GetHP() <= 0)
	{
		m_bplayingGame = false;

		if (m_curPlayer->GetPlayerNum() == 1)m_StatusBar->GettFinal().loadFromFile("images/2pwin.png");
		else if (m_curPlayer->GetPlayerNum() == 2)m_StatusBar->GettFinal().loadFromFile("images/1pwin.png");

		m_StatusBar->GetSpFinal().setTexture(m_StatusBar->GettFinal());
		m_StatusBar->GetSpFinal().setPosition(250, 100);
	}

	m_curPlayer->SetPowerGauge(0);
	
	printf("1P : %.2lf\n", m_Player1->GetHP());
	printf("2P : %.2lf\n\n", m_Player2->GetHP());
}

void Game::UpPowerGauge(double amount)
{
	if (m_curPlayer->GetPowerGauge() < 100) {
		m_curPlayer->SetPowerGauge(m_curPlayer->GetPowerGauge() + amount);
		m_StatusBar->Update(*m_curPlayer);
	}
	else {
		m_bIsPressingSpace = false;
		Shot();
		m_bIsShotting = true;
	}
}

void Game::MissileFlying()
{
	if (m_curPlayer->GetTank()->GetMissile()->GetYPos() <= m_curPlayer->GetYPos()) {
		m_curPlayer->GetTank()->GetMissile()->NextStep(m_dWindSpeed, -1);
	}
	else {
		
		Player* enemyPlayer;
		
		if (m_curPlayer->GetPlayerNum() == 1) enemyPlayer = GetPlayer2();
		else if (m_curPlayer->GetPlayerNum() == 2)enemyPlayer = GetPlayer1();
		
		double bloodDown = m_curPlayer->GetTank()->GetMissile()->GetAttack() * m_curPlayer->GetTank()->Get_m_dOffensivePower();
		double range = m_curPlayer->GetTank()->GetMissile()->GetRange();

		double missilePos = m_curPlayer->GetTank()->GetMissile()->GetXPos();
		double enemyPos = enemyPlayer->GetXPos();
		double myPos = m_curPlayer->GetXPos();

		if (missilePos >= enemyPos && missilePos <= enemyPos + 40)
			enemyPlayer->SetHP(bloodDown);
		else if (missilePos < enemyPos && abs(missilePos - enemyPos) <= range)
			enemyPlayer->SetHP(bloodDown *(100 - (range - abs(missilePos - enemyPos))) / 100);
		else if (missilePos > enemyPos && abs(missilePos - enemyPos + 40) <= range)
			enemyPlayer->SetHP(bloodDown *(100 - (range - abs(missilePos - enemyPos + 40))) / 100);

		if (missilePos >= myPos && missilePos <= myPos + 40)
			m_curPlayer->SetHP(bloodDown);
		else if (missilePos < myPos && abs(missilePos - myPos) <= range)
			m_curPlayer->SetHP(bloodDown *(100 - (range - abs(missilePos - myPos))) / 100);
		else if (missilePos > myPos && abs(missilePos - myPos + 40) <= range)
			m_curPlayer->SetHP(bloodDown *(100 - (range - abs(missilePos - myPos + 40))) / 100);

		m_StatusBar->GetSpBomb().setScale(range / 100, range / 100);
		m_StatusBar->GetSpBomb().setPosition(m_curPlayer->GetTank()->GetMissile()->GetXPos() - (100 * range / 100), m_curPlayer->GetTank()->GetMissile()->GetYPos() - (40 * range / 100));
		m_bBombFlag = true;

		m_bIsShotting = false;
		m_curPlayer->GetTank()->DeleteMissile();
		ChangeTurn();
	}
}


void Game::Shot()
{
	Player* enemyPlayer;
	if (m_curPlayer->GetPlayerNum() == 1) enemyPlayer = GetPlayer2();
	else if (m_curPlayer->GetPlayerNum() == 2)enemyPlayer = GetPlayer1();

	m_curPlayer->GetTank()->Shot(m_curPlayer->GetXPos(), m_curPlayer->GetYPos(), m_dWindSpeed, m_curPlayer->GetPowerGauge(), m_curPlayer->GetAngle(), m_curPlayer->GetIsSawRight(), enemyPlayer->GetXPos(), enemyPlayer->GetYPos());
	m_bIsShotting = true;
}

bool Game::GetIsShotting()
{
	return m_bIsShotting;
}

bool Game::GetIsPressingSpace()
{
	return m_bIsPressingSpace;
}

void Game::SetWindSpeed(double wind)
{
	m_dWindSpeed = wind;
}

double Game::GetWindSpeed()
{
	return m_dWindSpeed;
}

void Game::ChangWind()
{
	srand((unsigned int)time(NULL));
	SetWindSpeed((double)(rand() % 41 - 20));
	GetStatus()->GetSpWind().setScale(-GetWindSpeed()*0.45, 1);
}

void Game::ChangeAngle()
{
	Vertex* vertex = m_StatusBar->GetSpLine();
	if (m_curPlayer->GetIsSawRight())
		vertex[0] = sf::Vertex(sf::Vector2f(70 + 80 * cos(m_curPlayer->GetAngle()* PI / 180), 570 - 80 * sin(m_curPlayer->GetAngle() * PI / 180)));
	else
		vertex[0] = sf::Vertex(sf::Vector2f(70 - 80 * cos(m_curPlayer->GetAngle()* PI / 180), 570 - 80 * sin(m_curPlayer->GetAngle() * PI / 180)));
}

Game::~Game()
{
	delete m_Player1;
	delete m_Player2;
	delete m_Map;
	delete m_StatusBar;
}
