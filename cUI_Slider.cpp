#include "Framework.h"

cUI_Slider::cUI_Slider(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	//�ڽ� ��ü���� �������־�� �ϴ� ����
	//LONG Width = m_BgSprite->info.Width / 2;
	//LONG Height = m_BgSprite->info.Height / 2;
	//m_Rect = { Pos.x - Width, Pos.y - Height, Pos.x + Width, Pos.y + Height };
	m_RenderRect = { 0,0,0,0 };
	b_IsControl = false;
}

cUI_Slider::~cUI_Slider()
{
}

void cUI_Slider::Update()
{
	float Max = m_Max - m_Min;
	
	// ���콺�� Ŭ�� ���� ��
	if (INPUTMANAGER->BtnPress(LEFTCLICK))
	{
		// ���콺�� �����̴� ���� �ִٸ�
		if (Math::IsPointInRect(m_Rect, INPUTMANAGER->GetMousePos()))
		{
			// �����̴� ������ Ȱ��ȭ�ȴ�.
			b_IsControl = true;
		}
	}

	// ���콺�� ����
	if (INPUTMANAGER->BtnUp(LEFTCLICK))
		// �����̴� ������ ��Ȱ��ȭ �ȴ�.
		b_IsControl = false;

	// �����̴� ������ Ȱ��ȭ �Ǿ� ���� ��
	if (b_IsControl)
	{
		// �����̴��� ����� ���콺�� x��ġ�� ���󰣴�.
		m_HandlePos.x = INPUTMANAGER->GetMousePos().x;

		// �����̴��� ����� �����̴� �ٱ����� ������ ���� �����ش�.
		if (m_HandlePos.x <= m_Rect.left)
			m_HandlePos.x = m_Rect.left;
		if (m_HandlePos.x >= m_Rect.right)
			m_HandlePos.x = m_Rect.right;

		// �����̴��� ���� ���������� �����Ǿ� ���� ���, �� ���� �´� ��ġ�� ����� �Ű��ش�.
		if (b_IsInteger)
		{
			for (int i = 0; i < Max; i++)
			{
				int temp = (m_Rect.right - m_Rect.left) / (int)(Max);
				if (m_HandlePos.x >= m_Rect.left + (temp * i) - (temp / 2) &&
					m_HandlePos.x <= m_Rect.left + (temp * i) + (temp / 2))
				{
					m_HandlePos.x = m_Rect.left + (temp * i);
				}
			}
		}
	}

	// �����̴��� ���� �����Ѵ�.
	m_Amount = ((float)(m_HandlePos.x - m_Rect.left) / (float)(m_Rect.right - m_Rect.left)) * Max + m_Min;
	m_Amount = Clamp(m_Amount, m_Min, m_Max);

	// �����̴��� ���� ���������� �����Ǿ� ���� ���, �Ǽ��� ������ ��ȯ�Ѵ�.
	if (b_IsInteger)
		m_Amount = (int)m_Amount;

	m_RenderRect.bottom = m_Sprite->info.Height;
	m_RenderRect.right = m_Sprite->info.Width;

	m_RenderRect.right = m_Sprite->info.Width * ((m_Amount-m_Min) / Max);
}

void cUI_Slider::Render()
{
	POINT Pos = m_Pos;
	//Pos.x += m_RenderRect.left;
	m_BgSprite->CenterRender(m_Pos);
	m_Sprite->CenterRender(Pos, m_RenderRect, POINT{ 1, 1 });
	m_HandleSprite->CenterRender(m_HandlePos);
}
