#pragma once
// PROTOTYPE
class cEnemy1 : public cEnemy
{
private:

public:
	cEnemy1(POINT Pos, int tag);
	~cEnemy1();

	virtual void Update() override;
	virtual void Render() override;
};

