#pragma once

class cImageManager
{
private:
	LPD3DXSPRITE m_sprite;
	map<std::string, cTexture*> m_images;
	map<string, vector<cTexture*>*> m_Animations;
	LPD3DXFONT m_Fonts[33];
	LPD3DXFONT m_FontsKor[33];
	D3DXMATRIX m_Mat;

private:
	void Init();
	void Release();

public:
	cImageManager();
	~cImageManager();

	cTexture* AddImage(const string& key, const string& path);
	cTexture* FindImage(const string& key);
	vector<cTexture*>* AddAnimation(string key, const string& path, int amount);
	vector<cTexture*>* FindAnimation(string key);


	void Begin();
	void End();

	void Render(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, float rot = 0);
	//좌상단을 기준으로 이미지 랜더링

	void CenterRender(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, float rot = 0);
	//가운데를 기준으로 이미지 랜더링

	void RenderText(wstring Text, int Size, POINT Pos, float Scale, bool Kor, D3DCOLOR Color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRenderText(wstring Text, int Size, POINT Pos, float Scale, bool Kor, D3DCOLOR Color = D3DCOLOR_XRGB(255, 255, 255));
	// 텍스트 렌더링

	void LostDevice();
	void ResetDevice();
	//함수의 인자는 기본적으로 4개까지 사용하는것이 좋다.(4개를 넘어가면 급격히 느려진다)
	//자세한 이유는 나중에 레지스터와 시스템 캐시를 공부할때 알아보면 좋음
};