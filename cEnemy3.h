#pragma once
class cEnemy3 : public cEnemy
{
private:
	int m_Angle;
	int m_Rotate;

public:
	cEnemy3(POINT Pos, int tag, int Angle, EnemyState EnemyState);
	~cEnemy3();

	virtual void Update() override;
	virtual void Render() override;

	virtual void Attack(list<cGameObject*>* Objects) override;
};
