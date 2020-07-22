#pragma once
class cUI_Clear_Background : public cGameObject
{
private:

public:
	cUI_Clear_Background(POINT Pos, int tag);
	~cUI_Clear_Background();

	virtual void Update() override;
	virtual void Render() override;
};

