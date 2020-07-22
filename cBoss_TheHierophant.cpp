#include "Framework.h"

cBoss_TheHierophant::cBoss_TheHierophant(POINT Pos, int tag, cPlayer* Player)
	:cBoss(Pos, tag, Player)
{
	m_Sprite = IMAGEMANAGER->AddImage("Boss_TheHierophant", "./Images/Ingame/Enemy/Boss/Ingame_Boss_1.png");
	m_MaxHp = 5000;
	m_Hp = m_MaxHp;
	m_EnemyState = EnemyState::The_Hierophant;
	m_GiveScore = 2000;
}

cBoss_TheHierophant::~cBoss_TheHierophant()
{
}

void cBoss_TheHierophant::Update()
{
	// 다른 객체와 다른 다소 특이한 판정 범위로 인해 Rect값 설정을 따로 해준다.
	#pragma region SetRect
	LONG Width = m_Sprite->info.Width * m_Scale / 2;
	LONG Height = m_Sprite->info.Height * m_Scale / 2;
	m_Rect = { m_Pos.x - Width + 100, m_Pos.y - Height, m_Pos.x + Width - 95, m_Pos.y + Height - 50 };
	#pragma endregion 

	// m_Vec = { m_Player->GetPos().x - m_Pos.x, m_Player->GetPos().y - m_Pos.y };
	// m_Angle = D3DXToDegree(atan2(m_Vec.y, m_Vec.x));

	// 보스가 행동 가능한 상태일 때
	if (b_Control)
	{
		// 보스 공격 설정
		// (현재 시간) - (마지막 공격 시간) > 딜레이(초 * 1000)
		if (timeGetTime() - m_AttackTime > 2000)
		{
			b_Attack = true;	// 공격 함수 실행
		}
	}

}

void cBoss_TheHierophant::Attack(list<cGameObject*> *Objects)
{
	static int Temp;
	if (!b_Attacking)
		Temp = Random(1, 3);
		
	switch (Temp)
	{
	case 1:	b_Attacking = true;	Attack1(Objects);	break;
	case 2:	b_Attacking = true;	Attack2(Objects);	break;
	case 3:	b_Attacking = true;	Attack3(Objects);	break;
	}
}

void cBoss_TheHierophant::Attack1(list<cGameObject*> *Objects)
{
	int Temp = Random(3, 5);
	POINT Pos;
	POINT Vec;
	int Angle;

	for (int i = 0; i < Temp; i++)
	{
		Temp = Random(1, 4);
		Pos.x = m_Pos.x + Random(-300, 300);
		Pos.y = m_Pos.y + Random(-400, 400);

		Vec = { m_Player->GetPos().x - Pos.x, m_Player->GetPos().y - Pos.y };
		Angle = D3DXToDegree(atan2(Vec.y, Vec.x));

		switch (Temp)
		{
		case 1: (*Objects).push_back(new cEnemy1(Pos, ENEMY, Angle,		EnemyState::The_Hierophant));	break;
		case 2:	(*Objects).push_back(new cEnemy2(Pos, ENEMY, m_Player,	EnemyState::The_Hierophant));	break;
		case 3:	(*Objects).push_back(new cEnemy3(Pos, ENEMY, Angle,		EnemyState::The_Hierophant));	break;
		case 4:	(*Objects).push_back(new cEnemy4(Pos, ENEMY, Angle,		EnemyState::The_Hierophant));	break;
		}
	}
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime = timeGetTime();	// 마지막 공격 시간에 현재 시간 대입
}

void cBoss_TheHierophant::Attack2(list<cGameObject*> *Objects)
{
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();
	int BulletNum = 40;

	if (timeGetTime() - AttackTime >= 50)
	{
		(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, AttackCount++ * (360 / BulletNum) * 2));
		AttackTime = timeGetTime();
	}

	if (AttackCount > BulletNum)
	{
		AttackCount = 0;
		b_Attack = false;
		b_Attacking = false;
		m_AttackTime = timeGetTime();	// 마지막 공격 시간에 현재 시간 대입
	}
}

void cBoss_TheHierophant::Attack3(list<cGameObject*> *Objects)
{
	int BulletNum = 15;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	if (timeGetTime() - AttackTime >= 500)
	{
		if (AttackCount % 2 == 0)
			for (int i = 0; i < BulletNum; i++)
				(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, (360 / BulletNum) * i, 700));
		else
			for (int i = 0; i < BulletNum; i++)
				(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, (360 / BulletNum) * i + (360 / BulletNum) / 2, 700));

		AttackTime = timeGetTime();
		AttackCount++;
	}

	if (AttackCount == 4)
	{
		AttackCount = 0;
		b_Attack = false;
		b_Attacking = false;
		m_AttackTime = timeGetTime();	// 마지막 공격 시간에 현재 시간 대입
	}
}
