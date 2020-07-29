#pragma once
class cUI_Hit : public cGameObject
{
private:
	cTimer m_Timer;

public:
	cUI_Hit(POINT Pos, int tag);
	~cUI_Hit();

	virtual void Update() override;
	virtual void Render() override;
};

