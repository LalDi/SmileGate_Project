#include "Framework.h"

cUI_PlayerHp::cUI_PlayerHp(POINT Pos, int tag, cPlayer* Player)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Hp", "./Images/Ingame/Icon_Hp.png");
	m_Player = Player;
}

cUI_PlayerHp::~cUI_PlayerHp()
{
}

void cUI_PlayerHp::Update()
{
	m_Hp = m_Player->GetHp();
	m_MaxHp = m_Player->GetMaxHp();
}

void cUI_PlayerHp::Render()
{
	POINT Pos = m_Pos;
	for (int i = 0; i < m_Hp; i++)
	{
		m_Sprite->Render(Pos);
		Pos.x += 55;
	}
}
