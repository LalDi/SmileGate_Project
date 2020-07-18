#include "Framework.h"

cUI_Button::cUI_Button(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
}

cUI_Button::~cUI_Button()
{
}

/**
	@fn		Update()

	@brief	버튼의 기본 기능.

	@remark	버튼의 Rect값 설정, 마우스를 올렸을 때 버튼이 커지는 효과, 버튼을 클릭했을 때의 상호작용을 함.
*/
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

/**
	@fn		Render()

	@brief	버튼의 화면 출력
*/
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

/**
	@fn		CheckMouseOnButton()

	@return	마우스가 버튼 위에 올라가있다면 true, 그렇지 않다면 false를 반환
*/
bool cUI_Button::CheckMouseOnButton()
{
	POINT MousePos = INPUTMANAGER->GetMousePos();
	if (IsPointInRect(m_Rect, MousePos))
		return true;
	return false;
}
