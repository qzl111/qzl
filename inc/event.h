#pragma once

#include "myMath.h"

#include <stdarg.h>

typedef enum {
	EVENT_A,
	EVENT_B,
	EVENT_COUNT,	// Keep this at the end
} EventType;

typedef void (*EventCallback)(va_list);

// 单播回调
void EventAddListenerSingle(EventType type, EventCallback callback);
void EventBroadcastSingle(EventType type, ...);

void EventExample();
