#include "Framework.h"

cEnemy1::cEnemy1(POINT Pos, int tag, int Angle, EnemyState EnemyState)
	:cEnemy(Pos, tag)
{
	m_EnemyState = EnemyState;

	switch (m_EnemyState)
	{
	case EnemyState::The_Hierophant:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy1_TypeA", "./Images/Ingame/Enemy/TypeA/Ingame_Enemy_1.png");
		break;
	case EnemyState::The_Hermit:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy1_TypeB", "./Images/Ingame/Enemy/TypeB/Ingame_Enemy_1.png");
		break;
	case EnemyState::The_Magician:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy1_TypeC", "./Images/Ingame/Enemy/TypeC/Ingame_Enemy_1.png");
		break;
	case EnemyState::The_Fool:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy1_TypeD", "./Images/Ingame/Enemy/TypeD/Ingame_Enemy_1.png");
	}

	m_MaxHp = 7;
	m_Hp = m_MaxHp;
	m_Speed = 450;
	m_AttackSpeed = 0.65f;
	m_GiveScore = 300;
	m_Angle = Angle;
}

cEnemy1::~cEnemy1()
{
}

void cEnemy1::Update()
{
	cEnemy::Update();
	m_Pos.x += m_Speed * cos(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
	m_Pos.y += m_Speed * sin(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
}

void cEnemy1::Attack(list<cGameObject*> *Objects)
{
	(*Objects).push_back(Fire());
	SOUNDMANAGER->Play("ShootE", 1);
}
