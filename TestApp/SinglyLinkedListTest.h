/*
 * SinglyLinkedListTest.h
 *
 *  Created on: Oct 23, 2020
 *      Author: rtrk
 */

#ifndef SINGLYLINKEDLISTTEST_H_
#define SINGLYLINKEDLISTTEST_H_

#include "SinglyLinkedList.h"

// "constructor" and "destructor" for unity framework
void setUp(void);
void tearDown(void);

// Shared object runtime linking handlers
void* handle;
void (*listInit)(LinkedList* list);
void (*listDestroy)(LinkedList* list);
uint8_t (*listIsEmpty)(LinkedList* list);
void (*listInsert)(LinkedList* list, int_fast32_t value);
void (*listDelete)(LinkedList* list);
void (*listDump)(LinkedList* list);
int_fast32_t (*listSize)(LinkedList* list);
void (*nodeSwap)(struct Node *a, struct Node *b);
void (*listSort)(LinkedList* list);
void (*mergeLists)(LinkedList* list1, LinkedList* list2);
void LoadListLibrary(void);
void CloseListLibrary(void);

// Functions for unit testing the shared library functions
void ListIsEmptyAfterCreation(void);
void ListIsNotEmptyAfterInsertion(void);
void ListIsEmptyAfterDeletion(void);
void ListSortTest(void);
void ListIsEmptyAfterDestruction(void);


#endif /* SINGLYLINKEDLISTTEST_H_ */
