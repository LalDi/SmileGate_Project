#include "Framework.h"

cUI_Background::cUI_Background(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Background", "./Images/Ingame/Ingame_Status_Background.png");
}

cUI_Background::~cUI_Background()
{
}

void cUI_Background::Update()
{

}

void cUI_Background::Render()
{
	m_Sprite->Render(m_Pos);
}
