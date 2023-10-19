#pragma once

#include "event.h"
#include "myMath.h"

// 多播回调
bool EventAddListener(EventType event_type, EventCallback callback);
void EventBroadcast(EventType event_type, ...);
