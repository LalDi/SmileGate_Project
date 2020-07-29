#include "Framework.h"

cUI_Hit::cUI_Hit(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Hit", "./Images/Ingame/Ingame_Hit.png");
	m_Timer.Init();
}

cUI_Hit::~cUI_Hit()
{
}

void cUI_Hit::Update()
{
	m_Timer.Update();
	if (m_Timer.Time(2))
	{
		b_IsLive = false;
	}
}

void cUI_Hit::Render()
{
	m_Sprite->Render(m_Pos);
}
