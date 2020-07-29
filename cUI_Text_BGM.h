#pragma once
class cUI_Text_BGM : public cGameObject
{
private:
	
public:
	cUI_Text_BGM(POINT Pos, int tag);
	~cUI_Text_BGM();

	virtual void Update() override;
	virtual void Render() override;
};

