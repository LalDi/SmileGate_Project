#pragma once
/**
	@brief	�ΰ��ӿ��� ���� UI��, �����̴� ������ UI�� �⺻ ����� ���� Ŭ����
*/
class cUI_Slider : public cGameObject
{
protected:
	cTexture* m_BgSprite;		// �����̴��� ��� �̹���
	cTexture* m_HandleSprite;	// �����̴��� �ڵ� �̹���
	POINT m_HandlePos;			// �����̴��� �ڵ��� ��ġ
	RECT m_RenderRect;			// �������� ����� Rect��

	bool b_IsInteger;	// �����̴��� ���� ������ �����Ǵ��� ����

	float m_Min;		// �����̴��� ���� �ּҰ�
	float m_Max;		// �����̴��� ���� �ִ밪
	float m_Amount;		// �����̴��� ��

	bool b_IsControl;	// �����̴����� �����ϴ� ������ Ȯ��

public:
	cUI_Slider(POINT Pos, int tag);
	~cUI_Slider();

	virtual void Update() override;
	virtual void Render() override;
};

