/*
 * main.c
 *
 *  Created on: Oct 22, 2020
 *      Author: rtrk
 */

#include "SinglyLinkedListTest.h"
#include "unity.h"

int main() {

	LoadListLibrary();

	UNITY_BEGIN();

	RUN_TEST(ListIsEmptyAfterCreation);
	RUN_TEST(ListIsNotEmptyAfterInsertion);
	RUN_TEST(ListIsEmptyAfterDeletion);
	RUN_TEST(ListSortTest);
	RUN_TEST(ListIsEmptyAfterDestruction);

	CloseListLibrary();

	return UNITY_END();
}
