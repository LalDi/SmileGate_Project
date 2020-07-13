#pragma once
class cUI_Button_Option : public cUI_Button
{
private:

public:
	cUI_Button_Option(POINT Pos, int tag);
	~cUI_Button_Option();

	virtual void ClickButton() override;
	virtual void Update() override;
	virtual void Render() override;
};

