#pragma once
class cUI_Button_Pause_Reset : public cUI_Button
{
private:
	bool* b_IsPause;

public:
	cUI_Button_Pause_Reset(POINT Pos, int tag, bool* Pause);
	~cUI_Button_Pause_Reset();

	virtual void Update() override;
	virtual void Render() override;

	virtual void ClickButton() override;
};

