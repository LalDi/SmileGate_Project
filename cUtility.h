#pragma once

namespace Math
{
	BOOL IsPointInRect(const RECT rt, const POINT pt);
	BOOL IsPointInCircle(const POINT ptCircle, const int cr, const POINT pt);
	RECT* rtIntersectRect(const RECT rt1, const RECT rt2);
	BOOL RectCrashCheck(const RECT rt1, const RECT rt2);
	BOOL CircleCrashCheck(POINT ptCircle1, int r1, POINT ptCircle2, int r2);
	BOOL RectCircleCrashCheck(POINT ptCircle, int r, const RECT Rect);

	template<typename T>
	T Lerp(T _S, T _E, float _T)
	{
		return _S + (_E - _S) * _T;
	}
	int Random(int _Min, int _Max);
	float Random(float _Min, float _Max);
	float Clamp(float _Val, float _Min, float _Max);
}