#pragma once
class cUI_Button_SeleteCard1 : public cUI_Button
{
private:
	cPlayer* m_Player;
	bool* b_IsPause;

public:
	cUI_Button_SeleteCard1(POINT Pos, int tag, cPlayer* Player, bool* Pause);
	~cUI_Button_SeleteCard1();

	virtual void Update() override;
	virtual void ClickButton() override;
};

