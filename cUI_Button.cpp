#include "Framework.h"

cUI_Button::cUI_Button(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
}

cUI_Button::~cUI_Button()
{
}

void cUI_Button::Update()
{
	SetRect();

	if (CheckMouseOnButton())
	{
		if (b_IsOnMouseUp)
			m_Scale = 1.2f;
		if (INPUTMANAGER->BtnUp(LEFTCLICK))
		{
			ClickButton();
		}
	}
	else if (b_IsOnMouseUp)
	{
		m_Scale = 1;
	}

}

void cUI_Button::Render()
{
	if (b_IsCenter)
	{
		if (CheckMouseOnButton() && INPUTMANAGER->BtnPress(LEFTCLICK))
		{
			m_Sprite->CenterRender(m_Pos, m_Scale, 0, D3DCOLOR_XRGB(50, 50, 50));
		}
		else
		{
			m_Sprite->CenterRender(m_Pos, m_Scale, 0);
		}
	}
	else
	{
		if (CheckMouseOnButton() && INPUTMANAGER->BtnPress(LEFTCLICK))
		{
			m_Sprite->Render(m_Pos, m_Scale, 0, D3DCOLOR_XRGB(50, 50, 50));
		}
		else
		{
			m_Sprite->Render(m_Pos, m_Scale, 0);
		}
	}
}

bool cUI_Button::CheckMouseOnButton()
{
	POINT MousePos = INPUTMANAGER->GetMousePos();
	if (IsPointInRect(m_Rect, MousePos))
		return true;
	return false;
}
