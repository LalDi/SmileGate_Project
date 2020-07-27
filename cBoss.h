#pragma once
/**
	@brief	보스 에너미의 기본 기능을 담고 있는 클래스
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

	cGameObject* Fire(int x, int y, int Angle = 0, float Speed = 1500);	// 에너미가 발사하는 총알의 데이터를 반환하는 함수
	bool Appear(POINT Pos);
	bool DisAppear();
	void Pause(bool Pause);

	/**
		@fn			Attack(list<cGameObject*>*)
		@brief		에너미의 공격 패턴을 담은 함수
		@remark		cScene에서 오브젝트의 리스트의 주소를 받아와 오브젝트를 생성하여 push한다.
		@param		Objects	- 오브젝트의 작동을 관리하는 list의 주소
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