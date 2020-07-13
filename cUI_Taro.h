#pragma once
class cUI_Taro : public cGameObject
{
private:
	cTexture* m_TaroCard[3]; // 0 : Default 1 : Defence 2 : Attack
	cPlayer* m_Player;
	PlayerState m_PlayerState;

public:
	cUI_Taro(POINT Pos, int tag, cPlayer* Player);
	~cUI_Taro();

	virtual void Update() override;
	virtual void Render() override;
};

