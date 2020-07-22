#pragma once
class cEnemy2 : public cEnemy
{
private:
	int m_Angle;
	cPlayer* m_Player;

public:
	cEnemy2(POINT Pos, int tag, cPlayer* Player, EnemyState EnemyState);
	~cEnemy2();

	virtual void Update() override;

	virtual void Attack(list<cGameObject*>* Objects) override;
};

