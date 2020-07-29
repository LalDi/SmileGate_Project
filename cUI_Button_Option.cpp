#include "Framework.h"

cUI_Button_Option::cUI_Button_Option(POINT Pos, int tag, bool* BGM)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_Option", "./Images/Title/Title_Button_Option.png");
	b_PlayBgm = BGM;
}

cUI_Button_Option::~cUI_Button_Option()
{
}

void cUI_Button_Option::ClickButton()
{
	*b_PlayBgm = false;
	SCENEMANAGER->ChangeScene("Option");
}

void cUI_Button_Option::Update()
{
	cUI_Button::Update();
}

void cUI_Button_Option::Render()
{
	cUI_Button::Render();
}
