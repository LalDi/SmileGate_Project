#include "Framework.h"

cEnemy1::cEnemy1(POINT Pos, int tag)
	:cEnemy(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Enemy1", "./Images/Ingame/Enemy/Ingame_Enemy.png");

	m_MaxHp = 5;
	m_Hp = m_MaxHp;
	m_Speed = 200;
	m_AttackSpeed = 0.25f;
	m_Scale = 0.5;
}

cEnemy1::~cEnemy1()
{
}

void cEnemy1::Update()
{
	cEnemy::Update();
}

void cEnemy1::Render()
{
	cEnemy::Render();
}

void cEnemy1::Attack(list<cGameObject*> *Objects)
{
	(*Objects).push_back(Fire());
}
