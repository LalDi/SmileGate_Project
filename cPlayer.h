#pragma once
/**
	@brief	�÷��̾��� �Ӽ��� �����ϴ� ���Ű�
	
	@param	Wheel_of_Fortune	- �⺻�� / ���ݷ� 2, ü�� 5, ��ź ���ݷ� 10
	@param	Judgment			- ����� / ���ݷ� 1, ü�� 7, ��ź ���ݷ� 8
	@param	The_Sun				- ������ / ���ݷ� 4, ü�� 3, ��ź ���ݷ� 15
*/
enum class PlayerState
{
	Wheel_of_Fortune,
	Judgement,		
	The_Sun			
};

class cPlayer : public cGameObject
{
private:
	PlayerState m_PlayerState;	// �÷��̾� �Ӽ���

	int m_MaxHp;		// �ִ� ü��
	int m_Hp;			// ���� ü��

	int m_Damage;		// �÷��̾� ���ݷ�

	int m_Bomb;			// ��ź ����
	int m_MaxBomb;		// ��ź �ִ� ����
	int m_BombDamage;	// ��ź ���ݷ�

	int m_Power;		// �Ŀ� ������
	int m_MaxPower;		// �Ŀ� �ִ�ġ

	float m_Speed;		// �÷��̾� �̵��ӵ�
	float m_AttackSpeed;// �÷��̾� ���ݼӵ� (�Ѿ� �ʴ� �߻� ����)

	bool b_GracePeriod;	// �÷��̾� ����

	bool b_Fire = false;// �÷��̾� ����

	time_t m_FireTime;

public:
	cPlayer(POINT Pos, int tag);
	~cPlayer();

	virtual void Update() override;
	virtual void Render() override;

	cGameObject* Fire();

	void SetPlayerState();

	int GetDamage() { return m_Damage; }

	int GetMaxHp() { return m_MaxHp; }

	int GetHp()	{ return m_Hp; }
	void SetHp(int value) { m_Hp = value <= m_MaxHp ? value : m_MaxHp; }
	void MinusHp(int value) { m_Hp -= value; }

	int GetBomb() { return m_Bomb; }
	int GetMaxBomb() { return m_MaxBomb; }
	void SetBomb(int value) { m_Bomb = value <= m_MaxBomb ? value : m_MaxBomb; }

	int GetPower() { return m_Power; }
	int GetMaxPower() { return m_MaxPower; }
	void SetPower(int value) { m_Power = value <= m_Power ? value : m_Power; }

	bool GetGracePeriod() { return b_GracePeriod; }
	void SetGracePeriod(bool value) { b_GracePeriod = value; }

	PlayerState GetPlayerState() { return m_PlayerState; }
	void SetPlayerState(PlayerState value) { m_PlayerState = value; SetPlayerState(); }

	bool GetIsFire() { return b_Fire; }
};