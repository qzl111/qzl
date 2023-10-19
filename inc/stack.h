#pragma once

#include "myMath.h"

#define MAX_STACK_SIZE 20

typedef struct Stack
{
    float *base;
    u8 size;
    u8 topCount;
} Stack;

Stack *InitStack(int size);

bool IfStackEmpty(const Stack *stack);
bool IfStackFull(const Stack *stack);

bool Pop(Stack *Stack, float data);
bool Push(Stack *stack, float *data);
