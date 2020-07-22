#include "Framework.h"

cEnemy2::cEnemy2(POINT Pos, int tag, cPlayer* Player, EnemyState EnemyState)
	:cEnemy(Pos, tag)
{
	m_EnemyState = EnemyState;

	switch (m_EnemyState)
	{
	case EnemyState::The_Hierophant:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy2_TypeA", "./Images/Ingame/Enemy/TypeA/Ingame_Enemy_2.png");
		break;
	case EnemyState::The_Hermit:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy2_TypeB", "./Images/Ingame/Enemy/TypeB/Ingame_Enemy_2.png");
		break;
	case EnemyState::The_Magician:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy2_TypeC", "./Images/Ingame/Enemy/TypeC/Ingame_Enemy_2.png");
		break;
	case EnemyState::The_Fool:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy2_TypeD", "./Images/Ingame/Enemy/TypeD/Ingame_Enemy_2.png");
	}

	m_MaxHp = 12;
	m_Hp = m_MaxHp;
	m_Speed = 200;
	m_AttackSpeed = 0.3f;
	m_GiveScore = 400;
	m_Player = Player;
}

cEnemy2::~cEnemy2()
{
}

void cEnemy2::Update()
{
	cEnemy::Update();
	POINT Pos = m_Player->GetPos();
	//POINT Vector = { Pos.x - m_Pos.x, Pos.y - m_Pos.y };
	POINT Vector = { m_Pos.x - Pos.x, m_Pos.y - Pos.y };
	m_Angle = D3DXToDegree(atan2(Vector.y, Vector.x));

	m_Pos.x -= m_Speed * DXUTGetElapsedTime();
}

void cEnemy2::Attack(list<cGameObject*>* Objects)
{
	(*Objects).push_back(Fire(m_Angle, 1000));
}
