#include "inc/myMath.h"

float NChooseM(int n, int m)
{
	float temp = 1;
	m		   = (m < (n - m) ? m : (n - m));
	for (int i = m; i < n; i++) temp *= (i + 1);
	for (int i = 1; i < (n - m); i++) temp /= i + 1;
	return temp;
};