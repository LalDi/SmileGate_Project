#include "Framework.h"

cEnemy::cEnemy(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
}

cEnemy::~cEnemy()
{
}

void cEnemy::Update()
{
	SetRect();

	if (timeGetTime() - m_FireTime > 1000 / m_AttackSpeed)
	{
		b_Fire = true;
		m_FireTime = timeGetTime();
	}
}

void cEnemy::Render()
{
	m_Sprite->CenterRender(m_Pos);
}

cGameObject* cEnemy::Fire()
{
	cGameObject* Temp;
	POINT Pos = { m_Pos.x - 50, m_Pos.y };
	Temp = new cBullet(Pos, BULLETE, 1, 180);
	b_Fire = false;
	return Temp;
}
