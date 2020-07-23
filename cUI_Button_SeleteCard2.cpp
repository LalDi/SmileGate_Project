#include "Framework.h"
#include "cUI_Button_SeleteCard2.h"

cUI_Button_SeleteCard2::cUI_Button_SeleteCard2(POINT Pos, int tag, cPlayer* Player, bool* Pause)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Select_Card2", "./Images/Ingame/UI/Button/Ingame_Button_Card-2.png");
	m_Player = Player;
	b_IsPause = Pause;
}

cUI_Button_SeleteCard2::~cUI_Button_SeleteCard2()
{
}

void cUI_Button_SeleteCard2::Update()
{
	cUI_Button::Update();
	if (m_Player->GetIsChange() == false)
		b_IsLive = false;
}

void cUI_Button_SeleteCard2::ClickButton()
{
	m_Player->SetPlayerState(PlayerState::Judgement);
	m_Player->SetIsChange(false);
	*b_IsPause = false;
	b_IsLive = false;
}
