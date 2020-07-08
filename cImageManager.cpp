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

cTexture* cImageManager::AddImage(const std::string& key, const std::string& path)
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

cTexture* cImageManager::FindImage(const std::string& key)
{
	auto find = m_images.find(key);//�̸����� �̹����� ã�ƺ���
	if (find == m_images.end()) return nullptr;//������ nullptr�� ��´�
	return find->second;//������ �װ� ��´�
}

void cImageManager::Init()
{
	D3DXCreateSprite(g_device, &m_sprite);
}

void cImageManager::Release()
{
	for (auto iter : m_images)
	{
		iter.second->texturePtr->Release();
		SAFE_DELETE(iter.second);
	}
	m_images.clear();

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

void cImageManager::CenterRender(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color)
{
	Render(texturePtr, x - texturePtr->info.Width * size / 2, y - texturePtr->info.Height * size / 2, size, rot, color);
}

void cImageManager::CenterRender(cTexture* texturePtr, float x, float y, float rot)
{
	Render(texturePtr, x - texturePtr->info.Width / 2, y - texturePtr->info.Height / 2, rot);
}

void cImageManager::LostDevice()
{
	m_sprite->OnLostDevice();
}

void cImageManager::ResetDevice()
{
	m_sprite->OnResetDevice();
}
