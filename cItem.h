#pragma once
class cItem : public cGameObject
{
protected:
	cPlayer* m_Player;	// 아이템의 효과를 적용시킬 플레이어의 포인터
	int* m_Score;		// 아이템의 효과를 적용시킬 점수값의 포인터	

	float m_Speed;		

public:
	cItem(POINT Pos, int tag, cPlayer* Player, int* Score);
	virtual ~cItem();

	virtual void Update() override;
	virtual void Render() override;

	bool CheckOutMap();				// 아이템이 맵 밖으로 나간것을 확인하는 함수
	virtual void GetItem() PURE;	// 플레이어가 아이템을 획득하였을 때 작동하는 함수
};

