#pragma once
class cOptionBackground : public cGameObject
{
private:

public:
	cOptionBackground(POINT Pos, int tag);
	~cOptionBackground();

	virtual void Update() override;
	virtual void Render() override;

};

