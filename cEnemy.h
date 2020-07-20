#pragma once
/**
	@brief	에너미의 속성을 지정하는 열거값

	@param	The_Hierophant		- 교황	/ Wheel_of_Fortune에 약함.	Judgment에 강함.
	@param	The_Hermit			- 은둔자	/ The_Sun에 약함.			Wheel_of_Fortune에 강함.
	@param	The_Magician		- 마법사	/ Judgment에 약함.			The_Sun에 강함.
*/
enum class EnemyState
{
	The_Hierophant,	// - 교황 / Wheel_of_Fortune에 약함. Judgment에 강함.
	The_Hermit,		// - 은둔자 / The_Sun에 약함. Wheel_of_Fortune에 강함.
	The_Magician	// - 마법사 / Judgment에 약함. The_Sun에 강함.
};

/**
	@brief	에너미의 기본 기능을 담고 있는 클래스
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

	cGameObject* Fire(int Angle = 0, float Speed = 1500);	// 에너미가 발사하는 총알의 데이터를 반환하는 함수

	bool CheckOutMap();

	/**
		@fn			Attack(list<cGameObject*>*)
		@brief		에너미의 공격 패턴을 담은 함수
		@remark		cScene에서 오브젝트의 리스트의 주소를 받아와 총알을 생성하여 push한다.
		@param		Objects	- 오브젝트의 작동을 관리하는 list의 주소
	*/
	virtual void Attack(list<cGameObject*> *Objects) PURE;

	int GetHp() { return m_Hp; }
	void SetHp(int value) { m_Hp = value; }
	void MinusHp(int value) { m_Hp -= value; }
	int GetScore() { return m_GiveScore; }
	EnemyState GetEnemyState() { return m_EnemyState; }

	bool GetIsFire() { return b_Fire; }

};

