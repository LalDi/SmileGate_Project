#include "Framework.h"

cUI_Gauge::cUI_Gauge(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
}

cUI_Gauge::~cUI_Gauge()
{
}

void cUI_Gauge::Update()
{
	m_Amount = Math::Clamp(m_Amount, 0, 1);
}

void cUI_Gauge::Render()
{
	if (b_IsCenter)
	{
		m_Sprite_Background->CenterRender(m_Pos);
		m_Sprite->CenterRender(m_Pos, POINT{ (LONG)m_Amount, 1 }, 0);
	}
	else
	{
		POINT Temp;
		m_Sprite_Background->Render(m_Pos);
		Temp.x = m_Pos.x + (m_Sprite_Background->info.Width / 2) - (m_Sprite->info.Width);
		Temp.y = m_Pos.y + (m_Sprite_Background->info.Height / 2) - (m_Sprite->info.Height);
		m_Sprite->Render(Temp, POINT{ (LONG)m_Amount, 1 }, 0);
	}
}
