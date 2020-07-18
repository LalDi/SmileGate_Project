#include "Framework.h"

cUI_Button_Gameover_Restart::cUI_Button_Gameover_Restart(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Gameover_Restart", "./Images/Ingame/UI/Button/Ingame_Button_Restsrat.png");
}

cUI_Button_Gameover_Restart::~cUI_Button_Gameover_Restart()
{
}

void cUI_Button_Gameover_Restart::Update()
{
	cUI_Button::Update();
}

void cUI_Button_Gameover_Restart::Render()
{
	cUI_Button::Render();
}

void cUI_Button_Gameover_Restart::ClickButton()
{
	SCENEMANAGER->ChangeScene("Ingame");
}
