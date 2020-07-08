#pragma once
class cUI_Logo : public cGameObject
{
private:

public:
	cUI_Logo(POINT Pos, int tag);
	~cUI_Logo();

	virtual void Update() override;
	virtual void Render() override;
};

