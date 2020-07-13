#include "Framework.h"

cUI_Pause_Background::cUI_Pause_Background(POINT Pos, int tag, bool* Pause)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Pause_Background", "./Images/Ingame/UI/Ingame_Pause_Background.png");
	b_IsPause = Pause;
}

cUI_Pause_Background::~cUI_Pause_Background()
{
}

void cUI_Pause_Background::Update()
{
	if (*b_IsPause == false)
		b_IsLive = false;
}

void cUI_Pause_Background::Render()
{
	m_Sprite->Render(m_Pos);
}
