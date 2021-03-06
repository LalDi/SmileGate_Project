#pragma once
/**
	@brief	플레이어의 속성을 지정하는 열거값
	
	@param	Wheel_of_Fortune	- 기본형 / 공격력 2, 체력 5, 폭탄 공격력 10
	@param	Judgement			- 방어형 / 공격력 1, 체력 7, 폭탄 공격력 8
	@param	The_Sun				- 공격형 / 공격력 4, 체력 3, 폭탄 공격력 15
*/
enum class PlayerState
{
	Wheel_of_Fortune,	// 기본형
	Judgement,			// 방어형
	The_Sun				// 공격형
};

class cPlayer : public cGameObject
{
private:
	PlayerState m_PlayerState;	// 플레이어 속성값

	int m_MaxHp;		// 최대 체력
	int m_Hp;			// 현재 체력

	int m_Damage;		// 플레이어 공격력

	int m_Bomb;			// 폭탄 개수
	int m_MaxBomb;		// 폭탄 최대 개수
	int m_BombDamage;	// 폭탄 공격력

	int m_Power;		// 파워 게이지
	int m_MaxPower;		// 파워 최대치

	float m_Speed;		// 플레이어 이동속도
	float m_AttackSpeed;// 플레이어 공격속도 (총알 초당 발사 개수)

	bool b_GracePeriod;	// 플레이어 무적

	bool b_Fire = false;	// 플레이어 공격
	bool b_Bomb = false;	// 플레이어 폭탄
	bool b_Change = false;	// 플레이어 카드 변경

	bool b_PlayerControl = true;	//	플레이어 조작 권한

	time_t m_FireTime;

public:
	cPlayer(POINT Pos, int tag);
	~cPlayer();

	virtual void Update() override;
	virtual void Render() override;

	cGameObject* Fire();
	cGameObject* Bomb();

	void SetPlayerState();

	int GetDamage() { return m_Damage; }
	int GetBombDamage() { return m_BombDamage; }

	int GetMaxHp() { return m_MaxHp; }

	int GetHp()	{ return m_Hp; }
	void SetHp(int value) { m_Hp = value <= m_MaxHp ? value : m_MaxHp; }
	void MinusHp(int value) { m_Hp -= value; }

	int GetBomb() { return m_Bomb; }
	int GetMaxBomb() { return m_MaxBomb; }
	void SetBomb(int value) { m_Bomb = value <= m_MaxBomb ? value : m_MaxBomb; }

	int GetPower() { return m_Power; }
	int GetMaxPower() { return m_MaxPower; }
	void SetPower(int value) { m_Power = value <= m_MaxPower ? value : m_MaxPower; }

	bool GetGracePeriod() { return b_GracePeriod; }
	void SetGracePeriod(bool value) { b_GracePeriod = value; }

	PlayerState GetPlayerState() { return m_PlayerState; }
	void SetPlayerState(PlayerState value) { m_PlayerState = value; SetPlayerState(); }

	bool GetIsFire() { return b_Fire; }
	bool GetIsBomb() { return b_Bomb; }
	bool GetIsChange() { return b_Change; }
	void SetIsChange(bool value) { b_Change = value; }

	bool GetPlayerControl() { return b_PlayerControl; }
	void SetPlayerControl(bool value) { b_PlayerControl = value; }
};