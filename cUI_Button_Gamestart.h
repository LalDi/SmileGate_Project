#pragma once
class cUI_Button_Gamestart : public cUI_Button
{
private:
	bool* b_PlayBgm;

public:
	cUI_Button_Gamestart(POINT Pos, int tag, bool* BGM);
	~cUI_Button_Gamestart();

	virtual void ClickButton() override;
	virtual void Update() override;
	virtual void Render() override;
};

