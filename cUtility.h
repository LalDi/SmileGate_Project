#pragma once

BOOL IsPointInRect(const RECT rt, const POINT pt);
BOOL IsPointInCircle(const POINT ptCircle, const int cr, const POINT pt);
RECT* rtIntersectRect(const RECT rt1, const RECT rt2);
BOOL RectCrashCheck(const RECT rt1, const RECT rt2);
BOOL CircleCrashCheck(POINT ptCircle1, int r1, POINT ptCircle2, int r2);
BOOL RectCircleCrashCheck(POINT ptCircle, int r, const RECT Rect);
