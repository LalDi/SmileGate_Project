#pragma once
class cEnemy4 : public cEnemy
{
private:
	int m_Angle;
	int m_MaxBullet;

public:
	cEnemy4(POINT Pos, int tag, int Angle, EnemyState EnemyState);
	~cEnemy4();

	virtual void Update() override;

	virtual void Attack(list<cGameObject*>* Objects) override;
};
