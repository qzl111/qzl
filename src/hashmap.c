#include "inc/hashmap.h"

bool FindInHashMap(HashMap* hashmap, float data)
{
	size_t node = HashNode(hashmap, (int) data);
	return FindInList(&hashmap->list[node], data, ListFront2Tail);
}

bool InsertHashMap(HashMap* hashmap, float data)
{
	size_t node = HashNode(hashmap, (int) data);
	return ListTailInsert(&hashmap->list[node], data);
}

size_t HashNode(HashMap* hashmap, const int key) { return (key % (hashmap->nodeNumber)); }

HashMap* InitHashMap(const size_t node_number)
{
	HashMap* hashmap = (HashMap*) malloc(sizeof(HashMap));
	if (!hashmap)
		return NULL;

	hashmap->list = (List*) malloc(sizeof(List) * node_number);

	if (!hashmap->list) {
		free(hashmap);
		return NULL;
	}

	for (size_t i = 0; i < node_number; i++) hashmap->list[i] = *InitList();

	hashmap->nodeNumber = node_number;

	return hashmap;
}