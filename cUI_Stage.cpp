#include "Framework.h"

cUI_Stage::cUI_Stage(POINT Pos, int tag, int Stage)
	:cGameObject(Pos, tag)
{
	m_Stage = Stage;
	
	switch (m_Stage)
	{
	case 1:	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Stage1", "./Images/Ingame/UI/Text_Stage-1.png");
	case 2:	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Stage2", "./Images/Ingame/UI/Text_Stage-2.png");
	case 3:	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_Stage3", "./Images/Ingame/UI/Text_Stage-3.png");
	}

	m_Timer.Init();
}

cUI_Stage::~cUI_Stage()
{
}

void cUI_Stage::Update()
{
	m_Timer.Update();
	if (m_Timer.Time(1))
	{
		b_IsLive = false;
	}
	m_Alpha += 3;
}

void cUI_Stage::Render()
{
	m_Sprite->CenterRender(m_Pos, m_Scale, 0, D3DCOLOR_RGBA(255, 255, 255, m_Alpha));
}
