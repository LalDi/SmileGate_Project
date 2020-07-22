#include "Framework.h"

cBomb::cBomb(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Bomb", "./Images/Ingame/Ingame_Bomb.png");
	m_Alpha = 0;
	b_IsFull = false;
}

cBomb::~cBomb()
{
}

void cBomb::Update()
{
	if (!b_IsFull)
	{
		m_Alpha += 15;
		if (m_Alpha >= 255)
			b_IsFull = true;
	}
	if (b_IsFull)
	{
		m_Alpha -= 15;
		if (m_Alpha <= 0)
			b_IsFull = false;
		b_IsLive = false;
	}
	m_Alpha = Clamp(m_Alpha, 0, 255);
}

void cBomb::Render()
{
	m_Sprite->Render(m_Pos, m_Scale, 0, D3DCOLOR_RGBA(255, 255, 255, m_Alpha));
}
