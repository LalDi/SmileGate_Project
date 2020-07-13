#pragma once
enum class EnemyState
{

};

class cEnemy : public cGameObject
{
protected:
	int m_Hp;
	int m_MaxHp;
	float m_Speed;
	float m_AttackSpeed;
	EnemyState m_EnemyState;

	time_t m_FireTime;
	bool b_Fire = false;

public:
	cEnemy(POINT Pos, int tag);
	virtual ~cEnemy();

	virtual void Update() override;
	virtual void Render() override;

	cGameObject* Fire();

	virtual void Attack(list<cGameObject*> *Objects) PURE;

	int GetHp() { return m_Hp; }
	void SetHp(int value) { m_Hp = value; }
	void MinusHp(int value) { m_Hp -= value; }
	EnemyState GetEnemyState() { return m_EnemyState; }

	bool GetIsFire() { return b_Fire; }

};

