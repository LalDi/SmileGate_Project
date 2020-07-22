#include "Framework.h"

cUI_Button_Ingame_Restart::cUI_Button_Ingame_Restart(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Gameover_Restart", "./Images/Ingame/UI/Button/Ingame_Button_Restsrat.png");
}

cUI_Button_Ingame_Restart::~cUI_Button_Ingame_Restart()
{
}

void cUI_Button_Ingame_Restart::Update()
{
	cUI_Button::Update();
}

void cUI_Button_Ingame_Restart::Render()
{
	cUI_Button::Render();
}

void cUI_Button_Ingame_Restart::ClickButton()
{
	SCENEMANAGER->ChangeScene("Ingame");
}
