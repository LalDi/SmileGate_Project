#include "Framework.h"

cUI_Gauge_BossHp::cUI_Gauge_BossHp(POINT Pos, int tag, cBoss* Target)
	:cUI_Gauge(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Ingame_UI_BossHp", "./Images/Ingame/UI/Ingame_Boss_Hp.png");

	m_Boss = Target;
	m_MaxValue = m_Boss->GetMaxHp();
	m_Value = m_Boss->GetHp();

	b_IsCenter = true;
	b_LeftToRight = true;
}

cUI_Gauge_BossHp::~cUI_Gauge_BossHp()
{
}

void cUI_Gauge_BossHp::Update()
{
	if (m_Boss)
		m_Value = m_Boss->GetHp();
	else
		b_IsLive = false;

	m_Amount = (float)m_Value / (float)m_MaxValue;

	cUI_Gauge::Update();
}