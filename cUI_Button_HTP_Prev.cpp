#include "Framework.h"

cUI_Button_HTP_Prev::cUI_Button_HTP_Prev(POINT Pos, int tag, Page* Page)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_HowToPlay_Prev", "./Images/How To Play/HowToPlay_Button_left.png");
	m_Page = Page;
	b_IsCenter = true;
}

cUI_Button_HTP_Prev::~cUI_Button_HTP_Prev()
{
}

void cUI_Button_HTP_Prev::ClickButton()
{
	switch (*m_Page)
	{
	case Page::Page1:	break;
	case Page::Page2:	*m_Page = Page::Page1;	break;
	default:			break;
	}
}
