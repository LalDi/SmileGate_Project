#pragma once
class cUI_Button_Credit : public cUI_Button
{
private:

public:
	cUI_Button_Credit(POINT Pos, int tag);
	~cUI_Button_Credit();

	virtual void Update() override;
	virtual void Render() override;
};

