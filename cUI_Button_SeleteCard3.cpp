#include "Framework.h"

cUI_Button_SeleteCard3::cUI_Button_SeleteCard3(POINT Pos, int tag, cPlayer* Player, bool* Pause)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Select_Card3", "./Images/Ingame/UI/Button/Ingame_Button_Card-3.png");
	m_Player = Player;
	b_IsPause = Pause;
}

cUI_Button_SeleteCard3::~cUI_Button_SeleteCard3()
{
}

void cUI_Button_SeleteCard3::Update()
{
	cUI_Button::Update();
	if (m_Player->GetIsChange() == false)
		b_IsLive = false;
}

void cUI_Button_SeleteCard3::ClickButton()
{
	m_Player->SetPlayerState(PlayerState::The_Sun);
	m_Player->SetIsChange(false);
	*b_IsPause = true;
	b_IsLive = false;
}
