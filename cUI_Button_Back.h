#pragma once
class cUI_Button_Back : public cUI_Button
{
private:

public:
	cUI_Button_Back(POINT Pos, int tag);
	~cUI_Button_Back();

	virtual void ClickButton() override;
	virtual void Update() override;
	virtual void Render() override;
};

