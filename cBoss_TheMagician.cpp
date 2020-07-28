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

	// ������ �ൿ ������ ������ ��
	if (b_Control)
	{
		// ���� ���� ����
		if (m_AttackTime.Time(1))
		{
			b_Attack = true;	// ���� �Լ� ����
		}
	}
}

void cBoss_TheMagician::Attack(list<cGameObject*>* Objects)
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

void cBoss_TheMagician::Attack1(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheMagician::Attack2(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
}

void cBoss_TheMagician::Attack3(list<cGameObject*>* Objects)
{
	b_Attack = false;
	b_Attacking = false;
	m_AttackTime.Reset();
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
