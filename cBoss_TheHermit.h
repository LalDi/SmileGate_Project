#pragma once
class cBoss_TheHermit : public cBoss
{
private:
	cTexture* m_Shield;
	cTimer m_Heal;
	POINT m_SavePos;
	bool b_IsShield;

public:
	cBoss_TheHermit(POINT Pos, int tag, cPlayer* Player);
	~cBoss_TheHermit();

	virtual void Update() override;
	virtual void Render() override;

	virtual bool Appear(POINT Pos) override;

	virtual void Attack(list<cGameObject*>* Objects) override;

	void Attack1(list<cGameObject*>* Objects);
	void Attack2(list<cGameObject*>* Objects);
	void Attack3(list<cGameObject*>* Objects);
	void Attack4(list<cGameObject*>* Objects);

	void PowerAttack1(list<cGameObject*>* Objects);
	void PowerAttack2(list<cGameObject*>* Objects);
	void PowerAttack3(list<cGameObject*>* Objects);
	void PowerAttack4(list<cGameObject*>* Objects);

};

