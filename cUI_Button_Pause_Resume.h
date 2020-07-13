#pragma once
class cUI_Button_Pause_Resume : public cUI_Button
{
private:
	bool* b_IsPause;

public:
	cUI_Button_Pause_Resume(POINT Pos, int tag, bool* Pause);
	~cUI_Button_Pause_Resume();

	virtual void Update() override;
	virtual void Render() override;
	virtual void ClickButton() override;
};

