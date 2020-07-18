#pragma once
/**
	@brief	이미지 파일의 데이터를 갖는 클래스
	@brief	변수처럼 사용되며, 내부에 포함된 렌더 함수를 통해 이미지를 출력
*/
class cTexture
{
public:
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;

	cTexture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info);
	~cTexture();

	// 함수의 자세한 설명은 cImageManager 참고
	void Render(float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(float x, float y, float rot = 0);

	void CenterRender(float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(float x, float y, float rot = 0);

	void Render(POINT pos, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(POINT pos, POINT size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(POINT pos, float rot = 0);

	void CenterRender(POINT pos, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(POINT pos, POINT size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(POINT pos, float rot = 0);
};

