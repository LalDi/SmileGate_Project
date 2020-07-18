#pragma once
/**
	@brief	�ΰ��ӿ��� ���� UI��, ��ư ������ UI�� �⺻ ����� ���� Ŭ����
*/
class cUI_Button : public cGameObject
{
protected:
	bool b_IsCenter = true;		// ��ư�� ����� �߾��� �������� �ϴ��� Ȯ��
	bool b_IsOnMouseUp = true;	// ��ư�� ���� ���콺�� �÷��� �� ��ư�� Ŀ���� ȿ���� ������ �� ���� Ȯ��

public:
	cUI_Button(POINT Pos, int tag);
	virtual ~cUI_Button();

	virtual void Update() override;
	virtual void Render() override;
	virtual void ClickButton() PURE; // ��ư�� Ŭ������ �� ������ �Լ�

	bool CheckMouseOnButton(); // ��ư ���� ���콺�� �ö󰬴��� Ȯ���ϴ� �Լ�
};

