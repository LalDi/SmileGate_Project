#include "Framework.h"

cEnemy1::cEnemy1(POINT Pos, int tag)
	:cEnemy(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Enemy1", "./Images/Ingame/Ingame_Enemy.png");

	m_MaxHp = 5;
	m_Hp = m_MaxHp;
	m_Speed = 200;
	m_AttackSpeed = 1.5f;
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
