#pragma once
class cUI_PlayerHp : public cGameObject
{
private:
	cPlayer* m_Player;
	cTexture* m_EmptySprite;

	int m_MaxHp;
	int m_Hp;

public:
	cUI_PlayerHp(POINT Pos, int tag, cPlayer* Player);
	~cUI_PlayerHp();

	virtual void Update() override;
	virtual void Render() override;
};

