#pragma once
class cItem_Bomb : public cItem
{
private:
	int m_PlusScore;

public:
	cItem_Bomb(POINT Pos, int tag, cPlayer* Player, int* Score);
	~cItem_Bomb();

	virtual void GetItem() override;
};

