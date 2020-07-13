#pragma once
class cUI_Button : public cGameObject
{
protected:
	bool b_IsCenter = true;
	bool b_IsOnMouseUp = true;

public:
	cUI_Button(POINT Pos, int tag);
	virtual ~cUI_Button();

	virtual void Update() override;
	virtual void Render() override;
	virtual void ClickButton() PURE;

	bool CheckMouseOnButton();
};

