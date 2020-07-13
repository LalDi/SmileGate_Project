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

cTexture* cImageManager::AddImage(const string& key, const string& path)
{
	auto find = m_images.find(key);//이미 있는 이름을 다시 쓰려고 하는게 아닌지 확인해본다
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
		//이미지 로딩이 실패했을경우(없는 파일, cpu메모리 부족등등) 이곳으로 오게 된다
		return nullptr;
	}
	//이미 불러온 이미지를 다시 불러오려 했거나
	//다른 이미지를 같은 이름으로 쓰고 있을경우 이곳으로 오게 된다
	return find->second;
}

cTexture* cImageManager::FindImage(const string& key)
{
	auto find = m_images.find(key);//이름으로 이미지를 찾아본다
	if (find == m_images.end()) return nullptr;//없으면 nullptr을 뱉는다
	return find->second;//있으면 그걸 뱉는다
}

vector<cTexture*>* cImageManager::AddAnimation(string key, const string& path, int amount)
{
	auto find = m_Animations.find(key);//이미 있는 이름을 다시 쓰려고 하는게 아닌지 확인해본다
	if (find == m_Animations.end())
	{
		char Key[64];
		vector<cTexture*>* Vec = new vector<cTexture*>;
		for (int i = 1; i <= amount; i++)
		{
			LPDIRECT3DTEXTURE9 texturePtr;
			D3DXIMAGE_INFO info;
			sprintf(Key, "%s%d", path.c_str(), i);

			if (D3DXCreateTextureFromFileExA(g_device, Key, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
				D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texturePtr) == S_OK)
			{
				Vec->push_back(m_images[Key]);
			}
			else
				return nullptr; // 하나라도 이미지 로딩이 실패했을경우(없는 파일, 애니메이션 개수 오류, cpu메모리 부족등등) 이곳으로 오게 된다
		}
		m_Animations.insert(make_pair(key, Vec));
	}
	//이미 불러온 이미지를 다시 불러오려 했거나
	//다른 이미지를 같은 이름으로 쓰고 있을경우 이곳으로 오게 된다
	return find->second;
}

vector<cTexture*>* cImageManager::FindAnimation(string key)
{
	auto find = m_Animations.find(key);//이름으로 이미지를 찾아본다
	if (find == m_Animations.end()) return nullptr;//없으면 nullptr을 뱉는다
	return find->second;//있으면 그걸 뱉는다
}

void cImageManager::Init()
{
	D3DXCreateSprite(g_device, &m_sprite);
	for (int i = 1; i <= 32; i++)
	{
		D3DXCreateFont(g_device, i, 0, 0, 1, false, DEFAULT_CHARSET, 0, 0, 0, L"System", &m_Fonts[i]);
		D3DXCreateFont(g_device, i, 0, 0, 1, false, DEFAULT_CHARSET, 0, 0, 0, L"휴먼둥근헤드라인", &m_FontsKor[i]);
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

void cImageManager::CenterRender(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color)
{
	Render(texturePtr, x - texturePtr->info.Width * size.x / 2, y - texturePtr->info.Height * size.y / 2, size, rot, color);
}

void cImageManager::CenterRender(cTexture* texturePtr, float x, float y, float rot)
{
	Render(texturePtr, x - texturePtr->info.Width / 2, y - texturePtr->info.Height / 2, rot);
}

void cImageManager::RenderText(wstring Text, int Size, POINT Pos, float Scale, bool Kor, D3DCOLOR Color)
{
	D3DXVECTOR2 pos = { (float)Pos.x, (float)Pos.y };
	D3DXVECTOR2 scale = { Scale, Scale };
	D3DXMatrixTransformation2D(&m_Mat, NULL, 0, &scale, NULL, 0, &(pos));
	m_sprite->SetTransform(&m_Mat);
	(Kor ? m_FontsKor[Size] : m_Fonts[Size])->DrawTextW(m_sprite, Text.c_str(), -1, NULL, DT_NOCLIP | DT_CENTER, Color);
}

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
