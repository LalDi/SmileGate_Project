#pragma once
class cUI_Gauge_Power : public cUI_Gauge
{
private:
	cTexture* m_Border;
	cPlayer* m_Player;

	int m_MaxValue;
	int m_Value;

public:
	cUI_Gauge_Power(POINT Pos, int tag, cPlayer* Player);
	~cUI_Gauge_Power();

	virtual void Update() override;
	virtual void Render() override;
};

