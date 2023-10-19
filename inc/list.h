#pragma once

#include "myMath.h"

typedef enum ListTravelMode { ListFront2Tail, ListTail2Front } ListTravelMode;

typedef struct ListNode {
	struct ListNode* prev;
	struct ListNode* next;
	float			 data;
} ListNode;

typedef struct List {
	ListNode *head, *tail;
} List;

List* InitList(void);

bool ListPrevInsert(ListNode* listnode, float data);
bool ListNextInsert(ListNode* listnode, float data);

bool ListPrevDelete(ListNode* listnode, float* data);
bool ListNextDelete(ListNode* listnode, float* data);

bool ListHeadInsert(List* list, float data);
bool ListTailInsert(List* list, float data);

bool ListHeadDelete(List* list, float* data);
bool ListTailDelete(List* list, float* data);

ListNode* FindInList(const List* list, float data, const ListTravelMode travel_mode);

void TravelList(const List* list, void (*func)(float), const ListTravelMode travel_mode);