#include "Framework.h"

cUI_Button_HowToPlay::cUI_Button_HowToPlay(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_HowToPlay", "./Images/Title/Title_Button_How To Play.png");
}

cUI_Button_HowToPlay::~cUI_Button_HowToPlay()
{
}

void cUI_Button_HowToPlay::Update()
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

void cUI_Button_HowToPlay::Render()
{
	cUI_Button::Render();
}
