#pragma once
class cEnemy5 : public cEnemy
{
private:
	int m_Angle;

public:
	cEnemy5(POINT Pos, int tag, int Angle, EnemyState EnemyState);
	~cEnemy5();

	virtual void Update() override;
	virtual void Render() override;

	virtual void Attack(list<cGameObject*>* Objects) override;
};


