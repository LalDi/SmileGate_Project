#pragma once
class cMeteo : public cBullet
{
private:
	cTexture* m_Warning;
	cTimer m_Timer;

	bool b_IsShoot;

public:
	cMeteo(POINT Pos, int tag, int Angle = 0, float Speed = 3000);
	~cMeteo();

	virtual void Update() override;
	virtual void Render() override;

};

