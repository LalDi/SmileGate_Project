#pragma once
class cUI_Gameover_Background : public cGameObject
{
private:
	int m_Score;
	wchar_t m_Text[32];

public:
	cUI_Gameover_Background(POINT Pos, int tag, int Score);
	~cUI_Gameover_Background();

	virtual void Update() override;
	virtual void Render() override;
};

