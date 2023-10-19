#include "inc/list.h"

// 双向链表
List* InitList()
{
	List* list = (List*) malloc(sizeof(List));
	if (!list)
		return NULL;

	list->head = (ListNode*) malloc(sizeof(ListNode));
	list->tail = (ListNode*) malloc(sizeof(ListNode));

	if ((!list->head) || (!list->tail)) {
		free(list->head);
		free(list->tail);
		free(list);
		return NULL;
	}

	list->head->next = list->head->prev = list->tail;
	list->tail->next = list->tail->prev = list->head;
	return list;
};

bool ListPrevInsert(ListNode* listnode, float data)
{
	ListNode* newnode = (ListNode*) malloc(sizeof(ListNode));
	if (!newnode)
		return false;

	newnode->data		 = data;

	newnode->prev		 = listnode->prev;
	newnode->next		 = listnode;

	listnode->prev->next = newnode;
	listnode->prev		 = newnode;
	// newnode->next->prev = newnode;
	// newnode->prev->next = newnode;
	return true;
}

bool ListNextInsert(ListNode* listnode, float data)
{
	ListNode* newnode = (ListNode*) malloc(sizeof(ListNode));
	if (!newnode)
		return false;

	newnode->data		= data;

	newnode->next		= listnode->next;
	newnode->prev		= listnode;

	newnode->next->prev = newnode;
	newnode->prev->next = newnode;

	return true;
};

bool ListPrevDelete(ListNode* listnode, float* data)
{
	if (!listnode->prev)
		return false;

	ListNode* deleteNode   = listnode->prev;
	*data				   = deleteNode->data;

	listnode->prev		   = deleteNode->prev;
	deleteNode->prev->next = listnode;

	free(deleteNode);
	return true;
};

bool ListNextDelete(ListNode* listnode, float* data)
{
	if (!listnode->next)
		return false;

	ListNode* deleteNode   = listnode->next;
	*data				   = deleteNode->data;

	listnode->next		   = deleteNode->next;
	deleteNode->next->prev = listnode;

	free(deleteNode);
	return true;
};

bool ListHeadInsert(List* list, float data) { return ListNextInsert(list->head, data); };
bool ListTailInsert(List* list, float data) { return ListPrevInsert(list->tail, data); };

bool ListHeadDelete(List* list, float* data) { return ListNextDelete(list->head, data); };
bool ListTailDelete(List* list, float* data) { return ListPrevDelete(list->tail, data); };

ListNode* FindInList(const List* list, float data, const ListTravelMode travel_mode)
{
	if (travel_mode == ListFront2Tail) {
		ListNode* indexNode = list->head->next;
		while (indexNode != list->tail) {
			if (indexNode->data == data)
				return indexNode;
			indexNode = indexNode->next;
		}
	} else if (travel_mode == ListTail2Front) {
		ListNode* indexNode = list->tail->prev;
		while (indexNode != list->head) {
			if (indexNode->data == data)
				return indexNode;
			indexNode = indexNode->prev;
		}
	}
	return NULL;
};

void TravelList(const List* list, void (*func)(float), const ListTravelMode travel_mode)
{
	if (travel_mode == ListFront2Tail) {
		ListNode* indexNode = list->head->next;
		while (indexNode != list->tail) {
			func(indexNode->data);
			indexNode = indexNode->next;
		}
	} else if (travel_mode == ListTail2Front) {
		ListNode* indexNode = list->tail->prev;
		while (indexNode != list->head) {
			func(indexNode->data);
			indexNode = indexNode->prev;
		}
	}
};
