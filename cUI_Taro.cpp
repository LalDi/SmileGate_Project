#include "Framework.h"

cUI_Taro::cUI_Taro(POINT Pos, int tag, cPlayer* Player)
	:cGameObject(Pos, tag)
{
	m_TaroCard[0] = IMAGEMANAGER->AddImage("TaroCard1", "./Images/Ingame/UI/Icon_TaroCard-1.png");
	m_TaroCard[1] = IMAGEMANAGER->AddImage("TaroCard2", "./Images/Ingame/UI/Icon_TaroCard-2.png");
	m_TaroCard[2] = IMAGEMANAGER->AddImage("TaroCard3", "./Images/Ingame/UI/Icon_TaroCard-3.png");

	m_Sprite = m_TaroCard[0];
	m_Player = Player;
}

cUI_Taro::~cUI_Taro()
{
}

void cUI_Taro::Update()
{
	if (m_Player)
		m_Sprite = m_TaroCard[m_Player->GetPlayerState()];
}

void cUI_Taro::Render()
{
	m_Sprite->Render(m_Pos);
}
