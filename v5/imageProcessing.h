#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_

#include <stdint.h>
#include <stdbool.h>


void adjustImageBrightness(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight,
		bool brighten, uint_least8_t adjustmentValue);

void bwImage(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight);

void effect(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight);

void averageColors(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight);

void meanFilter(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight);

#endif /* IMAGEPROCESSING_H_ */
