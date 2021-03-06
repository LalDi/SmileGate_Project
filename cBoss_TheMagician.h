#pragma once
class cBoss_TheMagician : public cBoss
{
private:
	POINT m_Vec;
	int m_Direction = 1;

public:
	cBoss_TheMagician(POINT Pos, int tag, cPlayer* Player);
	~cBoss_TheMagician();

	virtual void Update() override;

	cGameObject* Meteo(int x, int y, int Angle = 0, float Speed = 1500);

	virtual void Attack(list<cGameObject*>* Objects) override;

	void Attack1(list<cGameObject*>* Objects);
	void Attack2(list<cGameObject*>* Objects);
	void Attack3(list<cGameObject*>* Objects);
	void Attack4(list<cGameObject*>* Objects);
	void Attack5(list<cGameObject*>* Objects);
	void Attack6(list<cGameObject*>* Objects);
	void Attack7(list<cGameObject*>* Objects);
};

