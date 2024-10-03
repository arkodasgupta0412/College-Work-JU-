#include "p3.h"
#include <stdio.h>
#include <stdlib.h>

List* createList(int n) {
	List* list = (List *)malloc(sizeof(List));
	list->capacity = n;
	list->size = 0;
	list* data = (int*)malloc(sizeof(capacity));
	return list;
}

void deleteList(List *) {
	free(List);
}

void print(List *list) {
	for (int i = 0; i < size; i++) {
		printf("%d ", list->data[i]);
	}
	printf("\n");
}

int length(List *list) {
	return list->size;
}

void rev(List *list) {
	int l = size/2;
	for (int i = 0; i < l; i++) {
		int t = list->data[i];
		list->data[i] = list->data[l-i-1];
		list->data[l-i-1] = t;
	}
}

int get(List* list, int pos) {
	if (pos >= list->size)
		return -1;
	else
		return list->data[pos];
}

int modify(List* list, int pos, int val) {
	if (pos >= list->size)
		return -1;
	else {
		list->data[pos] = val;
		return 0;
	}
}

int append(List* list, int val) {
	if (list->size >= list->capacity)
		return -1;
	else {
		list->data[list->size] = val;
		list->size++;
		return 0;
	}
}

int insert(List* list, int pos, int val) {
	if (list->size >= list->capacity)
		return -1;

	else {
		for (int i = list->size; i >= pos; i--) {
			list->data[i] = list->data[i-1];
		}
		list->data[pos] = val;
		list->size++;
		return 0;
	}
}

int main() {
	List* l1 = createList(5);
	append(l1, 6);
	append(l1, 7);
	append(l1, 10);

	print(l1);
	
	return 0;
}






