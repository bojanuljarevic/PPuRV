/*
 * SinglyLinkedListTest.c
 *
 *  Created on: Oct 23, 2020
 *      Author: rtrk
 */

#include <dlfcn.h>
#include "SinglyLinkedListTest.h"
#include "unity.h"
#include "FormatOutputSpy.h"

static LinkedList list;

void setUp(void)
{
	(*listInit)(&list);
}

void tearDown(void)
{
	(*listInit)(&list);
}

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

	listInsert = dlsym(handle, "ListInsert");
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

	nodeSwap = dlsym(handle, "NodeSwap");
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

}

void CloseListLibrary(void) {

	dlclose(handle);
}


void ListIsEmptyAfterCreation(void) {

	TEST_ASSERT_TRUE((*listIsEmpty)(&list));
}

void ListIsNotEmptyAfterInsertion(void) {

	(*listInsert)(&list, 0);

	TEST_ASSERT_FALSE((*listIsEmpty)(&list));
}

void ListIsEmptyAfterDeletion(void) {

	(*listDelete)(&list);

	TEST_ASSERT_TRUE((*listIsEmpty)(&list));
}

void ListSortTest(void) {

	int_fast32_t expected[] = { 0, 1, 2, 3, 4 };
	int_fast32_t i;

	for (i = 0; i < 5; i++) {

		(*listInsert)(&list, i);
	}

	(*listSort)(&list);
	struct Node* current = list.head;

	for (i = 0; i < 5; i++) {

		TEST_ASSERT_EQUAL(expected[i], current->data);
		current = current->next;
	}

}

void ListIsEmptyAfterDestruction(void) {

	(*listDestroy)(&list);

	TEST_ASSERT_TRUE((*listIsEmpty)(&list));
}


