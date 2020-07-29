#include "Framework.h"

cEnemy4::cEnemy4(POINT Pos, int tag, int Angle, EnemyState EnemyState)
	:cEnemy(Pos, tag)
{
	m_EnemyState = EnemyState;

	switch (m_EnemyState)
	{
	case EnemyState::The_Hierophant:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy4_TypeA", "./Images/Ingame/Enemy/TypeA/Ingame_Enemy_4.png");
		break;
	case EnemyState::The_Hermit:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy4_TypeB", "./Images/Ingame/Enemy/TypeB/Ingame_Enemy_4.png");
		break;
	case EnemyState::The_Magician:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy4_TypeC", "./Images/Ingame/Enemy/TypeC/Ingame_Enemy_4.png");
		break;
	case EnemyState::The_Fool:
		m_Sprite = IMAGEMANAGER->AddImage("Enemy4_TypeD", "./Images/Ingame/Enemy/TypeD/Ingame_Enemy_4.png");
	}

	m_MaxHp = 5;
	m_Hp = m_MaxHp;
	m_MaxBullet = 10;
	m_Speed = 350;
	m_AttackSpeed = 0.35f;
	m_GiveScore = 500;
	m_Angle = Angle;
}

cEnemy4::~cEnemy4()
{
}

void cEnemy4::Update()
{
	cEnemy::Update();
	m_Pos.x += m_Speed * cos(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
	m_Pos.y += m_Speed * sin(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
}

void cEnemy4::Attack(list<cGameObject*>* Objects)
{
	for (int i = 0; i < m_MaxBullet; i++)
	{
		(*Objects).push_back(Fire((360 / m_MaxBullet) * i, 1000));
	}
	SOUNDMANAGER->Play("ShootE", SE);
	SOUNDMANAGER->Play("ShootE", SE);
	SOUNDMANAGER->Play("ShootE", SE);
}
