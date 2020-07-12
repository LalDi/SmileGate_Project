#pragma once
class cItem_Power : public cItem
{
private:
	int m_PlusScore;
	int m_PlusPower;
public:
	cItem_Power(POINT Pos, int tag, cPlayer* Player, int* Score);
	~cItem_Power();

	virtual void GetItem() override;
};

