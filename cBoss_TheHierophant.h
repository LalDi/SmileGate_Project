#pragma once
class cBoss_TheHierophant : public cBoss
{
private:
	POINT m_Vec;

public:
	cBoss_TheHierophant(POINT Pos, int tag, cPlayer* Player);
	~cBoss_TheHierophant();

	virtual void Update() override;

	virtual void Attack(list<cGameObject*> *Objects) override;

	void Attack1(list<cGameObject*> *Objects);
	void Attack2(list<cGameObject*> *Objects);
	void Attack3(list<cGameObject*> *Objects);
	void Attack4(list<cGameObject*> *Objects);
	void Attack5(list<cGameObject*> *Objects);
	void Attack6(list<cGameObject*> *Objects);
	void Attack7(list<cGameObject*> *Objects);
	void Attack8(list<cGameObject*>* Objects);
};