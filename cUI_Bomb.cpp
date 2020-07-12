#include "Framework.h"

cUI_Bomb::cUI_Bomb(POINT Pos, int tag, cPlayer* Player)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Bomb", "./Images/Ingame/UI/Icon_bomb.png");

	m_Player = Player;
}

cUI_Bomb::~cUI_Bomb()
{
}

void cUI_Bomb::Update()
{
	m_Bomb = m_Player->GetBomb();
}

void cUI_Bomb::Render()
{
	POINT Pos = m_Pos;
	for (int i = 0; i < m_Bomb; i++)
	{
		Pos.x = m_Pos.x + 60 * i;
		m_Sprite->CenterRender(Pos);
	}
}
