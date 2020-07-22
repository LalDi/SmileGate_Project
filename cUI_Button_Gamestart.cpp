#include "Framework.h"

cUI_Button_Gamestart::cUI_Button_Gamestart(POINT Pos, int tag, bool* BGM)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_Gamestart", "./Images/Title/Title_Button_Game start.png");
	b_PlayBgm = BGM;
}

cUI_Button_Gamestart::~cUI_Button_Gamestart()
{
}

void cUI_Button_Gamestart::ClickButton()
{
	SCENEMANAGER->ChangeScene("Ingame");
	*b_PlayBgm = false;
	SOUNDMANAGER->StopAll();
}

void cUI_Button_Gamestart::Update()
{
	cUI_Button::Update();
}

void cUI_Button_Gamestart::Render()
{
	cUI_Button::Render();
}
