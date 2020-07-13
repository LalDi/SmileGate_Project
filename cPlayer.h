#pragma once
enum class PlayerState
{
	Wheel_of_Fortune,	// 기본형
	Judgement,			// 방어형
	The_Sun				// 공격형
};

class cPlayer : public cGameObject
{
private:
	int m_MaxHp;
	int m_Hp;
	int m_Damage;

	int m_Bomb;
	int m_MaxBomb;
	int m_BombDamage;

	int m_Power;
	int m_MaxPower;

	float m_Speed;
	float m_AttackSpeed;

	bool b_GracePeriod;

	bool b_Fire = false;

	time_t m_FireTime;


	PlayerState m_PlayerState;

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