#pragma once
class cBoss : public cEnemy
{
protected:

public:
	cBoss(POINT Pos, int tag);
	virtual ~cBoss();

	virtual void Update() override;
	virtual void Render() override;
};