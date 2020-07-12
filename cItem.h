#pragma once
class cItem : public cGameObject
{
protected:
	cPlayer* m_Player;

	float m_Speed;
	int* m_Score;

public:
	cItem(POINT Pos, int tag, cPlayer* Player, int* Score);
	virtual ~cItem();

	virtual void Update() override;
	virtual void Render() override;

	bool CheckOutMap();
	virtual void GetItem() PURE;
};

