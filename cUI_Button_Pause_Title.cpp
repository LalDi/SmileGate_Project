#include "Framework.h"

cUI_Button_Pause_Title::cUI_Button_Pause_Title(POINT Pos, int tag, bool* Pause)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Pause_Title", "./Images/Ingame/UI/Button/Ingame_Button_Title.png");
	b_IsPause = Pause;
	b_IsCenter = true;
	b_IsOnMouseUp = true;
}

cUI_Button_Pause_Title::~cUI_Button_Pause_Title()
{
}

void cUI_Button_Pause_Title::Update()
{
	cUI_Button::Update();
	
	if (*b_IsPause == false)
		b_IsLive = false;
}

void cUI_Button_Pause_Title::Render()
{
	cUI_Button::Render();
}

void cUI_Button_Pause_Title::ClickButton()
{
	*b_IsPause = false;
	SCENEMANAGER->ChangeScene("Title");
}
