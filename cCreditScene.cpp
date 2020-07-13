#include "Framework.h"

cCreditScene::cCreditScene()
{
}

cCreditScene::~cCreditScene()
{
}

void cCreditScene::Init()
{
	cGameObject* Background;
	cGameObject* UI_Temp;

	Background = new cCreditBackground(POINT{ 0, 0 }, TEXTURE);
	AddObject(Background);

	UI_Temp = new cUI_Button_Back(POINT{ 70, 70 }, UI);
	AddObject(UI_Temp);
}

void cCreditScene::Update()
{
	UpdateAllObject();
}

void cCreditScene::Render()
{
	RenderAllObject();
}

void cCreditScene::Release()
{
	RemoveAllObject();
}
