#pragma once
/**
	@brief	인게임에서 사용될 UI중, 슬라이더 형식인 UI의 기본 기능을 갖는 클래스
*/
class cUI_Slider : public cGameObject
{
protected:
	cTexture* m_BgSprite;		// 슬라이더의 배경 이미지
	cTexture* m_HandleSprite;	// 슬라이더의 핸들 이미지
	POINT m_HandlePos;			// 슬라이더의 핸들의 위치
	RECT m_RenderRect;			// 렌더링에 사용할 Rect값

	bool b_IsInteger;	// 슬라이더의 값이 정수로 고정되는지 여부

	float m_Min;		// 슬라이더의 값의 최소값
	float m_Max;		// 슬라이더의 값의 최대값
	float m_Amount;		// 슬러이더의 값

	bool b_IsControl;	// 슬라이더값을 조정하는 중인지 확인

public:
	cUI_Slider(POINT Pos, int tag);
	~cUI_Slider();

	virtual void Update() override;
	virtual void Render() override;
};

