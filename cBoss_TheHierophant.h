#pragma once
class cBoss_TheHierophant : public cBoss
{
private:

public:
	cBoss_TheHierophant(POINT Pos, int tag, cPlayer* Player);
	~cBoss_TheHierophant();

	virtual void Update() override;

	virtual void Attack(list<cGameObject*>* Objects) override;

	void Attack1(list<cGameObject*>* Objects);
	void Attack2(list<cGameObject*>* Objects);
	void Attack3(list<cGameObject*>* Objects);

};

