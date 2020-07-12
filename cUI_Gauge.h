#pragma once
class cUI_Gauge : public cGameObject
{
protected:
	cTexture* m_Sprite_Background;

	float m_Amount;
	bool b_IsCenter = true;

public:
	cUI_Gauge(POINT Pos, int tag);
	virtual ~cUI_Gauge();

	virtual void Update() override;
	virtual void Render() override;
};

