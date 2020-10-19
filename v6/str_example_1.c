/*
 * str_example_1.c
 *
 *  Created on: Oct 19, 2020
 *      Author: rtrk
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


uint32_t stringLength(const char str[]);
void stringTrim(char str[]);
uint8_t extractSubstring(const char inStr[], char outStr[], uint_least32_t
beginning, uint_least32_t end);
uint8_t concateStrings(char str1[], const char str2[]);

static uint_least32_t startIndex = 5;
static uint_least32_t endIndex = 9;

int main() {

	char string[] = "     1234 5678     \0";
	char *string2 = (char*)calloc(stringLength(string) * sizeof(char), sizeof(char));

	uint32_t len = stringLength(string);
	printf("strlen 1: %"PRIu32"\n", len);

	stringTrim(string);
	len = stringLength(string);
	printf("strlen after trim: %"PRIu32"\n", len);

	extractSubstring(string, string2, startIndex, endIndex);
	printf("extracted substring: %s\n", string2);

	len = stringLength(string2);
	printf("strlen 2: %"PRIu32"\n", len);

	concateStrings(string, string2);

	printf("string1 + string2 = %s\n", string);

	free(string2);

	return 0;
}


uint32_t stringLength(const char str[]) {

	uint32_t len = 0;

	while(str[len] != '\0') {
		len++;
	}

	return len;
}

void stringTrim(char str[]) {

	char* front = str;
	while(*front == ' ') {
		front++;
	}

	char* back = str;

	while(*back != '\0') {
		back++;
	}
	back--;

	while(*back == ' ') {
		back--;
	}

	uint8_t i = 0;

	do {
		str[i++] = *(front++);
	} while(front != back+1);

	str[i] = '\0';

}

uint8_t extractSubstring(const char inStr[], char outStr[], uint_least32_t beginning, uint_least32_t end) {

	uint8_t i, j = 0;

	if (end > stringLength(inStr)) return 0;

	for(i = beginning; i < end; i++) {
		outStr[j++] = inStr[i];
	}

	return 1;

}

uint8_t concateStrings(char str1[], const char str2[]) {

	uint32_t i = stringLength(str1);

	while(*str2 != '\0') {
		str1[i++] = *(str2++);
	}
	str1[i] = '\0';

	return 0;
}
