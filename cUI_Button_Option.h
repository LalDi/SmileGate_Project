#pragma once
class cUI_Button_Option : public cUI_Button
{
private:
	bool* b_PlayBgm;

public:
	cUI_Button_Option(POINT Pos, int tag, bool* BGM);
	~cUI_Button_Option();

	virtual void ClickButton() override;
	virtual void Update() override;
	virtual void Render() override;
};

