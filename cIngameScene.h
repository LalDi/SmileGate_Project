#pragma once
class cIngameScene : public cScene
{
private:
	cPlayer* m_Player;
	time_t m_GPTime; //GP = Grace Period
	bool DEBUGMODE = false;

public:
	cIngameScene();
	~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

