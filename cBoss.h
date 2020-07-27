#pragma once
/**
	@brief	���� ���ʹ��� �⺻ ����� ��� �ִ� Ŭ����
*/
class cBoss : public cGameObject
{
protected:
	cPlayer* m_Player;
	
	int m_Hp;
	int m_MaxHp;
	float m_Angle;
	int m_GiveScore;
	bool b_Attack;
	bool b_Attacking;
	EnemyState m_EnemyState;
	cTimer m_AttackTime;

	bool b_Control = true;

public:
	cBoss(POINT Pos, int tag, cPlayer* Player);
	virtual ~cBoss();

	virtual void Update() PURE;
	virtual void Render();

	cGameObject* Fire(int x, int y, int Angle = 0, float Speed = 1500);	// ���ʹ̰� �߻��ϴ� �Ѿ��� �����͸� ��ȯ�ϴ� �Լ�
	bool Appear(POINT Pos);
	bool DisAppear();
	void Pause(bool Pause);

	/**
		@fn			Attack(list<cGameObject*>*)
		@brief		���ʹ��� ���� ������ ���� �Լ�
		@remark		cScene���� ������Ʈ�� ����Ʈ�� �ּҸ� �޾ƿ� ������Ʈ�� �����Ͽ� push�Ѵ�.
		@param		Objects	- ������Ʈ�� �۵��� �����ϴ� list�� �ּ�
	*/
	virtual void Attack(list<cGameObject*>* Objects) PURE;

	int GetHp() { return m_Hp; }
	void SetHp(int value) { m_Hp = value; }
	void MinusHp(int value) { m_Hp -= value; }
	int GetMaxHp() { return m_MaxHp; }
	int GetScore() { return m_GiveScore; }
	bool GetAttack() { return b_Attack; }
	void SetAttack(bool value) { b_Attack = value; }
	EnemyState GetEnemyState() { return m_EnemyState; }

	void SetControl(bool value) { b_Control = value; }
};