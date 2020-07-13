#pragma once
class cUI_Button_Pause_Title : public cUI_Button
{
private:
	bool* b_IsPause;

public:
	cUI_Button_Pause_Title(POINT Pos, int tag, bool* Pause);
	~cUI_Button_Pause_Title();

	virtual void Update() override;
	virtual void Render() override;
	virtual void ClickButton() override;
};

