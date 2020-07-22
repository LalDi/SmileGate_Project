#include "Framework.h"

cUI_Warning::cUI_Warning(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Warning", "./Images/Ingame/Ingame_Warning.png");
	m_Timer = 0;
	m_Alpha = 0;
	b_IsFull = false;
	SOUNDMANAGER->Play("Warning", 1, false);
}

cUI_Warning::~cUI_Warning()
{
}

void cUI_Warning::Update()
{
	m_Timer += DXUTGetElapsedTime();
	if (m_Timer >= 3)
		b_IsLive = false;

	if (b_IsFull)
	{
		m_Alpha -= 5;
		if (m_Alpha <= 0)
		{
			b_IsFull = false;
			SOUNDMANAGER->Play("Warning", 1, false);
		}
	}
	if (!b_IsFull)
	{
		m_Alpha += 5;
		if (m_Alpha >= 255)
		{
			b_IsFull = true;
			SOUNDMANAGER->Play("Warning", 1, false);
		}
	}
	m_Alpha = Clamp(m_Alpha, 0, 255);
}

void cUI_Warning::Render()
{
	m_Sprite->Render(m_Pos, m_Scale, 0, D3DCOLOR_RGBA(255, 255, 255, m_Alpha));
}
