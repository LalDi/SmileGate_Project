#pragma once
class cBoss_TheHermit : public cBoss
{
private:
	POINT m_Vec;
	int m_Angle;

public:
	cBoss_TheHermit(POINT Pos, int tag, cPlayer* Player);
	~cBoss_TheHermit();

	virtual void Update() override;

	virtual void Attack(list<cGameObject*>* Objects) override;

	void Attack1(list<cGameObject*>* Objects);
	void Attack2(list<cGameObject*>* Objects);
	void Attack3(list<cGameObject*>* Objects);
	void Attack4(list<cGameObject*>* Objects);
	void Attack5(list<cGameObject*>* Objects);
	void Attack6(list<cGameObject*>* Objects);
	void Attack7(list<cGameObject*>* Objects);

};

