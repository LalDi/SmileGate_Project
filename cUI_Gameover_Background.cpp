#include "Framework.h"

cUI_Gameover_Background::cUI_Gameover_Background(POINT Pos, int tag, int Score)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_Gameover_Background", "./Images/Ingame/Ingame_Gameover.png");
	m_Score = Score;
}

cUI_Gameover_Background::~cUI_Gameover_Background()
{
}

void cUI_Gameover_Background::Update()
{
	swprintf(m_Text, L"%d", m_Score);
}

void cUI_Gameover_Background::Render()
{
	POINT temp = { WinSizeX / 2, WinSizeY / 2 + 50 };
	m_Sprite->Render(m_Pos);
	IMAGEMANAGER->CenterRenderText(m_Text, 32, temp);
}
