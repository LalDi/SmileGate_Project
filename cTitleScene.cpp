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

	SCENEMANAGER->AddScene("Credit", new cCreditScene());
}

void cTitleScene::Update()
{
	// 모든 오브젝트의 Update()를 실행시킨다.
	UpdateAllObject();
}

void cTitleScene::Render()
{
	// 모든 오브젝트의 Render()를 실행시킨다.
	RenderAllObject();
}

void cTitleScene::Release()
{
	RemoveAllObject();
}
