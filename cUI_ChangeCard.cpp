#include "Framework.h"

cUI_ChangeCard::cUI_ChangeCard(POINT Pos, int tag, cPlayer* Player)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_BlackScene", "./Images/Ingame/Ingame_BlackScene.png");
	m_Player = Player;
}

cUI_ChangeCard::~cUI_ChangeCard()
{
}

void cUI_ChangeCard::Update()
{
	if (m_Player->GetIsChange() == false)
		b_IsLive = false;
}

void cUI_ChangeCard::Render()
{
	m_Sprite->Render(m_Pos, m_Scale, 0, D3DCOLOR_RGBA(255, 255, 255, 100));
}
