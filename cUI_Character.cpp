#include "Framework.h"

cUI_Character::cUI_Character(POINT Pos, int tag, cPlayer* Player)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Character_Background", "./Images/Ingame/UI/Icon_Character_Background.png");
	IMAGEMANAGER->AddImage("Ingame_UI_Character-1", "./Images/Ingame/UI/Icon_Character-1.png");
	IMAGEMANAGER->AddImage("Ingame_UI_Character-2", "./Images/Ingame/UI/Icon_Character-2.png");
	IMAGEMANAGER->AddImage("Ingame_UI_Character-3", "./Images/Ingame/UI/Icon_Character-3.png");

	m_Player = Player;
}

cUI_Character::~cUI_Character()
{
}

void cUI_Character::Update()
{
	switch (m_Player->GetPlayerState())
	{
	case _Wheel_of_Fortune:	m_Sprite_Chara = IMAGEMANAGER->FindImage("Ingame_UI_Character-1");	break;
	case _Judgement:		m_Sprite_Chara = IMAGEMANAGER->FindImage("Ingame_UI_Character-2");	break;
	case _The_Sun:			m_Sprite_Chara = IMAGEMANAGER->FindImage("Ingame_UI_Character-3");	break;
	default:																					break;
	}
}

void cUI_Character::Render()
{
	m_Sprite->CenterRender(m_Pos);
	m_Sprite_Chara->CenterRender(m_Pos);
}
