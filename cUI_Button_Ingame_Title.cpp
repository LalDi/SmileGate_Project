#include "Framework.h"

cUI_Button_Ingame_Title::cUI_Button_Ingame_Title(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Title", "./Images/Ingame/UI/Button/Ingame_Button_Title.png");
}

cUI_Button_Ingame_Title::~cUI_Button_Ingame_Title()
{
}

void cUI_Button_Ingame_Title::Update()
{
	cUI_Button::Update();
}

void cUI_Button_Ingame_Title::Render()
{
	cUI_Button::Render();
}

void cUI_Button_Ingame_Title::ClickButton()
{
	SCENEMANAGER->ChangeScene("Title");
}
