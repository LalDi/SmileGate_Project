#include "Framework.h"

cEnemy3::cEnemy3(POINT Pos, int tag, int Angle, EnemyState EnemyState)
	:cEnemy(Pos, tag)
{
	m_EnemyState = EnemyState;

	switch (m_EnemyState)
	{
	case EnemyState::The_Hierophant:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy3_TypeA", "./Images/Ingame/Enemy/TypeA/Ingame_Enemy_3.png");
		break;
	case EnemyState::The_Hermit:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy3_TypeB", "./Images/Ingame/Enemy/TypeB/Ingame_Enemy_3.png");
		break;
	case EnemyState::The_Magician:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy3_TypeC", "./Images/Ingame/Enemy/TypeC/Ingame_Enemy_3.png");
		break;
	case EnemyState::The_Fool:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy3_TypeD", "./Images/Ingame/Enemy/TypeD/Ingame_Enemy_3.png");
	}

	m_MaxHp = 5;
	m_Hp = m_MaxHp;
	m_Speed = 450;
	m_AttackSpeed = 0.75f;
	m_GiveScore = 650;
	m_Angle = Angle;
	m_Rotate = Angle + 180;
}

cEnemy3::~cEnemy3()
{
}

void cEnemy3::Update()
{
	cEnemy::Update();
	m_Pos.x += m_Speed * cos(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
	m_Pos.y += m_Speed * sin(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
	m_Rotate += 3;
}

void cEnemy3::Render()
{
	m_Sprite->CenterRender(m_Pos, m_Scale, m_Rotate);
}

void cEnemy3::Attack(list<cGameObject*>* Objects)
{
	(*Objects).push_back(Fire(m_Rotate - 15));
	(*Objects).push_back(Fire(m_Rotate));
	(*Objects).push_back(Fire(m_Rotate + 15));
	SOUNDMANAGER->Play("ShootE", 1);
	SOUNDMANAGER->Play("ShootE", 1);
}
