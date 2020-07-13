#pragma once
class cUI_Score : public cGameObject
{
private:
	int* m_Score;
	wchar_t m_Text[32];

public:
	cUI_Score(POINT Pos, int tag, int* Score);
	~cUI_Score();

	virtual void Update() override;
	virtual void Render() override;
};

