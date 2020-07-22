#include "Framework.h"

cUI_ChangeCard::cUI_ChangeCard(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_BlackScene", "./Images/Ingame/Ingame_BlackScene.png");
}

cUI_ChangeCard::~cUI_ChangeCard()
{
}

void cUI_ChangeCard::Update()
{
}

void cUI_ChangeCard::Render()
{
	m_Sprite->Render(m_Pos, m_Scale, 0, D3DCOLOR_RGBA(255, 255, 255, 100));
}
