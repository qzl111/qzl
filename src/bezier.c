
#include "inc/bezier.h"

Bezier* InitBezier(u8 rank, Vector2f* ctrl_point)
{
	if (rank < 2)
		return NULL;

	Bezier* bezier = (Bezier*) malloc(sizeof(Bezier));
	if (!bezier)
		return NULL;

	bezier->deltaTRatio = (Vector2f*) malloc(sizeof(Vector2f) * (rank + 1));
	if (!bezier->deltaTRatio) {
		free(bezier);
		return NULL;
	}

	bezier->ctrlPoint = ctrl_point;
	bezier->rank	  = rank;

	memset(bezier->deltaTRatio, 0, sizeof(Vector2f) * (rank + 1));

	for (u8 i = 0; i < rank + 1; i++) {
		u8 n = rank + 1 - i;
		for (u8 j = 0; j < n; j++) {
			float tempdata				  = pow((float) (-1), (int) (n - 1 - j)) * NChooseM(rank, j) * NChooseM(rank - j, i);
			bezier->deltaTRatio[n - 1].x += tempdata * bezier->ctrlPoint[j].x;
			bezier->deltaTRatio[n - 1].y += tempdata * bezier->ctrlPoint[j].y;
		}
	}
	return bezier;
};

Vector2f* CalculateBezier(Bezier* bezier, float delta_t)
{
	Vector2f* result = (Vector2f*) malloc(sizeof(Vector2f));
	*result			 = bezier->ctrlPoint[0];
	for (u8 i = 0; i < bezier->rank; i++) {
		result->x += bezier->deltaTRatio[bezier->rank - i].x * pow(delta_t, bezier->rank - i);
		result->y += bezier->deltaTRatio[bezier->rank - i].y * pow(delta_t, bezier->rank - i);
	}
	return result;
};