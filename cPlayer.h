#pragma once
class cPlayer : public cGameObject
{
private:
	int m_MaxHp;
	int m_Hp;
	int m_Damage;
	int m_Bomb;
	int m_BombDamage;

	float m_Speed;
	float m_AttackSpeed;
	int m_Power;
	int m_MaxPower;
	bool b_GracePeriod;

	bool b_Fire = false;

	time_t m_FireTime;

	enum PlayerState
	{
		Wheel_of_Fortune,	// 기본형
		Judgement,			// 방어형
		The_Sun				// 공격형
	};
	PlayerState m_PlayerState;

public:
	cPlayer(POINT Pos, int tag);
	~cPlayer();

	virtual void Update() override;
	virtual void Render() override;

	cGameObject* Fire();

	void SetPlayerState();

	int GetMaxHp() { return m_MaxHp; }
	void SetMaxHp(int value) { m_MaxHp = value; }

	int GetHp() { return m_Hp; }
	void SetHp(int value) { m_Hp = value; }
	void MinusHp(int value) { m_Hp -= value; }

	int GetDamage() { return m_Damage; }
	void SetDamage(int value) { m_Damage = value; }

	bool GetGracePeriod() { return b_GracePeriod; }
	void SetGracePeriod(bool value) { b_GracePeriod = value; }

	PlayerState GetPlayerState() { return m_PlayerState; }
	void SetPlayerState(PlayerState value) { m_PlayerState = value; SetPlayerState(); }

	bool GetIsFire() { return b_Fire; }
};