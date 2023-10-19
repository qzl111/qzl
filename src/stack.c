#include "inc/stack.h"

Stack* InitStack(int size)
{
	if (size < 1)
		return NULL;
	if (size > MAX_STACK_SIZE)
		size = MAX_STACK_SIZE;

	Stack* stack = (Stack*) malloc((sizeof(Stack)));
	if (!stack)
		return NULL;

	stack->base = (float*) malloc(sizeof(float) * size);
	if (!stack->base) {
		free(stack);
		return NULL;
	}
	stack->size		= size;
	stack->topCount = 0;

	return stack;
};

bool IfStackEmpty(const Stack* stack) { return (stack->topCount == 0); };

bool IfStackFull(const Stack* stack) { return (stack->topCount == stack->size); }

bool Pop(Stack* stack, float data)
{
	if (IfStackFull(stack))
		return false;
	stack->base[stack->topCount++] = data;
	return true;
};

bool Push(Stack* stack, float* data)
{
	if (IfStackEmpty(stack))
		return false;

	*data = stack->base[--stack->topCount];
	return true;
};