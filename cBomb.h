#pragma once
class cBomb : public cGameObject
{
private:
	int m_Alpha;
	bool b_IsFull;

public:
	cBomb(POINT Pos, int tag);
	~cBomb();

	virtual void Update() override;
	virtual void Render() override;
};

