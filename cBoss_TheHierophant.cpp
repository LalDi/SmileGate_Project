#include "Framework.h"

cBoss_TheHierophant::cBoss_TheHierophant(POINT Pos, int tag, cPlayer* Player)
	:cBoss(Pos, tag, Player)
{
	m_Sprite = IMAGEMANAGER->AddImage("Boss_TheHierophant", "./Images/Ingame/Enemy/Boss/Ingame_Boss_1.png");
	m_MaxHp = 500;
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

	POINT Vec = { m_Player->GetPos().x - m_Pos.x, m_Player->GetPos().y - m_Pos.y };
	m_Angle = D3DXToDegree(atan2(Vec.y, Vec.x));
}

void cBoss_TheHierophant::Attack(list<cGameObject*>* Objects)
{
	int Temp = Random(1, 3);
	switch (Temp)
	{
	case 1:	Attack1(Objects);	break;
	case 2:	Attack2(Objects);	break;
	case 3:	Attack3(Objects);	break;
	}
}

void cBoss_TheHierophant::Attack1(list<cGameObject*>* Objects)
{
	int Temp = Random(3, 5);
	POINT Pos;
	POINT Vec;
	int Angle;
	for (int i = 0; i < Temp; i++)
	{
		Temp = Random(1, 5);
		Pos.x = m_Pos.x + Random(-300, 300);
		Pos.y = m_Pos.y + Random(-400, 400);

		Vec = { m_Player->GetPos().x - Pos.x, m_Player->GetPos().y - Pos.y };
		Angle = D3DXToDegree(atan2(Vec.y, Vec.x));

		switch (Temp)
		{
		case 1: (*Objects).push_back(new cEnemy1(Pos, ENEMY, Angle, EnemyState::The_Hierophant));	break;
		case 2:	(*Objects).push_back(new cEnemy1(Pos, ENEMY, Angle, EnemyState::The_Hierophant));	break;
		case 3:	(*Objects).push_back(new cEnemy1(Pos, ENEMY, Angle, EnemyState::The_Hierophant));	break;
		case 4:	(*Objects).push_back(new cEnemy1(Pos, ENEMY, Angle, EnemyState::The_Hierophant));	break;
		case 5:	(*Objects).push_back(new cEnemy1(Pos, ENEMY, Angle, EnemyState::The_Hierophant));	break;
		}
	}
}

void cBoss_TheHierophant::Attack2(list<cGameObject*>* Objects)
{
	(*Objects).push_back(Fire(m_Pos.x - 130, m_Pos.y - 105));
}

void cBoss_TheHierophant::Attack3(list<cGameObject*>* Objects)
{
}
