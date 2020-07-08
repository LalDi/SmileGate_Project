#include "Framework.h"

cUI_Button_Gamestart::cUI_Button_Gamestart(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_Gamestart", "./Images/Title/Title_Button_Game start.png");
}

cUI_Button_Gamestart::~cUI_Button_Gamestart()
{
}

void cUI_Button_Gamestart::Update()
{
	SetRect();

	if (CheckMouseOnButton())
	{
		m_Scale = 1.2f;
		if (INPUTMANAGER->BtnUp(LEFTCLICK))
		{
			SCENEMANAGER->ChangeScene("Ingame");
		}
	}
	else
	{
		m_Scale = 1;
	}
}

void cUI_Button_Gamestart::Render()
{
	cUI_Button::Render();
}
