#pragma once
/**
	@brief	���ʹ��� �Ӽ��� �����ϴ� ���Ű�

	@param	The_Hierophant		- ��Ȳ	/ Wheel_of_Fortune�� ����.	Judgment�� ����.
	@param	The_Hermit			- ������	/ The_Sun�� ����.			Wheel_of_Fortune�� ����.
	@param	The_Magician		- ������	/ Judgment�� ����.			The_Sun�� ����.
*/
enum class EnemyState
{
	The_Hierophant,	// - ��Ȳ / Wheel_of_Fortune�� ����. Judgment�� ����.
	The_Hermit,		// - ������ / The_Sun�� ����. Wheel_of_Fortune�� ����.
	The_Magician	// - ������ / Judgment�� ����. The_Sun�� ����.
};

/**
	@brief	���ʹ��� �⺻ ����� ��� �ִ� Ŭ����
*/
class cEnemy : public cGameObject
{
protected:
	int m_Hp;
	int m_MaxHp;
	float m_Speed;
	float m_AttackSpeed;
	int m_GiveScore;
	EnemyState m_EnemyState;

	time_t m_FireTime;
	bool b_Fire = false;

public:
	cEnemy(POINT Pos, int tag);
	virtual ~cEnemy();

	virtual void Update() override;
	virtual void Render() override;

	cGameObject* Fire(int Angle = 0, float Speed = 1500);	// ���ʹ̰� �߻��ϴ� �Ѿ��� �����͸� ��ȯ�ϴ� �Լ�

	bool CheckOutMap();

	/**
		@fn			Attack(list<cGameObject*>*)
		@brief		���ʹ��� ���� ������ ���� �Լ�
		@remark		cScene���� ������Ʈ�� ����Ʈ�� �ּҸ� �޾ƿ� �Ѿ��� �����Ͽ� push�Ѵ�.
		@param		Objects	- ������Ʈ�� �۵��� �����ϴ� list�� �ּ�
	*/
	virtual void Attack(list<cGameObject*> *Objects) PURE;

	int GetHp() { return m_Hp; }
	void SetHp(int value) { m_Hp = value; }
	void MinusHp(int value) { m_Hp -= value; }
	int GetScore() { return m_GiveScore; }
	EnemyState GetEnemyState() { return m_EnemyState; }

	bool GetIsFire() { return b_Fire; }

};

