#pragma once
/**
	@brief	게임 오브젝트가 가지는 기본 변수와 함수를 포함하는 클래스
*/
class cGameObject abstract
{
protected:
	POINT			m_Pos;		// 오브젝트의 위치
	RECT			m_Rect;		// 오브젝트의 크기를 Rect형식으로 저장
	INT				m_Radius;	// 오브젝트가 크기를 원형으로 저장. 반지름 값을 저장함.
	cTexture*		m_Sprite;	// 오브젝트가 출력되는 이미지 파일
	FLOAT			m_Scale;	// 오브젝트의 크기

public:
	INT				m_Tag;		// 오브젝트를 기능별로 구분하는 태그. Framework.h 참조
	BOOL			b_IsLive;	// 오브젝트가 살아있는지를 구분. false라면, 삭제처리

	cGameObject(POINT Pos, int tag = 0);
	virtual ~cGameObject();

	virtual void Update() PURE;
	virtual void Render() PURE;

	POINT GetPos() { return m_Pos; }
	RECT GetRect() { return m_Rect; }

	void SetRect();
};

