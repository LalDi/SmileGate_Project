#include "Framework.h"

cUI_Logo::cUI_Logo(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Logo", "./Images/Title/Title_Logo.png");
}

cUI_Logo::~cUI_Logo()
{
}

void cUI_Logo::Update()
{
}

void cUI_Logo::Render()
{
	m_Sprite->CenterRender(m_Pos);
}
