#include "Framework.h"

/**
	@fn		cEnemy(POINT, int)

	@brief	에너미의 기본적인 기능을 담은 클래스

	@param	Pos		- 오브젝트가 생성되는 위치
	@param	tag		- 오브젝트의 기능을 구분하는 태그.
*/
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
	m_Sprite->CenterRender(m_Pos, m_Scale, 0);
}

/**
	@fn		Fire()

	@brief	에너미가 발사하는 총알의 데이터를 담은 함수
	@remark	총알을 에너미보다 살짝 앞에 생성하여 그 데이터를 반환하는 함수
*/
cGameObject* cEnemy::Fire(int Angle)
{
	cGameObject* Temp;
	POINT Pos = { m_Pos.x - 50, m_Pos.y };
	Temp = new cBullet(Pos, BULLETE, 1, 180 + Angle);
	b_Fire = false;
	return Temp;
}