#pragma once

#include "list.h"

typedef struct HashMap {
	List*  list;
	size_t nodeNumber;
} HashMap;

HashMap* InitHashMap(const size_t node_number);
size_t	 HashNode(HashMap* hashmap, const int key);

bool InsertHashMap(HashMap* hashmap, float data);

bool FindInHashMap(HashMap* hashmap, float data);
