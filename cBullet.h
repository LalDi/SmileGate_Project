#pragma once
class cBullet : public cGameObject
{
private:
	float m_Speed;
	int m_Damage;
	int m_Angle;

public:
	cBullet(POINT Pos, int tag, int Damage, int Angle = 0, float Speed = 1500);
	~cBullet();

	virtual void Update() override;
	virtual void Render() override;
	bool CheckOutMap();

	int GetDamage() { return m_Damage; }
};

