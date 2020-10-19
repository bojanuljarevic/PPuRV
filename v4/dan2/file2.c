/*
 * file2.c
 *
 *  Created on: Oct 14, 2020
 *      Author: rtrk
 */

#include <stdio.h>
#include "file3.h"

// ex 1

void use_it() {
	printf("Ex 1: %x\n", ++global_variable);
}

// ex 2

int global_variable2;

void print_global() {
	printf("Ex 2: %x\n", global_variable2);
}


// ex3

static int global_variable3;

void print3() {
	printf("Ex 3: %x\n", global_variable3);
}

// ex4

static int global_variable4 = 0x1;

void print4() {
	printf("Ex 4: %x\n", global_variable4);
}

// ex5

static int global_variable5;

void print5() {
	printf("Ex 5: %x\n", global_variable5);
}
