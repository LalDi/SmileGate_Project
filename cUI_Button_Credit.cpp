#include "Framework.h"

cUI_Button_Credit::cUI_Button_Credit(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_Credit", "./Images/Title/Title_Button_Credit.png");
}

cUI_Button_Credit::~cUI_Button_Credit()
{
}

void cUI_Button_Credit::ClickButton()
{
	SCENEMANAGER->ChangeScene("Credit");
}

void cUI_Button_Credit::Update()
{
	cUI_Button::Update();
}

void cUI_Button_Credit::Render()
{
	cUI_Button::Render();
}
