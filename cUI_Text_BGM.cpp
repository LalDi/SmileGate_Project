#include "Framework.h"

cUI_Text_BGM::cUI_Text_BGM(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Option_Text_BGM", "./Images/Option/Option_BGM sound.png");
}

cUI_Text_BGM::~cUI_Text_BGM()
{
}

void cUI_Text_BGM::Update()
{
}

void cUI_Text_BGM::Render()
{
	m_Sprite->CenterRender(m_Pos);
}
