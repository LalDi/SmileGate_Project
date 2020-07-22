#pragma once
class cUI_Warning : public cGameObject
{
private:
	float m_Timer;
	int m_Alpha;
	bool b_IsFull;

public:
	cUI_Warning(POINT Pos, int tag);
	~cUI_Warning();

	virtual void Update() override;
	virtual void Render() override;
};

