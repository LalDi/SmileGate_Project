#include "Framework.h"

cImageManager::cImageManager()
	:m_sprite(nullptr)
{
	Init();
}

cImageManager::~cImageManager()
{
	Release();
}

/**
	@fn		cImageManager::AddImage(string&, string&)

	@brief	�̹��� ������ ã�Ƽ� ������ �߰��� ��, �� �̹����� ��ȯ.

	@remark	�̹��� ���Ͽ� �̸��� �Ҵ��Ͽ� �����ϰ�, �̹� ����� �̸����� �̹����� �ҷ��´ٸ�,
	@remark ���� �߰����� �ʰ� ����� �������� �̹����� ã�Ƽ� ��ȯ

	@param	key			- �߰��� �̹��� ������ �̸�
	@param	path		- �߰��� �̹��� ������ ���

	@return	cTexture*	- �߰��� �̹����� ��ȯ. Ȥ�� �߰��� �̸��� ���� �̹����� ã�Ƽ� ��ȯ.
*/
cTexture* cImageManager::AddImage(const string& key, const string& path)
{
	auto find = m_images.find(key);//�̹� �ִ� �̸��� �ٽ� ������ �ϴ°� �ƴ��� Ȯ���غ���
	if (find == m_images.end())
	{
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;

		if (D3DXCreateTextureFromFileExA(g_device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			cTexture* text = new cTexture(texturePtr, info);
			m_images.insert(make_pair(key, text));
			return text;
		}
		//�̹��� �ε��� �����������(���� ����, cpu�޸� �������) �̰����� ���� �ȴ�
		return nullptr;
	}
	//�̹� �ҷ��� �̹����� �ٽ� �ҷ����� �߰ų�
	//�ٸ� �̹����� ���� �̸����� ���� ������� �̰����� ���� �ȴ�
	return find->second;
}

/**
	@fn		cImageManager::FindImage(string&)

	@brief	�̹��� ������ ã�Ƽ� �� �̹����� ��ȯ.

	@remark	AddImage�Լ��� �߰��� �̹����� Ž��. Ž���� ��ɸ� �ֱ� ������ ���ο� �̹����� �߰��� ���� ����.

	@param	key			- �̹��� ������ �̸�

	@return	cTexture*	- ������ �̸��� ���� �̹����� ã�Ƽ� ��ȯ.
*/
cTexture* cImageManager::FindImage(const string& key)
{
	auto find = m_images.find(key);//�̸����� �̹����� ã�ƺ���
	if (find == m_images.end()) return nullptr;//������ nullptr�� ��´�
	return find->second;//������ �װ� ��´�
}

/**
	@fn		cImageManager::AddAnimation(string&, string&, int)

	@brief	�ִϸ��̼� ������ ã�Ƽ� ������ �߰��� ��, �� �ִϸ��̼��� ��ȯ.

	@remark	AddImage�Լ��� ���� ������� �ִϸ��̼��� �߰�
	@remark �̹����� �ҷ����� �������� �ϳ��� �̹����� �ε����� �ʴ´ٸ� nullptr�� ��ȯ�Ѵ�.
	@remark �̹��� ������ �̸��� (�̹��� ������ �̸�)��ȣ.png�� �������� �̷�� ���� �Ѵ�.

	@param	key		- �߰��� �̹��� ������ �̸�
	@param	path	- �߰��� �̹��� ������ ���
	@param	amount	- �ִϸ��̼��� ����� �̹��� ������ ����

	@return	vector<cTexture*>*	- �߰��� �ִϸ��̼��� ��ȯ. Ȥ�� �߰��� �̸��� ���� �ִϸ��̼��� ã�Ƽ� ��ȯ.
*/
vector<cTexture*>* cImageManager::AddAnimation(string key, const string& path, int amount)
{
	auto find = m_Animations.find(key);//�̹� �ִ� �̸��� �ٽ� ������ �ϴ°� �ƴ��� Ȯ���غ���
	if (find == m_Animations.end())
	{
		char Key[64];
		vector<cTexture*>* Vec = new vector<cTexture*>;
		for (int i = 1; i <= amount; i++)
		{
			LPDIRECT3DTEXTURE9 texturePtr;
			D3DXIMAGE_INFO info;
			sprintf(Key, "%s%d.png", path.c_str(), i);

			if (D3DXCreateTextureFromFileExA(g_device, Key, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
				D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texturePtr) == S_OK)
			{
				Vec->push_back(m_images[Key]);
			}
			else
				return nullptr; // �ϳ��� �̹��� �ε��� �����������(���� ����, �ִϸ��̼� ���� ����, cpu�޸� �������) �̰����� ���� �ȴ�
		}
		m_Animations.insert(make_pair(key, Vec));
	}
	//�̹� �ҷ��� �̹����� �ٽ� �ҷ����� �߰ų�
	//�ٸ� �̹����� ���� �̸����� ���� ������� �̰����� ���� �ȴ�
	return find->second;
}

/**
	@fn		cImageManager::FindAnimation(string&)

	@brief	�ִϸ��̼� ������ ã�Ƽ� �� �ִϸ��̼��� ��ȯ.

	@remark	AddAnimation�Լ��� �߰��� �̹����� Ž��. Ž���� ��ɸ� �ֱ� ������ ���ο� �ִϸ��̼��� �߰��� ���� ����.

	@param	key		- �ִϸ��̼� ������ �̸�

	@return	vector<cTexture*>*	- ������ �̸��� ���� �ִϸ��̼��� ã�Ƽ� ��ȯ.
*/
vector<cTexture*>* cImageManager::FindAnimation(string key)
{
	auto find = m_Animations.find(key);//�̸����� �̹����� ã�ƺ���
	if (find == m_Animations.end()) return nullptr;//������ nullptr�� ��´�
	return find->second;//������ �װ� ��´�
}

void cImageManager::Init()
{
	D3DXCreateSprite(g_device, &m_sprite);
	for (int i = 1; i <= 32; i++)
	{
		D3DXCreateFont(g_device, i, 0, 0, 1, false, DEFAULT_CHARSET, 0, 0, 0, L"System", &m_Fonts[i]);
		D3DXCreateFont(g_device, i, 0, 0, 1, false, DEFAULT_CHARSET, 0, 0, 0, L"�޸յձ�������", &m_FontsKor[i]);
	}
}

void cImageManager::Release()
{
	for (auto iter : m_images)
	{
		iter.second->texturePtr->Release();
		SAFE_DELETE(iter.second);
	}
	for (auto& iter : m_Animations)
	{
		SAFE_DELETE(iter.second);
	}
	for (int i = 1; i <= 32; i++)
	{
		m_Fonts[i]->Release();
		m_FontsKor[i]->Release();
	}
	m_images.clear();
	m_Animations.clear();

	m_sprite->Release();
}

void cImageManager::Begin()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void cImageManager::End()
{
	m_sprite->End();
}

/**
	@fn		cImageManager::Render(cTexture*, float, float, float, float, D3DCOLOR)

	@brief	�̹��� ������ ȭ�鿡 �����.

	@param	texturePtr	- ����� �̹��� ����
	@param	x			- ȭ����� ���� ��ġ
	@param	y			- ȭ����� ���� ��ġ
	@param	size		- ����� �̹��� ������ ũ�� ����
	@param	rot			- ����� �̹��� ������ ���� Degree������ �Է�.
	@param	color		- ����� �̹��� ������ �÷���. �⺻���� (255, 255, 255)
*/
void cImageManager::Render(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIX mat, matS, matR, matT;
		D3DXMatrixScaling(&matS, size, size, size);
		D3DXMatrixRotationZ(&matR, D3DXToRadian(rot));
		D3DXMatrixTranslation(&matT, x, y, 0);
		mat = matS * matR * matT;

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

/**
	@fn		cImageManager::Render(cTexture*, float, float, POINT, float, D3DCOLOR)

	@brief	�̹��� ������ ȭ�鿡 �����.

	@remark �μ� �� size���� POINT�� �޾Ƽ� ���ο� ������ ������ ���� �����ϵ��� ����.

	@param	texturePtr	- ����� �̹��� ����
	@param	x			- ȭ����� ���� ��ġ
	@param	y			- ȭ����� ���� ��ġ
	@param	size		- ����� �̹��� ������ ũ�� ����
	@param	rot			- ����� �̹��� ������ ���� Degree������ �Է�.
	@param	color		- ����� �̹��� ������ �÷���. �⺻���� (255, 255, 255)
*/
void cImageManager::Render(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIX mat, matS, matR, matT;
		D3DXMatrixScaling(&matS, size.x, size.y, 1);
		D3DXMatrixRotationZ(&matR, D3DXToRadian(rot));
		D3DXMatrixTranslation(&matT, x, y, 0);
		mat = matS * matR * matT;

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

/**
	@fn		cImageManager::Render(cTexture*, float, float, POINT, float, D3DCOLOR)

	@brief	�̹��� ������ ȭ�鿡 �����.

	@remark �μ� �� size���� POINT�� �޾Ƽ� ���ο� ������ ������ ���� �����ϵ��� ����.

	@param	texturePtr	- ����� �̹��� ����
	@param	x			- ȭ����� ���� ��ġ
	@param	y			- ȭ����� ���� ��ġ
	@param	rect		- �̹����� ����� ����
	@param	size		- ����� �̹��� ������ ũ�� ����
	@param	rot			- ����� �̹��� ������ ���� Degree������ �Է�.
	@param	color		- ����� �̹��� ������ �÷���. �⺻���� (255, 255, 255)
*/
void cImageManager::Render(cTexture* texturePtr, float x, float y, RECT rect, POINT size, float rot, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIX mat, matS, matR, matT;
		D3DXMatrixScaling(&matS, size.x, size.y, 1);
		D3DXMatrixRotationZ(&matR, D3DXToRadian(rot));
		D3DXMatrixTranslation(&matT, x, y, 0);
		mat = matS * matR * matT;

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, &rect, nullptr, nullptr, color);
	}
}

/**
	@fn		cImageManager::Render(cTexture*, float, float, float)

	@brief	�̹��� ������ ȭ�鿡 �����.

	@remark �ַ� �������� �ʴ� ������ size�� color�� �⺻������ �������� �Լ��� ����ȭ�� ��.

	@remark �μ� �� size���� 1�� ����
	@remark �μ� �� color���� (255, 255, 255)�� ����.

	@param	texturePtr	- ����� �̹��� ����
	@param	x			- ȭ����� ���� ��ġ
	@param	y			- ȭ����� ���� ��ġ
	@param	rot			- ����� �̹��� ������ ���� Degree������ �Է�. �⺻���� 0
*/
void cImageManager::Render(cTexture* texturePtr, float x, float y, float rot)
{
	if (texturePtr)
	{
		D3DXMATRIX mat, matS, matR, matT;
		D3DXMatrixScaling(&matS, 1.f, 1.f, 1.f);
		D3DXMatrixRotationZ(&matR, D3DXToRadian(rot));
		D3DXMatrixTranslation(&matT, x, y, 0);
		mat = matS * matR * matT;

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

/**
	@fn		cImageManager::CenterRender(cTexture*, float, float, float, float, D3DCOLOR)
	@fn		cImageManager::CenterRender(cTexture*, float, float, POINT, float, D3DCOLOR)
	@fn		cImageManager::CenterRender(cTexture*, float, float, float)

	@brief	�̹��� ������ ȭ�鿡 �����.

	@remark �̹��� ��� ��ġ�� �̹��� �»���� �ƴ�, �̹��� �߾��� �������� ���
	@remark �μ��� Render�Լ��� ����
*/
void cImageManager::CenterRender(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color)
{
	Render(texturePtr, x - texturePtr->info.Width * size / 2, y - texturePtr->info.Height * size / 2, size, rot, color);
}

void cImageManager::CenterRender(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color)
{
	Render(texturePtr, x - texturePtr->info.Width * size.x / 2, y - texturePtr->info.Height * size.y / 2, size, rot, color);
}

void cImageManager::CenterRender(cTexture* texturePtr, float x, float y, RECT rect, POINT size, float rot, D3DCOLOR color)
{
	Render(texturePtr, x - texturePtr->info.Width * size.x / 2, y - texturePtr->info.Height * size.y / 2, rect, size, rot, color);
}

void cImageManager::CenterRender(cTexture* texturePtr, float x, float y, float rot)
{
	Render(texturePtr, x - texturePtr->info.Width / 2, y - texturePtr->info.Height / 2, rot);
}

/**
	@fn		cImageManager::RenderText(wstring, int, POINT, float, bool, D3DCOLOR)

	@brief	�ؽ�Ʈ�� ȭ�鿡 �����.

	@param	Text	- ����� �ؽ�Ʈ�� ����
	@param	Size	- ?
	@param	Pos		- �ؽ�Ʈ�� ����� ��ġ. �ؽ�Ʈ�� �»���� �������� ��.
	@param	Scale	- �ؽ�Ʈ�� ũ��. �⺻���� 1.
	@param	Kor		- ����� �ؽ�Ʈ�� �ѱ������� Ȯ��. �⺻���� false
	@param	Color	- ����� �ؽ�Ʈ�� ��. �⺻���� (255, 255, 255)
*/
void cImageManager::RenderText(wstring Text, int Size, POINT Pos, float Scale, bool Kor, D3DCOLOR Color)
{
	D3DXVECTOR2 pos = { (float)Pos.x, (float)Pos.y };
	D3DXVECTOR2 scale = { Scale, Scale };
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &scale, NULL, 0, &(pos));
	m_sprite->SetTransform(&m_Mat);
	(Kor ? m_FontsKor[Size] : m_Fonts[Size])->DrawTextW(m_sprite, Text.c_str(), -1, NULL, DT_NOCLIP | DT_CENTER, Color);
}

/**
	@fn		cImageManager::CenterRenderText(wstring, int, POINT, float, bool, D3DCOLOR)

	@brief	�ؽ�Ʈ�� ȭ�鿡 �����.

	@param	Text	- ����� �ؽ�Ʈ�� ����
	@param	Size	- ?
	@param	Pos		- �ؽ�Ʈ�� ����� ��ġ. �ؽ�Ʈ�� �߾��� �������� ��.
	@param	Scale	- �ؽ�Ʈ�� ũ��. �⺻���� 1.
	@param	Kor		- ����� �ؽ�Ʈ�� �ѱ������� Ȯ��. �⺻���� false
	@param	Color	- ����� �ؽ�Ʈ�� ��. �⺻���� (255, 255, 255)
*/
void cImageManager::CenterRenderText(wstring Text, int Size, POINT Pos, float Scale, bool Kor, D3DCOLOR Color)
{
	D3DXVECTOR2 pos = { (float)Pos.x, (float)Pos.y };
	D3DXVECTOR2 scale = { Scale, Scale };
	D3DXVECTOR2 Center;
	RECT Rect;

	Rect.left = Rect.top = 0;
	(Kor ? m_FontsKor[Size] : m_Fonts[Size])->DrawTextW(m_sprite, Text.c_str(), -1, &Rect, DT_NOCLIP | DT_CALCRECT, Color);
	Center = D3DXVECTOR2((float)Rect.right * 0.5f, (float)Rect.bottom * 0.5f);
	D3DXMatrixTransformation2D(&m_Mat, &Center, 0, &scale, &Center, 0, &(pos - Center));
	m_sprite->SetTransform(&m_Mat);
	(Kor ? m_FontsKor[Size] : m_Fonts[Size])->DrawTextW(m_sprite, Text.c_str(), -1, NULL, DT_NOCLIP | DT_CENTER, Color);
}

void cImageManager::LostDevice()
{
	m_sprite->OnLostDevice();
}

void cImageManager::ResetDevice()
{
	m_sprite->OnResetDevice();
}
