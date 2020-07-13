#pragma once
class cUI_Button_Quit : public cUI_Button
{
private:

public:
	cUI_Button_Quit(POINT Pos, int tag);
	~cUI_Button_Quit();

	virtual void ClickButton() override;
	virtual void Update() override;
	virtual void Render() override;
};

