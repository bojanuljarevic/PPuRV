/*
 * SinglyLinkedListTest.c
 *
 *  Created on: Oct 23, 2020
 *      Author: rtrk
 */

#include <dlfcn.h>
#include "SinglyLinkedListTest.h"
#include "unity.h"


static LinkedList list;


/* constructor for the unity framework */
void setUp(void)
{
	(*listInit)(&list);
}


/* destructor for the unity framework */
void tearDown(void)
{
	(*listInit)(&list);
}


/* Connecting function pointers to libSinglyLinkedList.so functions */
void LoadListLibrary(void) {

	char* error;

	handle = dlopen("libSinglyLinkedList.so", RTLD_LAZY);
	if (handle == NULL)
	{
		fputs(dlerror(), stderr);
		exit(1);
	}

	listInit = dlsym(handle, "ListInit");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listDestroy = dlsym(handle, "ListDestroy");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listIsEmpty = dlsym(handle, "ListIsEmpty");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listPush = dlsym(handle, "ListPush");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listInsert = dlsym(handle, "ListInsert");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listAppend = dlsym(handle, "ListAppend");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listPopFront = dlsym(handle, "ListPopFront");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listDelete = dlsym(handle, "ListDelete");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listPopBack = dlsym(handle, "ListPopBack");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listSearch = dlsym(handle, "ListSearch");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listDump = dlsym(handle, "ListDump");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listSize = dlsym(handle, "ListSize");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	listSort = dlsym(handle, "ListSort");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	mergeLists = dlsym(handle, "MergeLists");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	freeMerged = dlsym(handle, "FreeMerged");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

}


/* Release dl handle */
void CloseListLibrary(void) {

	dlclose(handle);
}


/* Testing if the list has no elements upon creation */
void ListIsEmptyAfterCreation(void) {

	TEST_ASSERT_TRUE((*listIsEmpty)(&list));
}

/* Push 1 element to the front of an empty list -> test if it is not empty
 * Pop element from the front -> test if it is empty
 */
void ListPushAndPopFrontTest(void) {

	(*listPush)(&list, 0);

	TEST_ASSERT_FALSE((*listIsEmpty)(&list));

	(*listPopFront)(&list);

	TEST_ASSERT_TRUE((*listIsEmpty)(&list));
}

/* Append 1 element to the back of an empty list -> test if it is not empty
 * Pop element from the back -> test if it is empty
 */
void ListAppendAndPopBackTest(void) {

	(*listAppend)(&list, 0);

	TEST_ASSERT_FALSE((*listIsEmpty)(&list));

	(*listPopBack)(&list);

	TEST_ASSERT_TRUE((*listIsEmpty)(&list));
}


/* Testing the correctnes of subsequent appends */
void ListAppendTest(void) {

	int_fast32_t i;

	for (i = 0; i < 5; i++) {

		(*listAppend)(&list, i);
	}

	struct Node* current = list.head;
	i = 0;

	while(current != NULL) {

		TEST_ASSERT_EQUAL(i, current->data);
		current = current->next;
		i++;
	}

}


/* Testing the correctnes of the sort subroutine */
void ListSortTest(void) {

	const int_fast32_t expected[] = { 0, 1, 2, 3, 4 };
	int_fast32_t i;

	for (i = 0; i < 5; i++) {

		(*listPush)(&list, i);
	}

	(*listSort)(&list);
	struct Node* current = list.head;

	for (i = 0; i < 5; i++) {

		TEST_ASSERT_EQUAL(expected[i], current->data);
		current = current->next;
	}

}


/* Testing an insertion of a node valued 100 after a node valued 2 */
void ListArbitraryInsertionTest(void) {

	const int_fast32_t expected[] = { 0, 1, 2, 100, 3, 4 };
	int_fast32_t i = 0;

	(*listInsert)(&list, 100, 2);

	struct Node* current = list.head;

	while(current != NULL) {

		TEST_ASSERT_EQUAL(expected[i], current->data);
		i++;
		current = current->next;
	}

}

/* Testing if the list contains elements 2(true) and 6(false) */
void ListSearchTest(void) {

	int_fast32_t i;

	for (i = 0; i < 5; i++) {

		(*listAppend)(&list, i);
	}

	TEST_ASSERT_TRUE((*listSearch)(&list, 2));
	TEST_ASSERT_FALSE((*listSearch)(&list, 6));
}


/* Testing if a node valued 100 is properly deleted
 * & if the list remains the same after attempting to remove
 * a node valued 1000 which doesn't exist.
 */
void ListArbitraryDeletionTest(void) {

	const int_fast32_t expected[] = { 0, 1, 2, 3, 4 };
	int_fast32_t i = 0;

	(*listDelete)(&list, 100);

	struct Node* current = list.head;

	while(current != NULL) {

		TEST_ASSERT_EQUAL(expected[i], current->data);
		i++;
		current = current->next;
	}

	(*listDelete)(&list, 1000);

	current = list.head;

	while(current != NULL) {

		TEST_ASSERT_EQUAL(expected[i], current->data);
		i++;
		current = current->next;
	}

}


/* Freeing up allocated elements and checking if the list is empty */
void ListIsEmptyAfterDestruction(void) {

	(*listDestroy)(&list);

	TEST_ASSERT_TRUE((*listIsEmpty)(&list));
}


/* Testing if merging 2 lists :
 * List1: [8]->[6]->[4]->[2]->[0]
 * List2: [9]->[7]->[5]->[3]->[1]
 * results in 2 sorted lists which link together into
 * [0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9];
 * Implicitly tests the push function as well.
 */
void MergeSortedTest(void) {

	const int_fast32_t expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	LinkedList tempList;
	int_fast32_t i;

	for (i = 0; i < 5; i++) {
		(*listPush)(&list, 2*i);
		(*listPush)(&tempList, 2*i + 1);
	}

#if 0
	printf("List 1: ");
	(*listDump)(&list);
	printf("List 2: ");
	(*listDump)(&tempList);
	printf("Merged & Sorted: ");
#endif

	LinkedList* merged = (*mergeLists)(&list, &tempList);

#if 0
	(*listDump)(merged);
#endif

	struct Node* current = merged->head;
	i = 0;

	while(current != NULL) {

		TEST_ASSERT_EQUAL(expected[i], current->data);
		i++;
		current = current->next;
	}

	(*freeMerged)(merged);

}


