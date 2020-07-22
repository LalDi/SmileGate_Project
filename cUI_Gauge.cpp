#include "Framework.h"

cUI_Gauge::cUI_Gauge(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Rect = { 0,0,0,0 };
}

cUI_Gauge::~cUI_Gauge()
{
}

void cUI_Gauge::Update()
{
	m_Rect.bottom = m_Sprite->info.Height;
	m_Rect.right = m_Sprite->info.Width;

	m_Amount = Math::Clamp(m_Amount, 0, 1);
	m_Rect.left = m_Sprite->info.Width - m_Sprite->info.Width * m_Amount;
}

void cUI_Gauge::Render()
{
	POINT Pos = m_Pos;
	Pos.x += m_Rect.left;
	if (b_IsCenter)
	{
		if (b_LeftToRight)
			m_Sprite->CenterRender(Pos, m_Rect, POINT{ (LONG)m_Scale, (LONG)m_Scale });
		else
			m_Sprite->CenterRender(m_Pos, m_Rect, POINT{ (LONG)m_Scale, (LONG)m_Scale });
	}
	else
	{
		if (b_LeftToRight)
			m_Sprite->Render(Pos, m_Rect, POINT{ (LONG)m_Scale, (LONG)m_Scale });
		else
			m_Sprite->Render(m_Pos, m_Rect, POINT{ (LONG)m_Scale, (LONG)m_Scale });
	}
}
