#include "Framework.h"

cUI_Button_Option::cUI_Button_Option(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_Option", "./Images/Title/Title_Button_Option.png");
}

cUI_Button_Option::~cUI_Button_Option()
{
}

void cUI_Button_Option::Update()
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

void cUI_Button_Option::Render()
{
	cUI_Button::Render();
}
