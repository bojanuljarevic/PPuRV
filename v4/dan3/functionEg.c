#include "functionEg.h"


int_least32_t factorial(int_least16_t n)
{
	if(0 == n) return 1;
	else return n * factorial(n-1);
}

int_least32_t factorial2(int_least16_t n)
{
	int_least32_t res  = 1;
	while (n > 0) {
		res *= (n--);
	}
	return res;
}

int_least32_t fibonacci(int_least16_t n)
{
	if (n <= 1) {
		return 1;
	} else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int_least32_t fibonacci2(int_least16_t n)
{
	int_least32_t res = 0;
	int_least32_t f_n1 = 1;				// f(n-1)
	int_least32_t f_n2 = 0;				// f(n-2)
	int_least16_t i;
	for(i = 0; i < n; i++) {
		res = f_n1 + f_n2;
		f_n2 = f_n1;
		f_n1 = res;
	}
	return f_n1;
}
