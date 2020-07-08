#pragma once
class cUI_Button : public cGameObject
{
protected:
	bool b_IsCenter = true;
public:
	cUI_Button(POINT Pos, int tag);
	virtual ~cUI_Button();

	virtual void Update() PURE;
	virtual void Render() override;

	bool CheckMouseOnButton();
};

