#include "Framework.h"

cOptionBackground::cOptionBackground(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Option_Background", "./Images/Option/Title_Option_Background.png");
	m_Pos = { 0, 0 };
}

cOptionBackground::~cOptionBackground()
{
}

void cOptionBackground::Update()
{
}

void cOptionBackground::Render()
{
	m_Sprite->Render(m_Pos);
}
