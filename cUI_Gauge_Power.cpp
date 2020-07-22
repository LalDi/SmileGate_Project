#include "Framework.h"

cUI_Gauge_Power::cUI_Gauge_Power(POINT Pos, int tag, cPlayer* Player)
	:cUI_Gauge(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_PowerGauge", "./Images/Ingame/UI/Ingame_Powergage.png");
	m_Border = IMAGEMANAGER->AddImage("Ingame_UI_PowerBorder", "./Images/Ingame/UI/Ingame_Powergage_Border.png");

	m_Player = Player;
	m_MaxValue = m_Player->GetMaxPower();
	m_Value = m_Player->GetPower();

	b_IsCenter = true;
	b_LeftToRight = false;
}

cUI_Gauge_Power::~cUI_Gauge_Power()
{
}

void cUI_Gauge_Power::Update()
{
	m_Value = m_Player->GetPower();

	m_Amount = (float)m_Value / (float)m_MaxValue;

	cUI_Gauge::Update();
}

void cUI_Gauge_Power::Render()
{
	cUI_Gauge::Render();
	m_Border->CenterRender(m_Pos);
}
