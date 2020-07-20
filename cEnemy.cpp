#include "Framework.h"

/**
	@fn		cEnemy(POINT, int)

	@brief	���ʹ��� �⺻���� ����� ���� Ŭ����

	@param	Pos		- ������Ʈ�� �����Ǵ� ��ġ
	@param	tag		- ������Ʈ�� ����� �����ϴ� �±�.
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
	if (CheckOutMap())
	{
		b_IsLive = false;
	}
}

void cEnemy::Render()
{
	m_Sprite->CenterRender(m_Pos, m_Scale, 0);
}

/**
	@fn		Fire()

	@brief	���ʹ̰� �߻��ϴ� �Ѿ��� �����͸� ���� �Լ�
	@remark	�Ѿ��� ���ʹ̺��� ��¦ �տ� �����Ͽ� �� �����͸� ��ȯ�ϴ� �Լ�
*/
cGameObject* cEnemy::Fire(int Angle, float Speed)
{
	cGameObject* Temp;
	POINT Pos = { m_Pos.x - 50, m_Pos.y };
	Temp = new cBullet(Pos, BULLETE, 1, 180 + Angle, Speed);
	b_Fire = false;
	return Temp;
}

bool cEnemy::CheckOutMap()	
{
	bool temp;
	int x, y;
	x = m_Sprite->info.Width;
	y = m_Sprite->info.Height;
	temp = m_Pos.x < -x || m_Pos.x > WinSizeX + x || m_Pos.y < -y || m_Pos.y > WinSizeY + y;
	return temp;
}