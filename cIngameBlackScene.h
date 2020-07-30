#pragma once
class cIngameBlackScene : public cGameObject
{
private:
	float m_Speed;
	bool b_GoLeft;
	bool b_Disappear = false;
	bool b_ScreenBlack = false;

public:
	cIngameBlackScene(POINT Pos, int tag);
	~cIngameBlackScene();

	virtual void Update() override;
	virtual void Render() override;

	bool GetScreenBlack() { return b_ScreenBlack; }

	bool GetDisappear() { return b_Disappear; }
	void SetDisappear(bool value) { b_Disappear = value; }
};

