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
	UI_Temp = new cUI_Slider_Volume(POINT{ 875, 370 }, UI, BGM);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Slider_Volume(POINT{ 875, 470 }, UI, SE);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Text_BGM(POINT{ 400, 370 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Text_SE(POINT{ 400, 470 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Icon_Speaker(POINT{ 600, 370 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Icon_Speaker(POINT{ 600, 470 }, UI);
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
