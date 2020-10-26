/*
 * SinglyLinkedList.c
 *
 *  Created on: Oct 22, 2020
 *      Author: rtrk
 */

#include "SinglyLinkedList.h"


/* Initialization of an empty list */
void ListInit(LinkedList* list) {

	list->head = NULL;
	list->tail = NULL;
}


/* Freeing up memory allocated by a previously created list */
void ListDestroy(LinkedList* list) {

	struct Node* iterator = list->head;

	while (iterator != NULL) {

		struct Node* current = iterator;
		iterator = iterator->next;
		free(current);
	}

	ListReset(list);
}


/* Equivalent to ListInit, added because of semantics */
void ListReset(LinkedList* list) {

	list->head = NULL;
	list->tail = NULL;
}


/* Checks if the list has any elements; 1 if yes, otherwise 0 */
uint8_t ListIsEmpty(LinkedList* list) {

	if (list->head == NULL) {

		return true;
	}
	return false;
}


/* Adds an element to the front of the list */
void ListPush(LinkedList* list, int_fast32_t value) {

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;

	if (ListIsEmpty(list)) {

		list->head = node;
		list->tail = list->head;
	} else {

		node->next = list->head;
		list->head = node;
	}

}


/* Adds an element containing VALUE behind the element marked by POSITION
 * if no such element exists, does nothing
 */
void ListInsert(LinkedList* list, int_fast32_t value, int_fast32_t position) {

	if (!ListIsEmpty(list)) {

		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
		node->data = value;
		node->next = NULL;

		struct Node* iterator = list->head;

		while (iterator->data != position || iterator == NULL) {

			iterator = iterator->next;
		}

		if (iterator != NULL) {

			node->next = iterator->next;
			iterator->next = node;
			return;
		}

		free(node);
	}
}


/* Adds an element to the back of the list */
void ListAppend(LinkedList* list, int_fast32_t value) {

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;
	node->next = NULL;

	if (ListIsEmpty(list)) {

		list->head = node;
		list->tail = list->head;
	} else {

		list->tail->next = node;
		list->tail = node;
	}

}


/* Removes an element from the front of the list */
void ListPopFront(LinkedList* list) {

	if (!ListIsEmpty(list)) {

		struct Node* removed = list->head;
		list->head = list->head->next;
		free(removed);
	}
}


/* Removes the first element marked by value if such element exists */
void ListDelete(LinkedList* list, int_fast32_t value) {

	if (!ListIsEmpty(list)) {

		struct Node* iterator = list->head;
		struct Node* previous = iterator;

		while (iterator->data != value || iterator == NULL) {

			previous = iterator;
			iterator = iterator->next;
		}

		if (iterator != NULL) {

			previous->next = iterator->next;
			free(iterator);
		}
	}
}


/* Removes an element from the back of the list */
void ListPopBack(LinkedList* list) {

	if (!ListIsEmpty(list)) {

		struct Node* iterator = list->head;

		if (ListSize(list) > 1) {

			while(iterator->next != list->tail) {

				iterator = iterator->next;
			}

			list->tail = iterator;
			free(list->tail->next);
			return;

		}

		free(list->head);
		ListReset(list);

	}
}


/* Linear search for an element of given value
 * Returns 1 if such element exists, otherwise 0
 */
uint8_t ListSearch(LinkedList* list, int_fast32_t value) {

	struct Node* current = list->head;

	while (current->next != list->tail->next) {

		if (current->data == value) {

			return true;
		} else {

			current = current->next;
		}
	}

	return false;
}


/* Prints the elements of the list to standard output */
void ListDump(LinkedList* list) {

	struct Node* iterator = list->head;

	while (iterator != list->tail) {

		printf("[%"PRIiFAST32"]->", iterator->data);
		iterator = iterator->next;
	}
	printf("[%"PRIiFAST32"]\n", list->tail->data);
}


/* Returns the size of the list */
int_fast32_t ListSize(LinkedList* list) {

	int_fast32_t counter = 0;
	struct Node* iterator = list->head;

	while(iterator != list->tail) {
		counter++;
		iterator = iterator->next;
	}

	return counter;
}


/* Subroutine for swapping 2 nodes during sort
 * ONLY TO BE USED INSIDE THE ListSort FUNCTION !!!
 */
void NodeSwap(struct Node* node1, struct Node* node2) {

    uint_fast32_t temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}


/* Sorting a list in nondescending order (currently Bubblesort) */
void ListSort(LinkedList* list) {

	struct Node *iterator1 = list->head;
	struct Node *iterator2 = NULL;

	if (list->head == NULL) {
		return;
	}

	while (iterator1 != list->tail) {

		iterator2 = iterator1->next;

		while (iterator2 != NULL) {

			if (iterator1->data > iterator2->data) {

				NodeSwap(iterator1, iterator2);
			}

			iterator2 = iterator2->next;

		}
		iterator1 = iterator1->next;
	}

}


/* Subroutine for picking the minimal between the current nodes of 2 sorted lists
 * After it picks the minimal it updates the current node in it's list
 * ONLY TO BE USED INSIDE MergeLists FUNCTION !!!
 */
struct Node* MinNode(struct Node** const node1, struct Node** const node2) {

	struct Node* retVal;

	if ((*node1)->data < (*node2)->data) {

		retVal = *node1;
		if (retVal->next == NULL) {
			*node1 = NULL;
		} else {
			*node1 = (*node1)->next;
		}
	} else {

		retVal = *node2;
		if (retVal->next == NULL) {
			*node1 = NULL;
		} else {
		*node2 = (*node2)->next;
		}
	}

	return retVal;
}


/* Merges 2 sorted list into a sorted list
 * The returned value (Pointer to a LinkedList) needs to be freed after usage
 */
LinkedList* MergeLists(LinkedList* list1, LinkedList* list2) {

	ListSort(list1);
	ListSort(list2);

	struct Node* current1 = list1->head;
	struct Node* current2 = list2->head;

	LinkedList* merged = (LinkedList*)malloc(sizeof(LinkedList));
	ListInit(merged);

	if ((current1->data) < (current2->data)) {

		merged->head = list1->head;
		current1 = current1->next;

	} else {

		merged->head = list2->head;
		current2 = current2->next;
	}
	merged->tail = merged->head;

	while (current1 != NULL && current2 != NULL) {

		merged->tail->next = MinNode(&current1, &current2);
		merged->tail = merged->tail->next;
	}

	if (current1 == NULL) {

		while (current2 != NULL) {

			merged->tail->next = current2;
			merged->tail = merged->tail->next;
			current2 = current2->next;
		}
	} else {

		while (current1 != NULL) {

			merged->tail->next = current1;
			merged->tail = merged->tail->next;
			current1 = current1->next;
		}
	}

	ListReset(list1);
	ListReset(list2);

	return merged;
}


/* Needs to be called after finishing with MergeLists function to properly free memory */
void FreeMerged(LinkedList* list) {

	ListDestroy(list);
	free(list);
}


