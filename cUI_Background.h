#pragma once
class cUI_Background : public cGameObject
{
private:

public:
	cUI_Background(POINT Pos, int tag);
	~cUI_Background();

	virtual void Update() override;
	virtual void Render() override;
};

