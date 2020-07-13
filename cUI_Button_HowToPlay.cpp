#include "Framework.h"

cUI_Button_HowToPlay::cUI_Button_HowToPlay(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_HowToPlay", "./Images/Title/Title_Button_How To Play.png");
}

cUI_Button_HowToPlay::~cUI_Button_HowToPlay()
{
}

void cUI_Button_HowToPlay::ClickButton()
{
}

void cUI_Button_HowToPlay::Update()
{
	cUI_Button::Update();
}

void cUI_Button_HowToPlay::Render()
{
	cUI_Button::Render();
}
