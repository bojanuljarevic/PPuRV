/*
 * SinglyLinkedList.c
 *
 *  Created on: Oct 22, 2020
 *      Author: rtrk
 */

#include "SinglyLinkedList.h"


void ListInit(LinkedList* list) {

	list->head = NULL;
	list->tail = NULL;
}

void ListDestroy(LinkedList* list) {

	struct Node* iterator = list->head;

	while(iterator != NULL) {

		struct Node* current = iterator;
		iterator = iterator->next;
		free(current);
	}

}

bool ListIsEmpty(LinkedList* list) {

	if(list->head == NULL) {
		return true;
	}
	return false;
}

void ListInsert(LinkedList* list, int_fast32_t value) {

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;

	if(ListIsEmpty(list)) {
		list->head = node;
		list->tail = list->head;
	} else {
		node->next = list->head;
		list->head = node;
	}

}

void ListDelete(LinkedList* list) {

	if(!ListIsEmpty(list)) {
		struct Node* removed = list->head;
		list->head = list->head->next;
		free(removed);
	}
}

void ListDump(LinkedList* list) {

	struct Node* iterator = list->head;

	while (iterator != list->tail) {

		printf("[%"PRIiFAST32"]->", iterator->data);
		iterator = iterator->next;
	}
	printf("[%"PRIiFAST32"]\n", list->tail->data);
}

void ListSize(LinkedList* list) {

	uint_least8_t counter = 0;
	struct Node* iterator = list->head;

	while(iterator != list->tail) {
		counter++;
		iterator = iterator->next;
	}

	printf("List size: %"PRIuLEAST8"\n", counter);
}

void NodeSwap(struct Node* node1, struct Node* node2) {

    uint_fast32_t temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void ListSort(LinkedList* list) {

	int swapped, i;
	struct Node *ptr1;
	struct Node *lptr = NULL;

	/* Checking for empty list */
	if (list->head == NULL)
		return;

	do
	{
	    swapped = 0;
	    ptr1 = list->head;

	    while (ptr1->next != lptr)
	    {
	        if (ptr1->data > ptr1->next->data)
	        {
	        	NodeSwap(ptr1, ptr1->next);
	            swapped = 1;
	        }
	        ptr1 = ptr1->next;
	    }
	    lptr = ptr1;
	} while (swapped);

}

void MergeLists(LinkedList* list1, LinkedList* list2) {

	list1->tail->next = list2->head;
	list1->tail = list2->tail;
	ListInit(&list2);

}


