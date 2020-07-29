#include "Framework.h"

cBoss_TheHermit::cBoss_TheHermit(POINT Pos, int tag, cPlayer* Player)
	:cBoss(Pos, tag, Player)
{
	m_Sprite = IMAGEMANAGER->AddImage("Boss_TheHermit", "./Images/Ingame/Enemy/Boss/Ingame_Boss_2.png");
	m_Shield = IMAGEMANAGER->AddImage("Boss_TheHermit_Shield", "./Images/Ingame/Enemy/Boss/Ingame_Boss_2_Shield.png");
	m_MaxHp = 6500;
	m_Hp = m_MaxHp;
	m_EnemyState = EnemyState::The_Hermit;
	m_GiveScore = 4500;
	m_Scale = 0;
	b_IsShield = false;

	m_AttackTime.Init();
	m_Heal.Init();
}

cBoss_TheHermit::~cBoss_TheHermit()
{
}

void cBoss_TheHermit::Update()
{
	// 다른 객체와 다른 다소 특이한 판정 범위로 인해 Rect값 설정을 따로 해준다.
	#pragma region SetRect
	LONG Width = m_Sprite->info.Width / 2;
	LONG Height = m_Sprite->info.Height / 2;
	m_Rect = { m_Pos.x - Width + 30, m_Pos.y - Height, m_Pos.x + Width, m_Pos.y + Height - 20 };
	#pragma endregion 

	m_AttackTime.Update();
	m_Heal.Update();

	m_Radius = m_Shield->info.Height / 2 * m_Scale;

	// 보스가 행동 가능한 상태일 때
	if (b_Control)
	{
		// 보스 공격 설정
		if (m_AttackTime.Time(2.5f))
		{
			b_Attack = true;	// 공격 함수 실행
		}
	}

	// 특수 기믹 : 보스의 쉴드 안에 플레이어가 있다면, 
	if (b_IsShield)
	{
		if (RectCircleCrashCheck(m_Pos, m_Radius, m_Player->GetRect()))
		{
			m_Heal.Pause();  // 보스의 회복 정지
		}
		else
		{
			m_Heal.Resume(); // 보스의 회복 재개
		}

		if (m_Heal.Time(3))  // 보스는 3초마다 체력을 10 회복한다.
		{
			m_Hp = (m_Hp + 10 <= m_MaxHp) ? m_Hp + 10 : m_MaxHp;
			m_Heal.Reset();
		}

		// 특수 기믹 : 보스의 체력에 비례하여 쉴드의 크기가 달라진다.
		float t = (float)(m_Hp - 3000) / (float)(m_MaxHp - 3000);
		if (t >= 1)	t = 1;
		if (t <= 0)	t = 0;
		m_Scale = Lerp(1.f, 2.f, t);
	}

	// 특수 기믹 : 보스의 체력이 2000보다 낮다면 보스의 쉴드는 사라진다.
	if (m_Hp <= 2000 && b_IsShield)
	{
		b_IsShield = false;
		m_Scale = 0;
		SOUNDMANAGER->Play("Broken", SE);
	}
}

void cBoss_TheHermit::Render()
{
	m_Shield->CenterRender(m_Pos, m_Scale, 0);
	m_Sprite->CenterRender(m_Pos, m_Angle);
}

bool cBoss_TheHermit::Appear(POINT Pos)
{
	if (m_Pos.x >= Pos.x)
	{
		m_Pos.x -= 2;
		return false;
	}
	if (m_Scale <= 2)
	{
		m_Scale += 0.1f;
		return false;
	}
	b_IsShield = true;
	m_SavePos = m_Pos;
	return true;
}

void cBoss_TheHermit::Attack(list<cGameObject*>* Objects)
{
	static int Temp;	// static으로 변수를 선언하여 함수가 종료되어도 메모리에 남게 한다.

	// 보스의 쉴드 유무에 따라 페이즈가 달라진다
	if (b_IsShield)
	{
		if (!b_Attacking)	// 공격중이 이니라면,
			Temp = Random(1, 4);	// static 변수에 랜덤한 값을 넣는다.
	
		switch (Temp)
		{
		case 1:	b_Attacking = true;	Attack1(Objects);	break;
		case 2:	b_Attacking = true;	Attack2(Objects);	break;
		case 3:	b_Attacking = true;	Attack3(Objects);	break;
		case 4:	b_Attacking = true;	Attack4(Objects);	break;
		}
	}
	else
	{
		if (!b_Attacking)	// 공격중이 이니라면,
			Temp = Random(1, 4);	// static 변수에 랜덤한 값을 넣는다.
	
		switch (Temp)
		{
		case 1:	b_Attacking = true;	PowerAttack1(Objects);	break;
		case 2:	b_Attacking = true;	PowerAttack2(Objects);	break;
		case 3:	b_Attacking = true;	PowerAttack3(Objects);	break;
		case 4:	b_Attacking = true;	PowerAttack4(Objects);	break;
		}
	}

	//b_Attacking = true;	PowerAttack3(Objects);
}

void cBoss_TheHermit::Attack1(list<cGameObject*>* Objects)
{
	int BulletNum = 20;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	POINT Vec = { m_Player->GetPos().x - (m_Pos.x - 100), m_Player->GetPos().y - (m_Pos.y + 120) };
	int Angle = D3DXToDegree(atan2(Vec.y, Vec.x));

	if (timeGetTime() - AttackTime >= 80)
	{
		(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, Angle + 180));
		SOUNDMANAGER->Play("ShootE", SE);
		AttackTime = timeGetTime();
		AttackCount++;
	}

	if (AttackCount == BulletNum)
	{
		b_Attack = false;
		b_Attacking = false;
		AttackCount = 0;
		m_AttackTime.Reset();
	}
}

void cBoss_TheHermit::Attack2(list<cGameObject*>* Objects)
{
	int BulletNum = 15;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	if (timeGetTime() - AttackTime >= 500)
	{
		if (AttackCount == 0)
			for (int i = 0; i < BulletNum; i++)
				(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, (360 / BulletNum) * i, 1000));
		if (AttackCount == 1)
			for (int i = 0; i < BulletNum; i++)
				(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, (360 / BulletNum) * i + (360 / BulletNum) / 2, 2000));

		SOUNDMANAGER->Play("ShootE", SE);
		SOUNDMANAGER->Play("ShootE", SE);
		AttackTime = timeGetTime();
		AttackCount++;
	}

	if (AttackCount == 2)
	{
		AttackCount = 0;
		b_Attack = false;
		b_Attacking = false;
		m_AttackTime.Reset();
	}
}

void cBoss_TheHermit::Attack3(list<cGameObject*>* Objects)
{
	int BulletNum = 8;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();
	static int Direction = 1;

	m_Pos.y += 5 * Direction;

	if (m_Pos.y <= 300)
		Direction = 1;
	else if (m_Pos.y >= WinSizeY - 300)
		Direction = -1;

	if (timeGetTime() - AttackTime >= 350 && AttackCount < BulletNum)
	{
		(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, -20));
		(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, -10));
		(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120));
		(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, 10));
		(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, 20));
		SOUNDMANAGER->Play("ShootE", SE);							
		SOUNDMANAGER->Play("ShootE", SE);							
		SOUNDMANAGER->Play("ShootE", SE);							
		AttackTime = timeGetTime();									
		AttackCount++;
	}


	if (AttackCount == BulletNum)
	{
		if (m_Pos.y == WinSizeY / 2)
		{
			AttackCount = 0;
			b_Attack = false;
			b_Attacking = false;
			m_AttackTime.Reset();
		}
	}
}

void cBoss_TheHermit::Attack4(list<cGameObject*>* Objects)
{
	int BulletNum = 40;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	if (timeGetTime() - AttackTime >= 50)
	{
		(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, -10 + AttackCount));
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

void cBoss_TheHermit::PowerAttack1(list<cGameObject*>* Objects)
{
	int BulletNum = 20;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	POINT Vec = { m_Player->GetPos().x - (m_Pos.x - 100), m_Player->GetPos().y - (m_Pos.y + 120) };
	int Angle = D3DXToDegree(atan2(Vec.y, Vec.x));

	if (timeGetTime() - AttackTime >= 80)
	{
		for (int i = 0; i < 20; i++)
		{
			(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, Angle + 170 + i));
		}
		SOUNDMANAGER->Play("ShootE", SE);
		SOUNDMANAGER->Play("ShootE", SE);
		AttackTime = timeGetTime();
		AttackCount++;
	}

	if (AttackCount == BulletNum)
	{
		b_Attack = false;
		b_Attacking = false;
		AttackCount = 0;
		m_AttackTime.Reset();
	}
}

void cBoss_TheHermit::PowerAttack2(list<cGameObject*>* Objects)
{
	int BulletNum = 20;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();
	
	if (m_Pos.x > WinSizeX / 2 && AttackCount < 8)
	{
		m_Pos.x -= 20;
		return;
	}

	if (timeGetTime() - AttackTime >= 500 && AttackCount < 8)
	{
		if (AttackCount % 2 == 0)
			for (int i = 0; i < BulletNum; i++)
				(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, (360 / BulletNum) * i));
		else
			for (int i = 0; i < BulletNum; i++)
				(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, (360 / BulletNum) * i + (360 / BulletNum) / 2));

		SOUNDMANAGER->Play("ShootE", SE);
		SOUNDMANAGER->Play("ShootE", SE);
		AttackTime = timeGetTime();
		AttackCount++;
	}

	if (AttackCount == 8)
	{
		if (m_Pos.x == m_SavePos.x)
		{
			AttackCount = 0;
			b_Attack = false;
			b_Attacking = false;
			m_AttackTime.Reset();
		}
		else
		{
			m_Pos.x += 10;
		}
	}
}

void cBoss_TheHermit::PowerAttack3(list<cGameObject*>* Objects)
{
	int BulletNum = 15;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();
	static int Direction = 1;

	m_Pos.y += 5 * Direction;

	if (m_Pos.y <= 300)
		Direction = 1;
	else if (m_Pos.y >= WinSizeY - 300)
		Direction = -1;

	if (timeGetTime() - AttackTime >= 350 && AttackCount < 6)
	{
		for (int i = 0; i < BulletNum; i++)
			(*Objects).push_back(Fire(m_Pos.x - 100, m_Pos.y + 120, (360 / BulletNum) * i));
		SOUNDMANAGER->Play("ShootE", SE);
		SOUNDMANAGER->Play("ShootE", SE);
		AttackTime = timeGetTime();
		AttackCount++;
	}


	if (AttackCount == 6)
	{
		if (m_Pos.y == WinSizeY / 2)
		{
			AttackCount = 0;
			b_Attack = false;
			b_Attacking = false;
			m_AttackTime.Reset();
		}
	}
}

void cBoss_TheHermit::PowerAttack4(list<cGameObject*>* Objects)
{
	int BulletNum = 360 * 2;
	static int AttackCount = 0;
	static time_t AttackTime = timeGetTime();

	if (AttackCount < BulletNum)
	{
		if (m_Pos.x > WinSizeX / 2)
		{
			m_Pos.x -= 20;
			return;
		}

		if (timeGetTime() - AttackTime >= 10)
		{
			(*Objects).push_back(Fire(m_Pos.x - 130, m_Pos.y + 120, + AttackCount));
			(*Objects).push_back(Fire(m_Pos.x - 130, m_Pos.y + 120, + AttackCount + 90));
			(*Objects).push_back(Fire(m_Pos.x - 130, m_Pos.y + 120, + AttackCount + 180));
			(*Objects).push_back(Fire(m_Pos.x - 130, m_Pos.y + 120, + AttackCount + 270));
			if (AttackCount % 5 == 0)
				SOUNDMANAGER->Play("ShootE", SE);
			AttackTime = timeGetTime();
			AttackCount++;
		}
	}
	else
	{
		if (m_Pos.x == m_SavePos.x)
		{
			AttackCount = 0;
			b_Attack = false;
			b_Attacking = false;
			m_AttackTime.Reset();
		}
		else
		{
			m_Pos.x += 10;
		}
	}
}

