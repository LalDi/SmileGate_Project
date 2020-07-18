#include "Framework.h"

cUI_Score::cUI_Score(POINT Pos, int tag, int* Score)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Score", "./Images/Ingame/UI/Ingame_Score_Background.png");
	m_Score = Score;
	//m_Text = L"";
}

cUI_Score::~cUI_Score()
{
}

void cUI_Score::Update()
{
	int temp = *m_Score;
	swprintf(m_Text, L"%011d", temp);
}

void cUI_Score::Render()
{
	m_Sprite->CenterRender(m_Pos);
	POINT Temp = m_Pos;
	Temp.x -= 100;
	IMAGEMANAGER->CenterRenderText(L"Score : ", 32, Temp);
	Temp.x += 150;
	IMAGEMANAGER->CenterRenderText(m_Text, 32, Temp);
}
