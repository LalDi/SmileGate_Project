#pragma once
class cUI_ChangeCard : public cGameObject
{
private:
	cPlayer* m_Player;

public:
	cUI_ChangeCard(POINT Pos, int tag, cPlayer* Player);
	~cUI_ChangeCard();

	virtual void Update() override;
	virtual void Render() override;
};

