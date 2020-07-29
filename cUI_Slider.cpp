#include "Framework.h"

cUI_Slider::cUI_Slider(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	//자식 객체에서 선언해주어야 하는 내용
	//LONG Width = m_BgSprite->info.Width / 2;
	//LONG Height = m_BgSprite->info.Height / 2;
	//m_Rect = { Pos.x - Width, Pos.y - Height, Pos.x + Width, Pos.y + Height };
	m_RenderRect = { 0,0,0,0 };
	b_IsControl = false;
}

cUI_Slider::~cUI_Slider()
{
}

void cUI_Slider::Update()
{
	float Max = m_Max - m_Min;
	
	// 마우스를 클릭 했을 때
	if (INPUTMANAGER->BtnPress(LEFTCLICK))
	{
		// 마우스가 슬라이더 위에 있다면
		if (Math::IsPointInRect(m_Rect, INPUTMANAGER->GetMousePos()))
		{
			// 슬라이더 조정이 활성화된다.
			b_IsControl = true;
		}
	}

	// 마우스를 떼면
	if (INPUTMANAGER->BtnUp(LEFTCLICK))
		// 슬라이더 조정이 비활성화 된다.
		b_IsControl = false;

	// 슬라이더 조정이 활성화 되어 있을 때
	if (b_IsControl)
	{
		// 슬라이더의 헤더는 마우스의 x위치를 따라간다.
		m_HandlePos.x = INPUTMANAGER->GetMousePos().x;

		// 슬라이더의 헤더가 슬라이더 바깥으로 나가는 것을 막아준다.
		if (m_HandlePos.x <= m_Rect.left)
			m_HandlePos.x = m_Rect.left;
		if (m_HandlePos.x >= m_Rect.right)
			m_HandlePos.x = m_Rect.right;

		// 슬라이더의 값이 정수값으로 고정되어 있을 경우, 그 값에 맞는 위치로 헤더를 옮겨준다.
		if (b_IsInteger)
		{
			for (int i = 0; i < Max; i++)
			{
				int temp = (m_Rect.right - m_Rect.left) / (int)(Max);
				if (m_HandlePos.x >= m_Rect.left + (temp * i) - (temp / 2) &&
					m_HandlePos.x <= m_Rect.left + (temp * i) + (temp / 2))
				{
					m_HandlePos.x = m_Rect.left + (temp * i);
				}
			}
		}
	}

	// 슬라이더의 값을 적용한다.
	m_Amount = ((float)(m_HandlePos.x - m_Rect.left) / (float)(m_Rect.right - m_Rect.left)) * Max + m_Min;
	m_Amount = Clamp(m_Amount, m_Min, m_Max);

	// 슬라이더의 값이 정수값으로 고정되어 있을 경우, 실수를 정수로 변환한다.
	if (b_IsInteger)
		m_Amount = (int)m_Amount;

	m_RenderRect.bottom = m_Sprite->info.Height;
	m_RenderRect.right = m_Sprite->info.Width;

	m_RenderRect.right = m_Sprite->info.Width * ((m_Amount-m_Min) / Max);
}

void cUI_Slider::Render()
{
	POINT Pos = m_Pos;
	//Pos.x += m_RenderRect.left;
	m_BgSprite->CenterRender(m_Pos);
	m_Sprite->CenterRender(Pos, m_RenderRect, POINT{ 1, 1 });
	m_HandleSprite->CenterRender(m_HandlePos);
}
