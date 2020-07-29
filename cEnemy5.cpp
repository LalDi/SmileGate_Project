#include "Framework.h"

cEnemy5::cEnemy5(POINT Pos, int tag, int Angle, EnemyState EnemyState)
	:cEnemy(Pos, tag)
{
	m_EnemyState = EnemyState;

	switch (m_EnemyState)
	{
	case EnemyState::The_Hierophant:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy5_TypeA", "./Images/Ingame/Enemy/TypeA/Ingame_Enemy_5.png");
		break;
	case EnemyState::The_Hermit:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy5_TypeB", "./Images/Ingame/Enemy/TypeB/Ingame_Enemy_5.png");
		break;
	case EnemyState::The_Magician:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy5_TypeC", "./Images/Ingame/Enemy/TypeC/Ingame_Enemy_5.png");
		break;
	case EnemyState::The_Fool:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy5_TypeD", "./Images/Ingame/Enemy/TypeD/Ingame_Enemy_5.png");
	}

	m_MaxHp = 20;
	m_Hp = m_MaxHp;
	m_Speed = 1450;
	m_AttackSpeed = 1;
	m_GiveScore = 500;
	m_Angle = Angle;
}

cEnemy5::~cEnemy5()
{
}

void cEnemy5::Update()
{
	cEnemy::Update();
	m_Pos.x += m_Speed * cos(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
	m_Pos.y += m_Speed * sin(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
}

void cEnemy5::Render()
{
	m_Sprite->CenterRender(m_Pos, m_Scale, m_Angle + 90);
}

void cEnemy5::Attack(list<cGameObject*>* Objects)
{
}
