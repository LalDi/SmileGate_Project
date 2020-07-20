#include "Framework.h"

cBoss::cBoss(POINT Pos, int tag, cPlayer* Player)
	:cGameObject(Pos, tag)
{
	m_Player = Player;
}

cBoss::~cBoss()
{
}

void cBoss::Render()
{
	m_Sprite->CenterRender(m_Pos);
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
