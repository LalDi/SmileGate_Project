#include "Framework.h"

cIngameBackground::cIngameBackground(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	//m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background", "./Images/Ingame/Ingame_Background_Temp.png");
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background", "./Images/Ingame/Ingame_Background.png");
	m_Speed = 500;
}

cIngameBackground::~cIngameBackground()
{
}

void cIngameBackground::Update()
{
	m_Pos.x -= m_Speed * DXUTGetElapsedTime();
	int Width = m_Sprite->info.Width;
	if (m_Pos.x + Width < 0)
		m_Pos.x = 0;
}

void cIngameBackground::Render()
{
	POINT m_Pos2 = m_Pos;
	m_Pos2.x += m_Sprite->info.Width;
	m_Sprite->Render(m_Pos);
	m_Sprite->Render(m_Pos2);
}