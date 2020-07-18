#pragma once
/**
	@brief	���� ������Ʈ�� ������ �⺻ ������ �Լ��� �����ϴ� Ŭ����
*/
class cGameObject abstract
{
protected:
	POINT			m_Pos;		// ������Ʈ�� ��ġ
	RECT			m_Rect;		// ������Ʈ�� ũ�⸦ Rect�������� ����
	INT				m_Radius;	// ������Ʈ�� ũ�⸦ �������� ����. ������ ���� ������.
	cTexture*		m_Sprite;	// ������Ʈ�� ��µǴ� �̹��� ����
	FLOAT			m_Scale;	// ������Ʈ�� ũ��

public:
	INT				m_Tag;		// ������Ʈ�� ��ɺ��� �����ϴ� �±�. Framework.h ����
	BOOL			b_IsLive;	// ������Ʈ�� ����ִ����� ����. false���, ����ó��

	cGameObject(POINT Pos, int tag = 0);
	virtual ~cGameObject();

	virtual void Update() PURE;
	virtual void Render() PURE;

	POINT GetPos() { return m_Pos; }
	RECT GetRect() { return m_Rect; }

	void SetRect();
};

