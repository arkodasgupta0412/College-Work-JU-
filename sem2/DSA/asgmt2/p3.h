#ifndef P3_H
#define P3_H

typedef struct List {
	int* data;
	int capacity;
	int size;
}List;

// initializes an empty list
List *createList(int);

// prints list
void print(List *);

// returns the size of list
int length(List *);

// reverses the list
void rev(List *);

// returns the element at given position, if position not exist, return -1
int get(List*, int);

// modifies the element at given position, if modifies return 0, else return -1
int modify(List*, int, int);

// appends element at end of list, success -> 0, else returns -1
int append(List*, int);

// inserts the element at given position (success -> 0), if size >= capacity returns -1
int insert(List*, int, int);

// delete the List object
void deleteList(List *);

// sorts list
void sort(List *, int);

#endif




