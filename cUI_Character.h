#pragma once
class cUI_Character : public cGameObject
{
private:
	cTexture* m_Sprite_Chara;
	cPlayer* m_Player;

public:
	cUI_Character(POINT Pos, int tag, cPlayer* Player);
	~cUI_Character();

	virtual void Update() override;
	virtual void Render() override;

};

