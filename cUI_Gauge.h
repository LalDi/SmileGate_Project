#pragma once
/**
	@brief	인게임에서 사용될 UI중, 게이지 형식인 UI의 기본 기능을 갖는 클래스
*/
class cUI_Gauge : public cGameObject
{
protected:
	cTexture* m_Sprite_Background;	// 게이지의 배경 이미지

	float m_Amount;					// 게이지가 채워진 정도 (0~1)
	bool b_IsCenter = true;			// 이미지 출력을 중앙에 할 지 여부 확인

public:
	cUI_Gauge(POINT Pos, int tag);
	virtual ~cUI_Gauge();

	virtual void Update() override;
	virtual void Render() override;
};

