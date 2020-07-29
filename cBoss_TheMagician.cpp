#include "Framework.h"

cBoss_TheMagician::cBoss_TheMagician(POINT Pos, int tag, cPlayer* Player)
	:cBoss(Pos, tag, Player)
{
	m_Sprite = IMAGEMANAGER->AddImage("Boss_TheMagician", "./Images/Ingame/Enemy/Boss/Ingame_Boss_3.png");
	m_MaxHp = 4500;
	m_Hp = m_MaxHp;
	m_EnemyState = EnemyState::The_Magician;
	m_GiveScore = 8000;

	m_AttackTime.Init();
}

cBoss_TheMagician::~cBoss_TheMagician()
{
}

void cBoss_TheMagician::Update()
{
	SetRect();

	m_AttackTime.Update();

	// 보스가 행동 가능한 상태일 때
	if (b_Control)
	{
		// 보스 공격 설정
		if (m_AttackTime.Time(1.2f))
		{
			b_Attack = true;	// 공격 함수 실행
		}
	}
}

void cBoss_TheMagician::Attack(list<cGameObject*>* Objects)
{
	static int Temp;	// static으로 변수를 선언하여 함수가 종료되어도 메모리에 남게 한다.
	if (!b_Attacking)	// 공격중이 이니라면,
		Temp = Random(1, 7);	// static 변수에 랜덤한 값을 넣는다.

	//switch (Temp)
	//{
	//case 1:	b_Attacking = true;	Attack1(Objects);	break;
	//case 2:	b_Attacking = true;	Attack2(Objects);	break;
	//case 3:	b_Attacking = true;	Attack3(Objects);	break;
	//case 4:	b_Attacking = true;	Attack4(Objects);	break;
	//case 5:	b_Attacking = true;	Attack5(Objects);	break;
	//case 6:	b_Attacking = true;	Attack6(Objects);	break;
	//case 7:	b_Attacking = true;	Attack7(Objects);	break;
	//}

	b_Attacking = true;	Attack3(Objects);
}

void cBoss_TheMagician::Attack1(list<cGameObject*>* Objects)
{
	int BulletNum = 10;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	if (timeGetTime() - AttackTime >= 500)
	{
		int x = Random(0, WinSizeX);
		int y = Random(0, WinSizeY);
		for (int i = 0; i < BulletNum; i++)
			(*Objects).push_back(Fire(x, y, (360 / BulletNum) * i));

		SOUNDMANAGER->Play("ShootE", SE);
		SOUNDMANAGER->Play("ShootE", SE);
		AttackTime = timeGetTime();
		AttackCount++;
	}

	if (AttackCount == 4)
	{
		AttackCount = 0;
		b_Attack = false;
		b_Attacking = false;
		m_AttackTime.Reset();
	}
}

void cBoss_TheMagician::Attack2(list<cGameObject*>* Objects)
{
	int BulletNum = 30;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	POINT Pos;
	POINT Vec;
	int Angle;

	if (timeGetTime() - AttackTime >= 100)
	{
		switch (Random(1, 4))
		{
		case 1:	Pos.x = Random(0, WinSizeX);	Pos.y = 0;			break;
		case 2:	Pos.x = Random(0, WinSizeX);	Pos.y = WinSizeY;	break;
		case 3:	Pos.y = Random(0, WinSizeY);	Pos.x = 0;			break;
		case 4:	Pos.y = Random(0, WinSizeY);	Pos.x = WinSizeX;	break;
		}
		Vec = { Pos.x - m_Player->GetPos().x, Pos.y - m_Player->GetPos().y };
		Angle = D3DXToDegree(atan2(Vec.y, Vec.x));

		(*Objects).push_back(Fire(Pos.x, Pos.y, Angle));

		SOUNDMANAGER->Play("ShootE", SE);
		AttackTime = timeGetTime();
		AttackCount++;
	}

	if (AttackCount == BulletNum)
	{
		AttackCount = 0;
		b_Attack = false;
		b_Attacking = false;
		m_AttackTime.Reset();
	}
}

void cBoss_TheMagician::Attack3(list<cGameObject*>* Objects)
{
	int BulletNum = 15;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	if (timeGetTime() - AttackTime >= 500)
	{
		for (int i = 0; i < BulletNum; i++)
			(*Objects).push_back(Fire(m_Pos.x, m_Pos.y, Random(-90, 90)));

		SOUNDMANAGER->Play("ShootE", SE);
		SOUNDMANAGER->Play("ShootE", SE);
		AttackTime = timeGetTime();
		AttackCount++;
	}

	if (AttackCount == 4)
	{
		AttackCount = 0;
		b_Attack = false;
		b_Attacking = false;
		m_AttackTime.Reset();
	}
}

void cBoss_TheMagician::Attack4(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheMagician::Attack5(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheMagician::Attack6(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheMagician::Attack7(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}
