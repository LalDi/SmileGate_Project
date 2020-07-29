#pragma once
class cOptionScene : public cScene
{
private:
	float m_BGM_Amount = 1;
	float m_SE_Amount = 1;

public:
	cOptionScene();
	~cOptionScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

