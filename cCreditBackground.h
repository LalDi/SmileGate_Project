#pragma once
class cCreditBackground : public cGameObject
{
private:

public:
	cCreditBackground(POINT Pos, int tag);
	~cCreditBackground();

	virtual void Update() override;
	virtual void Render() override;
};

