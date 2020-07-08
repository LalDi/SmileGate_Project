#pragma once
class cIngameBackground : public cGameObject
{
private:
	float m_Speed;

public:
	cIngameBackground(POINT Pos, int tag);
	~cIngameBackground();

	virtual void Update() override;
	virtual void Render() override;
};

