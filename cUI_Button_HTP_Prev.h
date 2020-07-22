#pragma once
class cUI_Button_HTP_Prev : public cUI_Button
{
private:
	Page* m_Page;

public:
	cUI_Button_HTP_Prev(POINT Pos, int tag, Page* Page);
	~cUI_Button_HTP_Prev();

	virtual void ClickButton() override;
};

