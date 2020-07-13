#include "Framework.h"

cUI_Button_Pause_Reset::cUI_Button_Pause_Reset(POINT Pos, int tag, bool* Pause)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Pause_Reset", "./Images/Ingame/UI/Button/Ingame_Button_Reset.png");
	b_IsPause = Pause;
	b_IsCenter = true;
	b_IsOnMouseUp = true;
}

cUI_Button_Pause_Reset::~cUI_Button_Pause_Reset()
{
}

void cUI_Button_Pause_Reset::Update()
{
	cUI_Button::Update();

	if (*b_IsPause == false)
		b_IsLive = false;
}

void cUI_Button_Pause_Reset::Render()
{
	cUI_Button::Render();
}

void cUI_Button_Pause_Reset::ClickButton()
{
	*b_IsPause = false;
	SCENEMANAGER->ChangeScene("Ingame");
}
