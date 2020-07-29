#include "Framework.h"

cUI_Icon_Speaker::cUI_Icon_Speaker(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Option_Icon_Speaker", "./Images/Option/Option_Icon_Speaker.png");
}

cUI_Icon_Speaker::~cUI_Icon_Speaker()
{
}

void cUI_Icon_Speaker::Update()
{
}

void cUI_Icon_Speaker::Render()
{
	m_Sprite->CenterRender(m_Pos);
}
