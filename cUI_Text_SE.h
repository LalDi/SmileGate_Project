#pragma once
class cUI_Text_SE : public cGameObject
{
private:

public:
	cUI_Text_SE(POINT Pos, int tag);
	~cUI_Text_SE();

	virtual void Update() override;
	virtual void Render() override;
};


