#pragma once
class cEnemy1 : public cEnemy
{
private:
	int m_Angle;

public:
	cEnemy1(POINT Pos, int tag, int Angle, EnemyState EnemyState);
	~cEnemy1();

	virtual void Update() override;

	virtual void Attack(list<cGameObject*> *Objects) override;
};

