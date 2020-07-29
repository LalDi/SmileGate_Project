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
	// 모든 오브젝트의 Update()를 실행시킨다.
	UpdateAllObject();
}

void cOptionScene::Render()
{
	// 모든 오브젝트의 Render()를 실행시킨다.
	RenderAllObject();
}

void cOptionScene::Release()
{
	RemoveAllObject();
}
