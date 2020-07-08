#include "Framework.h"

cTexture::cTexture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
    :texturePtr(texturePtr), info(info)
{
}

cTexture::~cTexture()
{
}

void cTexture::Render(float x, float y, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->Render(this, x, y, size, rot, color);
}

void cTexture::Render(float x, float y, float rot)
{
	IMAGEMANAGER->Render(this, x, y, rot);
}

void cTexture::CenterRender(float x, float y, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->CenterRender(this, x, y, size, rot, color);
}

void cTexture::CenterRender(float x, float y, float rot)
{
	IMAGEMANAGER->CenterRender(this, x, y, rot);
}

void cTexture::Render(POINT pos, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->Render(this, pos.x, pos.y, size, rot, color);
}

void cTexture::Render(POINT pos, float rot)
{
	IMAGEMANAGER->Render(this, pos.x, pos.y, rot);
}

void cTexture::CenterRender(POINT pos, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->CenterRender(this, pos.x, pos.y, size, rot, color);
}

void cTexture::CenterRender(POINT pos, float rot)
{
	IMAGEMANAGER->CenterRender(this, pos.x, pos.y, rot);
}
