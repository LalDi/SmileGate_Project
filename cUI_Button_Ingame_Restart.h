#pragma once
class cUI_Button_Ingame_Restart : public cUI_Button
{
public:
	cUI_Button_Ingame_Restart(POINT Pos, int tag);
	~cUI_Button_Ingame_Restart();

	virtual void Update() override;
	virtual void Render() override;

	virtual void ClickButton() override;
};

