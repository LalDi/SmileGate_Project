#include "Framework.h"

cUI_Button_SeleteCard1::cUI_Button_SeleteCard1(POINT Pos, int tag, cPlayer* Player, bool* Pause)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Select_Card1", "./Images/Ingame/UI/Button/Ingame_Button_Card-1.png");
	m_Player = Player;
	b_IsPause = Pause;
}

cUI_Button_SeleteCard1::~cUI_Button_SeleteCard1()
{
}

void cUI_Button_SeleteCard1::Update()
{
	cUI_Button::Update();
	if (m_Player->GetIsChange() == false)
		b_IsLive = false;
}

void cUI_Button_SeleteCard1::ClickButton()
{
	m_Player->SetPlayerState(PlayerState::Wheel_of_Fortune);
	m_Player->SetIsChange(false);
	*b_IsPause = true;
	b_IsLive = false;
}
