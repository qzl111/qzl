#include "inc/event.h"

EventCallback g_eventCallbacks[EVENT_COUNT] = {0};

void EventAddListenerSingle(EventType type, EventCallback callback) { g_eventCallbacks[type] = callback; }

void EventBroadcastSingle(EventType type, ...)
{
	if (type < EVENT_COUNT && g_eventCallbacks[type]) {
		va_list args;
		va_start(args, type);
		g_eventCallbacks[type](args);
		va_end(args);
	}
}

void OnEventA(va_list args)
{
	int			intValue	= va_arg(args, int);
	const char* stringValue = va_arg(args, const char*);
	printf("Event A triggered with int value: %d, string value: %s\n", intValue, stringValue);
}

void OnEventB(va_list args)
{
	float		floatValue	= (float) va_arg(args, double);	   // float values are promoted to double when passed through '...'
	const char* stringValue = va_arg(args, const char*);
	printf("Event B triggered with float value: %f, string value: %s\n", floatValue, stringValue);
}

void EventExample()
{
	// Register event callbacks
	EventAddListenerSingle(EVENT_A, OnEventA);
	EventAddListenerSingle(EVENT_B, OnEventB);

	// Dispatch events
	EventBroadcastSingle(EVENT_A, 42, "Hello from Event A");
	EventBroadcastSingle(EVENT_B, 3.14f, "Hello from Event B");
}
