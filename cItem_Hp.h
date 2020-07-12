#pragma once
class cItem_Hp : public cItem
{
private:
	int m_PlusScore;

public:
	cItem_Hp(POINT Pos, int tag, cPlayer* Player, int* Score);
	~cItem_Hp();

	virtual void GetItem() override;
};

