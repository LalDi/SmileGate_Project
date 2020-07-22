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

	@brief	이미지 파일을 찾아서 변수에 추가한 후, 그 이미지를 반환.

	@remark	이미지 파일에 이름을 할당하여 저장하고, 이미 저장된 이름으로 이미지를 불러온다면,
	@remark 새로 추가하지 않고 저장된 변수에서 이미지를 찾아서 반환

	@param	key			- 추가할 이미지 파일의 이름
	@param	path		- 추가할 이미지 파일의 경로

	@return	cTexture*	- 추가한 이미지를 반환. 혹은 추가한 이름을 갖는 이미지를 찾아서 반환.
*/
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

/**
	@fn		cImageManager::FindImage(string&)

	@brief	이미지 파일을 찾아서 그 이미지를 반환.

	@remark	AddImage함수로 추가한 이미지를 탐색. 탐색의 기능만 있기 때문에 새로운 이미지를 추가할 수는 없다.

	@param	key			- 이미지 파일의 이름

	@return	cTexture*	- 설정한 이름을 갖는 이미지를 찾아서 반환.
*/
cTexture* cImageManager::FindImage(const string& key)
{
	auto find = m_images.find(key);//이름으로 이미지를 찾아본다
	if (find == m_images.end()) return nullptr;//없으면 nullptr을 뱉는다
	return find->second;//있으면 그걸 뱉는다
}

/**
	@fn		cImageManager::AddAnimation(string&, string&, int)

	@brief	애니메이션 파일을 찾아서 변수에 추가한 후, 그 애니메이션을 반환.

	@remark	AddImage함수와 같은 방법으로 애니메이션을 추가
	@remark 이미지를 불러오는 과정에서 하나라도 이미지가 로딩되지 않는다면 nullptr을 반환한다.
	@remark 이미지 파일의 이름은 (이미지 파일의 이름)번호.png의 형식으로 이루어 져야 한다.

	@param	key		- 추가할 이미지 파일의 이름
	@param	path	- 추가할 이미지 파일의 경로
	@param	amount	- 애니메이션을 사용할 이미지 파일의 개수

	@return	vector<cTexture*>*	- 추가한 애니메이션을 반환. 혹은 추가한 이름을 갖는 애니메이션을 찾아서 반환.
*/
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
			sprintf(Key, "%s%d.png", path.c_str(), i);

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

/**
	@fn		cImageManager::FindAnimation(string&)

	@brief	애니메이션 파일을 찾아서 그 애니메이션을 반환.

	@remark	AddAnimation함수로 추가한 이미지를 탐색. 탐색의 기능만 있기 때문에 새로운 애니메이션을 추가할 수는 없다.

	@param	key		- 애니메이션 파일의 이름

	@return	vector<cTexture*>*	- 설정한 이름을 갖는 애니메이션을 찾아서 반환.
*/
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

/**
	@fn		cImageManager::Render(cTexture*, float, float, float, float, D3DCOLOR)

	@brief	이미지 파일을 화면에 출력함.

	@param	texturePtr	- 출력할 이미지 파일
	@param	x			- 화면상의 가로 위치
	@param	y			- 화면상의 세로 위치
	@param	size		- 출력할 이미지 파일의 크기 배율
	@param	rot			- 출력할 이미지 파일의 각도 Degree값으로 입력.
	@param	color		- 출력할 이미지 파일의 컬러값. 기본값은 (255, 255, 255)
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

	@brief	이미지 파일을 화면에 출력함.

	@remark 인수 중 size값을 POINT로 받아서 가로와 세로의 배율을 따로 조정하도록 설정.

	@param	texturePtr	- 출력할 이미지 파일
	@param	x			- 화면상의 가로 위치
	@param	y			- 화면상의 세로 위치
	@param	size		- 출력할 이미지 파일의 크기 배율
	@param	rot			- 출력할 이미지 파일의 각도 Degree값으로 입력.
	@param	color		- 출력할 이미지 파일의 컬러값. 기본값은 (255, 255, 255)
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

	@brief	이미지 파일을 화면에 출력함.

	@remark 인수 중 size값을 POINT로 받아서 가로와 세로의 배율을 따로 조정하도록 설정.

	@param	texturePtr	- 출력할 이미지 파일
	@param	x			- 화면상의 가로 위치
	@param	y			- 화면상의 세로 위치
	@param	rect		- 이미지를 출력할 범위
	@param	size		- 출력할 이미지 파일의 크기 배율
	@param	rot			- 출력할 이미지 파일의 각도 Degree값으로 입력.
	@param	color		- 출력할 이미지 파일의 컬러값. 기본값은 (255, 255, 255)
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

	@brief	이미지 파일을 화면에 출력함.

	@remark 주로 수정되지 않는 인자인 size와 color를 기본값으로 고정시켜 함수를 간략화한 것.

	@remark 인수 중 size값을 1로 고정
	@remark 인수 중 color값을 (255, 255, 255)로 고정.

	@param	texturePtr	- 출력할 이미지 파일
	@param	x			- 화면상의 가로 위치
	@param	y			- 화면상의 세로 위치
	@param	rot			- 출력할 이미지 파일의 각도 Degree값으로 입력. 기본값은 0
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

	@brief	이미지 파일을 화면에 출력함.

	@remark 이미지 출력 위치를 이미지 좌상단이 아닌, 이미지 중앙을 기준으로 출력
	@remark 인수는 Render함수를 따라감
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

	@brief	텍스트를 화면에 출력함.

	@param	Text	- 출력할 텍스트의 문구
	@param	Size	- ?
	@param	Pos		- 텍스트를 출력할 위치. 텍스트의 좌상단을 기준으로 함.
	@param	Scale	- 텍스트의 크기. 기본값은 1.
	@param	Kor		- 출력할 텍스트가 한국어인지 확인. 기본값은 false
	@param	Color	- 출력할 텍스트의 색. 기본값은 (255, 255, 255)
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

	@brief	텍스트를 화면에 출력함.

	@param	Text	- 출력할 텍스트의 문구
	@param	Size	- ?
	@param	Pos		- 텍스트를 출력할 위치. 텍스트의 중앙을 기준으로 함.
	@param	Scale	- 텍스트의 크기. 기본값은 1.
	@param	Kor		- 출력할 텍스트가 한국어인지 확인. 기본값은 false
	@param	Color	- 출력할 텍스트의 색. 기본값은 (255, 255, 255)
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
