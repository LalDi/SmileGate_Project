#pragma once
class cUI_ChangeCard : public cGameObject
{
private:

public:
	cUI_ChangeCard(POINT Pos, int tag);
	~cUI_ChangeCard();

	virtual void Update() override;
	virtual void Render() override;
};

