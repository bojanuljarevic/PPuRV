#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


static const int_least32_t treshold1 = 20;
static const int_least32_t treshold2 = 30;
static const int_least32_t treshold3 = 40;


typedef struct _s
{
	int_least32_t value;
	int_least16_t index;
} val_ind_struct_t;

static val_ind_struct_t struct_array[4000];


static void bubble_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (str_array[i].value < str_array[j].value)
			{
				val_ind_struct_t tmp;
				
				tmp = str_array[i];
				str_array[i] = str_array[j];
				str_array[j] = tmp;
			}
		}
	}
}


static int_least32_t compare(const void* a, const void* b) {
	return (*(int_least32_t*) a - *(int_least32_t*)b);
}

static void quick_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	// sort using qsort standard function
	qsort(str_array, n, sizeof(str_array[0]), compare);
}


static int_least32_t state1() {
	return treshold1;
}
static int_least32_t state2() {
	return treshold2;
}
static int_least32_t state3() {
	return treshold1;
}

static int_least32_t (*fptr[])() = {state1, state2, state3};
static int_least32_t new_state(int_least32_t index)
{
return fptr[index]();
}


static void (*sort_fptr[])(val_ind_struct_t* str_array, int_least16_t n) = {bubble_sort, quick_sort};
static void* sort_pick(int_least32_t index, val_ind_struct_t* str_array, int_least16_t n)
{
	sort_fptr[index](str_array,n);
}




static void print(const val_ind_struct_t* str_array, int_least16_t n, int_fast8_t tr_index)
{
	int_least16_t i = 0;
	int_least32_t treshold;
	printf("Up to the %"PRIdFAST8". threshold: ", tr_index);

	/*
	switch (tr_index)
	{
	case 1:
		treshold = treshold1;
		break;
	case 2:
		treshold = treshold2;
		break;
	case 3:
		treshold = treshold3;
		break;
	}*/

	treshold = new_state(tr_index);

	while (str_array[i].value > treshold && i < n)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", str_array[i].value, str_array[i].index);
		i++;
	}
	printf("\n");
}


int main()
{
	int_least16_t i;
	int_least16_t n;
	int_fast8_t treshold_index;
	int_fast8_t sort_index;
	printf("Number of elements: ");
	scanf("%"SCNdLEAST16, &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32, &(struct_array[i].value));
		struct_array[i].index = i;
		printf("\n");
	}
	printf("Threshold you want to use (1, 2, or 3): ");
	scanf("%"SCNdFAST8, &treshold_index);
	printf("\n");
	printf("Sorting algorithm you want to use (1- bubble, 2- quick): ");
	scanf("%"SCNdFAST8, &sort_index);
	printf("\n");

	/*
	switch (sort_index)
	{
	case 1:
		bubble_sort(struct_array, n);
		break;
	case 2:
		quick_sort(struct_array, n);
		break;
	}*/

	sort_pick(sort_index, struct_array, n);


	print(struct_array, n, treshold_index);

	return 0;
}
