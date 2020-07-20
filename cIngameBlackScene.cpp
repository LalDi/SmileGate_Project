#include "Framework.h"

cIngameBlackScene::cIngameBlackScene(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_BalckScene", "./Images/Ingame_BlackScene.png");
	b_GoLeft = Pos.x == WinSizeX ? true : false;
}

cIngameBlackScene::~cIngameBlackScene()
{
}

void cIngameBlackScene::Update()
{
	if (m_Pos.x != 0)
	{
		if (b_GoLeft)
		{
			m_Pos.x -= 5;
		}
		else
		{
			m_Pos.x += 5;
		}
	}
	
	if (b_Disappear)
	{
		if (b_GoLeft)
		{
			m_Pos.x -= 10;
			if (m_Pos.x <= -WinSizeX)
				b_IsLive = false;
		}
		else
		{
			m_Pos.x += 10;
			if (m_Pos.x >= WinSizeX)
				b_IsLive = false;
		}
	}
}

void cIngameBlackScene::Render()
{
	m_Sprite->Render(m_Pos);
}
