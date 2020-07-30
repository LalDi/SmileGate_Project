#include "Framework.h"

cIngameBlackScene::cIngameBlackScene(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_BlackScene", "./Images/Ingame/Ingame_BlackScene.png");
	b_GoLeft = Pos.x == WinSizeX ? true : false;
}

cIngameBlackScene::~cIngameBlackScene()
{
}

void cIngameBlackScene::Update()
{
	if (b_Disappear)
	{
		if (b_GoLeft)
		{
			m_Pos.x -= 50;
			if (m_Pos.x <= -WinSizeX)
				b_IsLive = false;
		}
		else
		{
			m_Pos.x += 50;
			if (m_Pos.x >= WinSizeX)
				b_IsLive = false;
		}
	}
	else
	{
		if (m_Pos.x != 0)
		{
			if (b_GoLeft)
			{
				m_Pos.x -= 50;
			}
			else
			{
				m_Pos.x += 50;
			}
		}
		else
			b_ScreenBlack = true;
	}
}

void cIngameBlackScene::Render()
{
	m_Sprite->Render(m_Pos);
}
