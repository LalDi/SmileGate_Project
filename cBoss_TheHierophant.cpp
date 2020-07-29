#include "Framework.h"

cBoss_TheHierophant::cBoss_TheHierophant(POINT Pos, int tag, cPlayer* Player)
	:cBoss(Pos, tag, Player)
{
	m_Sprite = IMAGEMANAGER->AddImage("Boss_TheHierophant", "./Images/Ingame/Enemy/Boss/Ingame_Boss_1.png");
	m_MaxHp = 5000;
	m_Hp = m_MaxHp;
	m_EnemyState = EnemyState::The_Hierophant;
	m_GiveScore = 2000;

	m_AttackTime.Init();
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

	m_AttackTime.Update();

	// 보스가 행동 가능한 상태일 때
	if (b_Control)
	{
		// 보스 공격 설정
		if (m_AttackTime.Time(2))
		{
			b_Attack = true;	// 공격 함수 실행
		}
	}
}

void cBoss_TheHierophant::Attack(list<cGameObject*> *Objects)
{
	static int Temp;	// static으로 변수를 선언하여 함수가 종료되어도 메모리에 남게 한다.
	if (!b_Attacking)	// 공격중이 이니라면,
		Temp = Random(1, 7);	// static 변수에 랜덤한 값을 넣는다.
		
	switch (Temp)
	{
	case 1:	b_Attacking = true;	Attack1(Objects);	break;
	case 2:	b_Attacking = true;	Attack2(Objects);	break;
	case 3:	b_Attacking = true;	Attack3(Objects);	break;
	case 4:	b_Attacking = true;	Attack4(Objects);	break;
	case 5:	b_Attacking = true;	Attack5(Objects);	break;
	case 6:	b_Attacking = true;	Attack6(Objects);	break;
	case 7:	b_Attacking = true;	Attack7(Objects);	break;
	}

	//b_Attacking = true;	Attack7(Objects);
}

void cBoss_TheHierophant::Attack1(list<cGameObject*> *Objects)
{
	int Temp = Random(3, 5);
	POINT Pos;
	POINT Vec;
	int Angle;

	for (int i = 0; i < Temp; i++)
	{
		int Temp2 = Random(1, 4);
		Pos.x = m_Pos.x + Random(-300, 300);
		Pos.y = m_Pos.y + Random(-400, 400);

		Vec = { m_Player->GetPos().x - Pos.x, m_Player->GetPos().y - Pos.y };
		Angle = D3DXToDegree(atan2(Vec.y, Vec.x));

		switch (Temp2)
		{
		case 1: (*Objects).push_back(new cEnemy1(Pos, ENEMY, Angle,		EnemyState::The_Hierophant));	break;
		case 2:	(*Objects).push_back(new cEnemy2(Pos, ENEMY, m_Player,	EnemyState::The_Hierophant));	break;
		case 3:	(*Objects).push_back(new cEnemy3(Pos, ENEMY, Angle,		EnemyState::The_Hierophant));	break;
		case 4:	(*Objects).push_back(new cEnemy4(Pos, ENEMY, Angle,		EnemyState::The_Hierophant));	break;
		}
	}
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheHierophant::Attack2(list<cGameObject*> *Objects)
{
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();
	int BulletNum = 40;

	if (timeGetTime() - AttackTime >= 50)
	{
		(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, AttackCount++ * (360 / BulletNum) * 2));
		SOUNDMANAGER->Play("ShootE", SE);
		AttackTime = timeGetTime();
	}

	if (AttackCount > BulletNum)
	{
		AttackCount = 0;
		b_Attack = false;
		b_Attacking = false;
		m_AttackTime.Reset();
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

void cBoss_TheHierophant::Attack4(list<cGameObject*>* Objects)
{
	int BulletNum = 20;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	POINT Vec = { m_Player->GetPos().x - (m_Pos.x - 50), m_Player->GetPos().y - (m_Pos.y - 120) };
	int Angle = D3DXToDegree(atan2(Vec.y, Vec.x));

	if (timeGetTime() - AttackTime >= 100)
	{
		(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, Angle + 160, 1250));
		(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, Angle + 180, 1250));
		(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, Angle + 200, 1250));
		SOUNDMANAGER->Play("ShootE", SE);
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

void cBoss_TheHierophant::Attack5(list<cGameObject*>* Objects)
{
	int BulletNum = 10;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	if (timeGetTime() - AttackTime >= 50)
	{
		for (int i = 0; i < BulletNum; i++)
		{
			(*Objects).push_back(Fire(m_Pos.x - 70, m_Pos.y - 130, AttackCount + (360 / BulletNum) * i, 750));
		}
		SOUNDMANAGER->Play("ShootE", SE);
		AttackCount += 8;
		AttackTime = timeGetTime();
	}

	if (AttackCount > 180)
	{
		AttackCount = 0;
		b_Attack = false;
		b_Attacking = false;
		m_AttackTime.Reset();
	}
}

void cBoss_TheHierophant::Attack6(list<cGameObject*>* Objects)
{
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	if (timeGetTime() - AttackTime >= 100)
	{
		switch (AttackCount)
		{
		case 0:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, 0, 800));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 1:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 1000));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 1000));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 2:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 1300));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 1300));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 3:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 1600));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 1600));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 4:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 1900));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 1900));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 5:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 2100));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 2100));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 6:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 2400));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 2400));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 7:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 2700));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 2700));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 8:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 3000));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 3000));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 9:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 3300));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 3300));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 10:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 3600));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 3600));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 11:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 3900));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 3900));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		case 12:
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, -AttackCount * 8, 4200));
			(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, +AttackCount * 8, 4200));
			SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
			break;
		default:
			AttackCount = 0;
			b_Attack = false;
			b_Attacking = false;
			m_AttackTime.Reset();
			break;
		}
	}
}

void cBoss_TheHierophant::Attack7(list<cGameObject*>* Objects)
{
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	if (timeGetTime() - AttackTime >= 1000)
	{
		for (int i = 0; i < 360; i++)
		{
			switch (AttackCount)
			{
			case 0:
				if (!(i >= 0 && i < 35))
					(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, i, 1000));
				break;
			case 1:
				if (!(i >= 340 || i <= 5))
					(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, i, 1000));
				break;
			case 2:
				if (!(i >= 0 && i <= 30))
					(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, i, 1000));
				break;
			case 3:
				if (!(i >= 320 && i <= 350))
					(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, i, 1000));
				break;
			case 4:
				if (!(i >= 345 || i <= 15))
					(*Objects).push_back(Fire(m_Pos.x - 50, m_Pos.y - 120, i, 1000));
				break;
			}
		}
		SOUNDMANAGER->Play("ShootE", SE);
		SOUNDMANAGER->Play("ShootE", SE);
		AttackCount++;
		AttackTime = timeGetTime();
	}

	if (AttackCount == 5)
	{
		AttackCount = 0;
		b_Attack = false;
		b_Attacking = false;
		m_AttackTime.Reset();
	}
}
