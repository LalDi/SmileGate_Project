#pragma once
class cUI_Character : public cGameObject
{
private:
	cTexture* m_Sprite_Chara;

public:
	cUI_Character(POINT Pos, int tag);
	~cUI_Character();

	virtual void Update() override;
	virtual void Render() override;

};

