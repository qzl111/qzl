#pragma once

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI	   3.1415926
#define ABS(x) ((x) < 0 ? (-(x)) : (x))

typedef size_t u8;

// 排列组合
float NChooseM(int n, int m);