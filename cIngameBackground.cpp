#include "Framework.h"

cIngameBackground::cIngameBackground(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background", "./Images/Ingame/Ingame_Background.png");
	m_Speed = 500;
}

cIngameBackground::~cIngameBackground()
{
}

void cIngameBackground::Update()
{
	m_Pos.x -= m_Speed * DXUTGetElapsedTime();
	if (m_Pos.x + WinSizeX < 0)
		m_Pos.x = 0;
}

void cIngameBackground::Render()
{
	POINT m_Pos2 = m_Pos;
	m_Pos2.x += WinSizeX;
	m_Sprite->Render(m_Pos);
	m_Sprite->Render(m_Pos2);
}
