#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


static void sort(int_least32_t* values, int_least16_t* indexes, int_least16_t n)
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


static int_least16_t print(const int_least32_t* values, const int_least16_t* indexes, int_least16_t n,
		const int_least32_t treshold,  int_least32_t* selected_val, int_least16_t* selected_i)
{
	int_least16_t i = 0, even_count = 0;
	printf("Up to the first threshold: ");
	while (values[i] > treshold && i < n)
	{
		if(!(values[i] % 2)) {
			selected_val[even_count] = values[i];
			selected_i[even_count++] = indexes[i];
		}
		i++;
	}
	printf("\n");
	return even_count;
}


int main()
{

	const int_least32_t treshold = 20;

	int_least32_t values[4000];
	int_least16_t indexes[4000];
	int_least32_t selected_val[4000];
	int_least16_t selected_i[4000];

	int_least16_t i;
	int_least16_t n;
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

	sort(values, indexes, n);

	int_least16_t even_cnt = print(values, indexes, n, treshold, selected_val, selected_i);

	printf("Selected values: ");
	for(i = 0; i < even_cnt; i++) printf("%"PRIdLEAST32"(""%"PRIdLEAST16") ", selected_val[i], selected_i[i]);

	return 0;
}
