#include "Framework.h"

cIngameBackground::cIngameBackground(POINT Pos, int tag, int Stage)
	:cGameObject(Pos, tag)
{
	//m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background", "./Images/Ingame/Ingame_Background_Temp.png");
	switch (Stage)
	{
	case 1:	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background", "./Images/Ingame/Ingame_Background-1.png");	break;
	case 2:	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background", "./Images/Ingame/Ingame_Background-2.png");	break;
	case 3:	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background", "./Images/Ingame/Ingame_Background-3.png");	break;
	default:	break;
	}
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

void cIngameBackground::ChangeBG(int Stage)
{
	switch (Stage)
	{
	case 1:	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background1", "./Images/Ingame/Ingame_Background-1.png");	break;
	case 2:	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background2", "./Images/Ingame/Ingame_Background-2.png");	break;
	case 3:	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Background3", "./Images/Ingame/Ingame_Background-3.png");	break;
	default:	break;
	}
}
