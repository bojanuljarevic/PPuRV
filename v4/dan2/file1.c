/*
 * file1.c
 *
 *  Created on: Oct 14, 2020
 *      Author: rtrk
 */

#include "file3.h"

// ex1
int global_variable = 0x9;

void increment() {
	global_variable++;
}

// ex2
int global_variable2 = 0xe;


// ex3

static int global_variable3;

void init3() {
	global_variable3 = 0x1;
}

// ex4

static int global_variable4 = 0xe;

void init4() {
	global_variable4 = 0x1;
}

// ex5

int global_variable5;

void init5() {
	global_variable5 = 0x1;
}
