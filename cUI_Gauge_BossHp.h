#pragma once
class cUI_Gauge_BossHp : public cUI_Gauge
{
private:
	cBoss* m_Boss;

	int m_MaxValue;
	int m_Value;

public:
	cUI_Gauge_BossHp(POINT Pos, int tag, cBoss* Target);
	~cUI_Gauge_BossHp();

	virtual void Update() override;
};

