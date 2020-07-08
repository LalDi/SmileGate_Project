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
	if (m_Hp <= 0)
	{
		int item;
		item = rand() % 2;
		if (item == 0)
		{
			item = rand() % 3;
			switch (item)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			}
		}
		b_IsLive = false;
	}
	
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
