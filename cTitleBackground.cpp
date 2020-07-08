#include "Framework.h"

cTitleBackground::cTitleBackground(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Background", "./Images/Title/Title_Background.png"); // 이름, 경로
	m_Pos = { 0, 0 };
}

cTitleBackground::~cTitleBackground()
{
}

void cTitleBackground::Update()
{
}

void cTitleBackground::Render()
{
	m_Sprite->Render(m_Pos);
}
