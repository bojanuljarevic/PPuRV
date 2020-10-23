/*
 * SinglyLinkedList.h
 *
 *  Created on: Oct 22, 2020
 *      Author: rtrk
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct Node{
	int_fast32_t data;
	struct Node* next;
} Node;


typedef struct {
	struct Node* head;
	struct Node* tail;
} LinkedList;


void ListInit(LinkedList* list);
void ListDestroy(LinkedList* list);
bool ListIsEmpty(LinkedList* list);
void ListInsert(LinkedList* list, int_fast32_t value);
void ListDelete(LinkedList* list);
void ListDump(LinkedList* list);
void ListSize(LinkedList* list);
void NodeSwap(struct Node *a, struct Node *b);
void ListSort(LinkedList* list);
void MergeLists(LinkedList* list1, LinkedList* list2);


#endif /* SINGLYLINKEDLIST_H_ */
