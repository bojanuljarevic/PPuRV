/*
 * SinglyLinkedListTest.h
 *
 *  Created on: Oct 23, 2020
 *      Author: rtrk
 */

#ifndef SINGLYLINKEDLISTTEST_H_
#define SINGLYLINKEDLISTTEST_H_

#include "SinglyLinkedList.h"

/* "constructor" and "destructor" for unity framework */
void setUp(void);
void tearDown(void);

/* Shared object runtime linking handlers */
void* handle;
void (*listInit)(LinkedList* list);
void (*listDestroy)(LinkedList* list);
uint8_t (*listIsEmpty)(LinkedList* list);
void (*listPush)(LinkedList* list, int_fast32_t value);
void (*listInsert)(LinkedList* list, int_fast32_t value, int_fast32_t position);
void (*listAppend)(LinkedList* list, int_fast32_t value);
void (*listPopFront)(LinkedList* list);
void (*listDelete)(LinkedList* list, int_fast32_t value);
void (*listPopBack)(LinkedList* list);
uint8_t (*listSearch)(LinkedList* list, int_fast32_t value);
void (*listDump)(LinkedList* list);
int_fast32_t (*listSize)(LinkedList* list);
void (*listSort)(LinkedList* list);
LinkedList* (*mergeLists)(LinkedList* list1, LinkedList* list2);
void (*freeMerged)(LinkedList *list);
void LoadListLibrary(void);
void CloseListLibrary(void);


/* Functions for unit testing the shared library functions */
void ListIsEmptyAfterCreation(void);
void ListPushAndPopFrontTest(void);
void ListAppendAndPopBackTest(void);
void ListAppendTest(void);
void ListSortTest(void);
void ListArbitraryInsertionTest(void);
void ListSearchTest(void);
void ListArbitraryDeletionTest(void);
void ListIsEmptyAfterDestruction(void);
void MergeSortedTest(void);


#endif /* SINGLYLINKEDLISTTEST_H_ */
