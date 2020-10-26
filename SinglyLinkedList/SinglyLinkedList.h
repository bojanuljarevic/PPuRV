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


/* Element of the linked list */
struct Node{
	int_fast32_t data;
	struct Node* next;
};


/* Linked list structure */
typedef struct {
	struct Node* head;
	struct Node* tail;
} LinkedList;


/* Basic operations on a singly linked list; further explanations in the source file */
void ListInit(LinkedList* list);
void ListDestroy(LinkedList* list);
void ListReset(LinkedList* list);
uint8_t ListIsEmpty(LinkedList* list);
void ListPush(LinkedList* list, int_fast32_t value);
void ListInsert(LinkedList* list, int_fast32_t value, int_fast32_t position);
void ListAppend(LinkedList* list, int_fast32_t value);
void ListPopFront(LinkedList* list);
void ListDelete(LinkedList* list, int_fast32_t value);
void ListPopBack(LinkedList* list);
uint8_t ListSearch(LinkedList* list, int_fast32_t value);
void ListDump(LinkedList* list);
int_fast32_t ListSize(LinkedList* list);
void NodeSwap(struct Node *a, struct Node *b);
void ListSort(LinkedList* list);
struct Node* MinNode(struct Node** const node1, struct Node** const node2);
LinkedList* MergeLists(LinkedList* list1, LinkedList* list2);
void FreeMerged(LinkedList* list);


#endif /* SINGLYLINKEDLIST_H_ */
