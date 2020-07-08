#pragma once
class cUI_Button_HowToPlay : public cUI_Button
{
private:

public:
	cUI_Button_HowToPlay(POINT Pos, int tag);
	~cUI_Button_HowToPlay();

	virtual void Update() override;
	virtual void Render() override;
};

