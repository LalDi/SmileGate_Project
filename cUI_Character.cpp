#include "Framework.h"

cUI_Character::cUI_Character(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Character_Background", "./Images/Ingame/UI/Icon_Character_Background.png");
	m_Sprite_Chara = IMAGEMANAGER->AddImage("Ingame_UI_Character", "./Images/Ingame/UI/Icon_Character.png");
}

cUI_Character::~cUI_Character()
{
}

void cUI_Character::Update()
{
}

void cUI_Character::Render()
{
	m_Sprite->CenterRender(m_Pos);
	m_Sprite_Chara->CenterRender(m_Pos);
}
