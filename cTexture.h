#pragma once
class cTexture
{
public:
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;

	cTexture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info);
	~cTexture();

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

