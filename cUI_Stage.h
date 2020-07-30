#pragma once
class cUI_Stage : public cGameObject
{
private:
	int m_Stage;
	cTimer m_Timer;
	int m_Alpha = 0;

public:
	cUI_Stage(POINT Pos, int tag, int Stage);
	~cUI_Stage();

	virtual void Update() override;
	virtual void Render() override;

};

