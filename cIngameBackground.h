#pragma once
class cIngameBackground : public cGameObject
{
private:
	float m_Speed;

public:
	cIngameBackground(POINT Pos, int tag, int Stage);
	~cIngameBackground();

	virtual void Update() override;
	virtual void Render() override;

	void ChangeBG(int Stage);
};

