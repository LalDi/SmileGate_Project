#include "Framework.h"

cBoss::cBoss(POINT Pos, int tag, cPlayer* Player)
	:cGameObject(Pos, tag)
{
	m_Player = Player;
	b_Attack = false;
	b_Attacking = false;
	m_Angle = 0;

	m_AttackTime.Init();
}

cBoss::~cBoss()
{
}

void cBoss::Render()
{
	m_Sprite->CenterRender(m_Pos, m_Angle);
}

cGameObject* cBoss::Fire(int x, int y, int Angle, float Speed)
{
	cGameObject* Temp;
	POINT Pos = { x, y };
	Temp = new cBullet(Pos, BULLETE, 1, 180 + Angle, Speed);
	return Temp;
}

bool cBoss::Appear(POINT Pos)
{
	if (m_Pos.x >= Pos.x)
	{
		m_Pos.x -= 2;
		return false;
	}
	return true;
}

bool cBoss::DisAppear()
{
	if (m_Pos.y <= WinSizeY + m_Sprite->info.Height / 2)
	{
		m_Pos.y += 3;
		if (m_Angle >= -90)
			m_Angle -= 0.1f;
		return false;
	}
	return true;
}

void cBoss::Pause(bool Pause)
{
	if (Pause)
		m_AttackTime.Pause();
	else
		m_AttackTime.Resume();
}
