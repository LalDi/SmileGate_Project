#include "Framework.h"

cHTPBackground::cHTPBackground(POINT Pos, int tag, Page* Page)
	:cGameObject(Pos, tag)
{
	m_Page = Page;
	m_Sprite = IMAGEMANAGER->AddImage("HowToPlay_Background1", "./Images/How To Play/HowToPlay-1.png");
	m_Sprite2 = IMAGEMANAGER->AddImage("HowToPlay_Background2", "./Images/How To Play/HowToPlay-2.png");
}

cHTPBackground::~cHTPBackground()
{
}

void cHTPBackground::Update()
{
}

void cHTPBackground::Render()
{
	switch (*m_Page)
	{
	case Page::Page1:	m_Sprite->Render(m_Pos);	break;
	case Page::Page2:	m_Sprite2->Render(m_Pos);	break;
	default:										break;
	}
}
