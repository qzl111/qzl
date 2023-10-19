#pragma once

#include "coordinate.h"
#include "myMath.h"

typedef struct Bezier {
	u8		  rank;			  // bezier的阶次
	Vector2f* ctrlPoint;	  // bezier的控制点
	Vector2f* deltaTRatio;	  // 既定点下，各个阶次deltaT的系数
} Bezier;

Bezier*	  InitBezier(u8 rank, Vector2f* ctrl_point);
Vector2f* CalculateBezier(Bezier* bezier, float delta_t);