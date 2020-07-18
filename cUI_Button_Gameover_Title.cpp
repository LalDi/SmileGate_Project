#include "Framework.h"

cUI_Button_Gameover_Title::cUI_Button_Gameover_Title(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Gameover_Title", "./Images/Ingame/UI/Button/Ingame_Button_Title.png");
}

cUI_Button_Gameover_Title::~cUI_Button_Gameover_Title()
{
}

void cUI_Button_Gameover_Title::Update()
{
	cUI_Button::Update();
}

void cUI_Button_Gameover_Title::Render()
{
	cUI_Button::Render();
}

void cUI_Button_Gameover_Title::ClickButton()
{
	SCENEMANAGER->ChangeScene("Title");
}
