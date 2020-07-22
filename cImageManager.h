#pragma once
/**
	@brief 프로그램의 화면 출력 전반을 관리하는 매니저
	@brief 이미지파일의 저장, 이미지 및 텍스트의 출력을 한다.
*/
class cImageManager
{
private:
	LPD3DXSPRITE m_sprite;
	map<std::string, cTexture*> m_images;			// 이미지 파일에 이름을 붙여 저장
	map<string, vector<cTexture*>*> m_Animations;	// 애니메이션 파일에 이름을 붙여 저장
	LPD3DXFONT m_Fonts[33];							// 영문 폰트
	LPD3DXFONT m_FontsKor[33];						// 한글 폰트
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

	void Render(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, RECT rect, POINT size, float rot = 0, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, float rot = 0);
	//좌상단을 기준으로 이미지 랜더링

	void CenterRender(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, RECT rect, POINT size, float rot = 0, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, float rot = 0);
	//가운데를 기준으로 이미지 랜더링

	void RenderText(wstring Text, int Size, POINT Pos, float Scale = 1, bool Kor = false, D3DCOLOR Color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void CenterRenderText(wstring Text, int Size, POINT Pos, float Scale = 1, bool Kor = false, D3DCOLOR Color = D3DCOLOR_RGBA(255, 255, 255, 255));
	// 텍스트 렌더링

	void LostDevice();
	void ResetDevice();
};