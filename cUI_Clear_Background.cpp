#include "Framework.h"

cUI_Clear_Background::cUI_Clear_Background(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Clear_Background", "./Images/Clear/GameClear_BackGround.png");
}

cUI_Clear_Background::~cUI_Clear_Background()
{
}

void cUI_Clear_Background::Update()
{
}

void cUI_Clear_Background::Render()
{
	m_Sprite->Render(m_Pos);
}
