#pragma once
class cUI_Button_OptionBack : public cUI_Button
{
private:

public:
	cUI_Button_OptionBack(POINT Pos, int tag);
	~cUI_Button_OptionBack();

	virtual void ClickButton() override;
	virtual void Update() override;
	virtual void Render() override;
};

