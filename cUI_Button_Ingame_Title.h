#pragma once
class cUI_Button_Ingame_Title : public cUI_Button
{
public:
	cUI_Button_Ingame_Title(POINT Pos, int tag);
	~cUI_Button_Ingame_Title();

	virtual void Update() override;
	virtual void Render() override;

	virtual void ClickButton() override;

};

