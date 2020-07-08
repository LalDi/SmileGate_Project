#pragma once
class cGameObject abstract
{
protected:
	POINT			m_Pos;
	RECT			m_Rect;
	INT				m_Radius;
	cTexture*		m_Sprite;

public:
	FLOAT			m_Scale;
	INT				m_Tag;
	std::string		m_Name;
	BOOL			b_IsLive;

	cGameObject(POINT Pos, int tag = 0);
	virtual ~cGameObject();

	virtual void Update() PURE;
	virtual void Render() PURE;

	POINT GetPos() { return m_Pos; }
	RECT GetRect() { return m_Rect; }

	void SetRect();
};

