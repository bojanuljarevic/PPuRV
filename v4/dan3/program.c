#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


static const int_least32_t treshold = 20;

static int_least32_t values[4000];
static int_least16_t indexes[4000];
static int_least16_t n;
static int_least32_t selected_val[4000];
static int_least32_t selected_i[4000];
static int_least16_t selected_cnt = 0;

static void sort()
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] < values[j])
			{
				int_least32_t tmp;
				int_least16_t tmp1;

				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp1 = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp1;
			}
		}
	}
}


static void print()
{
	int_least16_t i = 0;
	printf("Up to the first treshold: ");
	while (values[i] > treshold && i < n)
	{
		if(!(values[i] % 2)) {
			selected_val[selected_cnt] = values[i];
			selected_i[selected_cnt++] = indexes[i];
		}
		i++;
	}
	printf("\n");
}


int main()
{
	int_least16_t i;
	printf("Number of elements: ");
	scanf("%"SCNdLEAST16, &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32, &values[i]);
		indexes[i] = i;
		printf("\n");
	}

	sort();
	print();

	printf("selected elements: ");
	for(i = 0; i < selected_cnt; i++) printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", selected_val[i], selected_i[i]);

	return 0;

}
