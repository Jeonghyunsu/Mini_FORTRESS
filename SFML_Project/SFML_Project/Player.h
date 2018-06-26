#pragma once

#include <SFML/Graphics.hpp>
#include "Tank.h"

using namespace sf;

// Item�� ���Ŀ� Ŭ����ȭ�� �ϴ� ���� ��ǥ�� �մϴ�
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

	Tank *m_Tank; // �÷��̾��� ��ũ
	double m_dHP; // �÷��̾��� HP
	double m_dGauge; // �÷��̾��� �Ŀ� ������
	double m_dXpos; // x��ǥ
	double m_dYpos; // y��ǥ

	bool m_bIsSawRight; // �������� ���� �ִ��� �ƴ���
	double m_dAngle; // ������ ����
	Item m_Items[4]; // ���� ������ �ִ� ������

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

