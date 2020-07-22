#pragma once
class cUI_Button_HTP_Next : public cUI_Button
{
private:
	Page* m_Page;

public:
	cUI_Button_HTP_Next(POINT Pos, int tag, Page* Page);
	~cUI_Button_HTP_Next();

	virtual void ClickButton() override;
};
