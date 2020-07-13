#include "Framework.h"

cUI_Button_Pause_Resume::cUI_Button_Pause_Resume(POINT Pos, int tag, bool* Pause)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Pause_Resume", "./Images/Ingame/UI/Button/Ingame_Button_Resume.png");
	b_IsPause = Pause;
	b_IsCenter = true;
	b_IsOnMouseUp = true;
}

cUI_Button_Pause_Resume::~cUI_Button_Pause_Resume()
{
}

void cUI_Button_Pause_Resume::Update()
{
	cUI_Button::Update();

	if (*b_IsPause == false)
		b_IsLive = false;
}

void cUI_Button_Pause_Resume::Render()
{
	cUI_Button::Render();
}

void cUI_Button_Pause_Resume::ClickButton()
{
	*b_IsPause = false;
}
