#include "Framework.h"

cUI_Button_Back::cUI_Button_Back(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_Back", "./Images/Title/Title_Back.png");
	b_IsCenter = true;
}

cUI_Button_Back::~cUI_Button_Back()
{
}

void cUI_Button_Back::ClickButton()
{
	SCENEMANAGER->ChangeScene("Title");
}

void cUI_Button_Back::Update()
{
	cUI_Button::Update();
}

void cUI_Button_Back::Render()
{
	cUI_Button::Render();
}
