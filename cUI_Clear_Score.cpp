#include "Framework.h"

cUI_Clear_Score::cUI_Clear_Score(POINT Pos, int tag, int* Score)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Clear_Score", "./Images/Clear/GameClear_Score.png");
	m_Score = Score;
}

cUI_Clear_Score::~cUI_Clear_Score()
{
}

void cUI_Clear_Score::Update()
{
	int temp = 0;
	temp = *m_Score;
	swprintf(m_Text, L"%d", temp);
}

void cUI_Clear_Score::Render()
{
	m_Sprite->CenterRender(m_Pos);
	POINT Temp = m_Pos;
	Temp.x += 130;
	IMAGEMANAGER->CenterRenderText(m_Text, 32, Temp);
}
