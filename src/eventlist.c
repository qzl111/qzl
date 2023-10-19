#include "inc/eventlist.h"

typedef struct EventListNode {
	EventCallback		  func;
	struct EventListNode* next;
} EventListNode;

typedef struct EventGroup {
	EventListNode eventList[EVENT_COUNT];
} EventGroup;

EventGroup g_eventGroup;

bool EventAddListener(EventType event_type, EventCallback callback)
{
	EventListNode* newEvent = (EventListNode*) malloc(sizeof(EventListNode));
	if (!newEvent)
		return false;

	newEvent->func = callback;
	newEvent->next = NULL;

	if (g_eventGroup.eventList[event_type].next)	// 如果头后面又事件了
		newEvent->next = g_eventGroup.eventList[event_type].next;

	g_eventGroup.eventList[event_type].next = newEvent;
	return true;
}

void EventBroadcast(EventType event_type, ...)
{
	if ((event_type >= EVENT_COUNT) || (!g_eventGroup.eventList[event_type].next))
		return;

	va_list args;
	va_start(args, event_type);
	va_end(args);
	EventListNode* startEvent = g_eventGroup.eventList[event_type].next;
	while (startEvent) {
		startEvent->func(args);
		startEvent = startEvent->next;
	}
};
