#pragma once
class cUI_Button_Gamestart : public cUI_Button
{
private:

public:
	cUI_Button_Gamestart(POINT Pos, int tag);
	~cUI_Button_Gamestart();

	virtual void Update() override;
	virtual void Render() override;
};

