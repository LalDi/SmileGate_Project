#include "Framework.h"

cHowToPlayScene::cHowToPlayScene()
{
}

cHowToPlayScene::~cHowToPlayScene()
{
}

void cHowToPlayScene::Init()
{
	cGameObject* UI_Temp;

	m_NowPage = Page::Page1;

	m_Background = new cHTPBackground(POINT{ 0, 0 }, TEXTURE, &m_NowPage);
	AddObject(m_Background);

	UI_Temp = new cUI_Button_Back(POINT{ 70, 70 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Button_HTP_Prev(POINT{ WinSizeX / 2 - 750, WinSizeY / 2 }, UI, &m_NowPage);
	AddObject(UI_Temp);							
	UI_Temp = new cUI_Button_HTP_Next(POINT{ WinSizeX / 2 + 750, WinSizeY / 2 }, UI, &m_NowPage);
	AddObject(UI_Temp);
}

void cHowToPlayScene::Update()
{
	// ��� ������Ʈ�� Update()�� �����Ų��.
	UpdateAllObject();
}

void cHowToPlayScene::Render()
{
	// ��� ������Ʈ�� Render()�� �����Ų��.
	RenderAllObject();
}

void cHowToPlayScene::Release()
{
	RemoveAllObject();
}
