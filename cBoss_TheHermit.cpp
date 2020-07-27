#include "Framework.h"

cBoss_TheHermit::cBoss_TheHermit(POINT Pos, int tag, cPlayer* Player)
	:cBoss(Pos, tag, Player)
{
	m_Sprite = IMAGEMANAGER->AddImage("Boss_TheHermit", "./Images/Ingame/Enemy/Boss/Ingame_Boss_2.png");
	m_MaxHp = 8500;
	m_Hp = m_MaxHp;
	m_EnemyState = EnemyState::The_Hermit;
	m_GiveScore = 4500;

	m_AttackTime.Init();
}

cBoss_TheHermit::~cBoss_TheHermit()
{
}

void cBoss_TheHermit::Update()
{
	// �ٸ� ��ü�� �ٸ� �ټ� Ư���� ���� ������ ���� Rect�� ������ ���� ���ش�.
	#pragma region SetRect
	LONG Width = m_Sprite->info.Width * m_Scale / 2;
	LONG Height = m_Sprite->info.Height * m_Scale / 2;
	m_Rect = { m_Pos.x - Width, m_Pos.y - Height, m_Pos.x + Width, m_Pos.y + Height - 20 };
	#pragma endregion 

	m_AttackTime.Update();

	// ������ �ൿ ������ ������ ��
	if (b_Control)
	{
		// ���� ���� ����
		if (m_AttackTime.Time(2.5f))
		{
			b_Attack = true;	// ���� �Լ� ����
		}
	}
}

void cBoss_TheHermit::Attack(list<cGameObject*>* Objects)
{
	static int Temp;	// static���� ������ �����Ͽ� �Լ��� ����Ǿ �޸𸮿� ���� �Ѵ�.
	if (!b_Attacking)	// �������� �̴϶��,
		Temp = Random(1, 7);	// static ������ ������ ���� �ִ´�.

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

void cBoss_TheHermit::Attack1(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheHermit::Attack2(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheHermit::Attack3(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheHermit::Attack4(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheHermit::Attack5(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheHermit::Attack6(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheHermit::Attack7(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}
