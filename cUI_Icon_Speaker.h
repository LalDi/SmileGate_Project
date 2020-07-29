#pragma once
class cUI_Icon_Speaker : public cGameObject
{
private:

public:
	cUI_Icon_Speaker(POINT Pos, int tag);
	~cUI_Icon_Speaker();

	virtual void Update() override;
	virtual void Render() override;
};

