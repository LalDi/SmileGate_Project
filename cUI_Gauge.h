#pragma once
/**
	@brief	�ΰ��ӿ��� ���� UI��, ������ ������ UI�� �⺻ ����� ���� Ŭ����
*/
class cUI_Gauge : public cGameObject
{
protected:
	cTexture* m_Sprite_Background;	// �������� ��� �̹���

	float m_Amount;					// �������� ä���� ���� (0~1)
	bool b_IsCenter = true;			// �̹��� ����� �߾ӿ� �� �� ���� Ȯ��

public:
	cUI_Gauge(POINT Pos, int tag);
	virtual ~cUI_Gauge();

	virtual void Update() override;
	virtual void Render() override;
};

