#include "Framework.h"

cTitleScene::cTitleScene()
{
}

cTitleScene::~cTitleScene()
{
}

void cTitleScene::Init()
{
	cGameObject* Background;
	cGameObject* UI_Temp;

	Background = new cTitleBackground(POINT{ 0, 0 }, TEXTURE);
	AddObject(Background);

	UI_Temp = new cUI_Logo(POINT{ 820, 210 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Button_Gamestart(POINT{ 545, 820 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Button_HowToPlay(POINT{ 865, 820 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Button_Option(POINT{ 1130 , 820 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Button_Credit(POINT{ 1345 , 820 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Button_Quit(POINT{ 1525 , 820 }, UI);
	AddObject(UI_Temp);
}

void cTitleScene::Update()
{
	UpdateAllObject();
}

void cTitleScene::Render()
{
	RenderAllObject();
}

void cTitleScene::Release()
{
	RemoveAllObject();
}
