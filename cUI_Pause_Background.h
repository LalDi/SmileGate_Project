#pragma once
class cUI_Pause_Background : public cGameObject
{
private:
	bool* b_IsPause;

public:
	cUI_Pause_Background(POINT Pos, int tag, bool *Pause);
	~cUI_Pause_Background();

	virtual void Update() override;
	virtual void Render() override;
};

