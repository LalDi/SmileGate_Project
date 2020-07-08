#include "Framework.h"

cUI_Button_Credit::cUI_Button_Credit(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_Credit", "./Images/Title/Title_Button_Credit.png");
}

cUI_Button_Credit::~cUI_Button_Credit()
{
}

void cUI_Button_Credit::Update()
{
	SetRect();

	if (CheckMouseOnButton())
	{
		m_Scale = 1.2f;
		if (INPUTMANAGER->BtnUp(LEFTCLICK))
		{
			// 버튼 상호 작용
		}
	}
	else
	{
		m_Scale = 1;
	}
}

void cUI_Button_Credit::Render()
{
	cUI_Button::Render();
}
