#include "Framework.h"

cUI_Button_Quit::cUI_Button_Quit(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_Quit", "./Images/Title/Title_Button_Quit.png");
}

cUI_Button_Quit::~cUI_Button_Quit()
{
}

void cUI_Button_Quit::Update()
{
	SetRect();

	if (CheckMouseOnButton())
	{
		m_Scale = 1.2f;
		if (INPUTMANAGER->BtnUp(LEFTCLICK))
		{
			exit(0);
		}
	}
	else
	{
		m_Scale = 1;
	}
}

void cUI_Button_Quit::Render()
{
	cUI_Button::Render();
}
