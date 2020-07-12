#pragma once
class cUI_Bomb : public cGameObject
{
private:
	cPlayer* m_Player;

	int m_Bomb;

public:
	cUI_Bomb(POINT Pos, int tag, cPlayer* Player);
	~cUI_Bomb();

	virtual void Update() override;
	virtual void Render() override;
};
