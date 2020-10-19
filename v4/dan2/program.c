#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

enum tresholds_t
{
	TRESHOLDS_FIRST = 10,
	TRESHOLDS_SECOND,
	TRESHOLDS_THIRD = 20
};


void sort(int_least32_t* values, int_least16_t* indexes, const int_least32_t n)
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
				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp;
			}
		}
	}
}


void print(const int_least32_t* values, const int_least16_t* indexes, const int_least32_t n)
{
	int_least16_t i = 0;
	printf("Up to the first threshold: ");
	while (values[i] > TRESHOLDS_FIRST && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
	printf("Up to the second threshold: ");
	while (values[i] > TRESHOLDS_SECOND && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
	printf("Up to the third threshold: ");
	while (values[i] > TRESHOLDS_THIRD && i < n)
	{
		printf("%" PRIdLEAST32"(""%" PRIdLEAST16"(", values[i], indexes[i]);
		i++;
	}
}


int main()
{
	int_least32_t values[30000];
	int_least16_t indexes[30000];
	int_least16_t i;
	int_least32_t n;
	printf("Number of elements: ");
	scanf("%" PRId32, &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d. element: ", i);
		scanf("%" PRId32, &values[i]);
		indexes[i] = i;
		printf("\n");
	}

	sort(values, indexes, n);

	print(values, indexes, n);

	return 0;
}
