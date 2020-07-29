#include "Framework.h"

cOptionScene::cOptionScene()
{
}

cOptionScene::~cOptionScene()
{
}

void cOptionScene::Init()
{
	cGameObject* Background;
	cGameObject* UI_Temp;

	Background = new cOptionBackground(POINT{ 0, 0 }, TEXTURE);
	AddObject(Background);

	UI_Temp = new cUI_Button_OptionBack(POINT{ 70, 70 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Slider_Volume(POINT{ 825, 375 }, UI, BGM);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Slider_Volume(POINT{ 825, 450 }, UI, SE);
	AddObject(UI_Temp);
}

void cOptionScene::Update()
{
	// ��� ������Ʈ�� Update()�� �����Ų��.
	UpdateAllObject();
}

void cOptionScene::Render()
{
	// ��� ������Ʈ�� Render()�� �����Ų��.
	RenderAllObject();
}

void cOptionScene::Release()
{
	RemoveAllObject();
}
