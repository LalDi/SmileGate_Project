#pragma once
class cTitleBackground : public cGameObject
{
private:

public:
	cTitleBackground(POINT Pos, int tag);
	~cTitleBackground();

	virtual void Update() override;
	virtual void Render() override;
};

