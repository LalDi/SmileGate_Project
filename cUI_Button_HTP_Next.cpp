#include "Framework.h"

cUI_Button_HTP_Next::cUI_Button_HTP_Next(POINT Pos, int tag, Page* Page)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_HowToPlay_Next", "./Images/How To Play/HowToPlay_Button_right.png");
	m_Page = Page;
	b_IsCenter = true;
}

cUI_Button_HTP_Next::~cUI_Button_HTP_Next()
{
}

void cUI_Button_HTP_Next::ClickButton()
{
	switch (*m_Page)
	{
	case Page::Page1:	*m_Page = Page::Page2;	break;;
	case Page::Page2:	break;
	default:			break;
	}
}
