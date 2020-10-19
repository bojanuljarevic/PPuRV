
#include "imageProcessing.h"
#include "bmp.h"
#include <stdint.h>

static const uint_least8_t bwTreshold = 128;
const int_least16_t brightnessMinimum = 20;
const int_least16_t brightnessMaximum = 220;


void adjustImageBrightness(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight,
		bool brighten, uint_least8_t adjustmentValue)
{
	uint_least32_t i;
	int_least16_t newValue;

	for (i=0; i<iWidth*iHeight*3; i++)
	{
		newValue = iData[i];
		if(brighten)
		{
			newValue += adjustmentValue;
		}
		else
		{
			newValue -= adjustmentValue;
		}

		if(newValue < brightnessMinimum)
		{
			newValue = brightnessMinimum;
		}
		else if(newValue > brightnessMaximum)
		{
			newValue = brightnessMaximum;
		}

		iData[i] = newValue;
	}
}

void bwImage(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight)
{
	uint_least16_t i;
	uint_least16_t j;
	uint_least16_t k;
	
	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			uint_least16_t sum = 0;
			for (k=0; k<3; k++)
			{
				sum += iData[i * iWidth * 3 + j * 3 + k];
			}
			sum = sum / 3;

			sum = (sum > bwTreshold)? 255 : 0;

			for (k=0; k<3; k++)
			{
				iData[i * iWidth * 3 + j * 3 + k] = sum;
			}
		}
	}
}

void effect(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight)
{
	uint_least16_t i;
	uint_least16_t j;
	uint_least8_t* ptr = iData;
	
	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			*ptr = (*ptr > bwTreshold)? 255 : 0;
			ptr++;
			*ptr = (*ptr > bwTreshold)? 255 : 0;
			ptr++;
			*ptr = (*ptr > bwTreshold)? 255 : 0;
			ptr++;;
		}
	}
}

void averageColors(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight)
{
	uint_least16_t i;
	uint_least16_t j;
	uint_least32_t avgRed = 0;
	uint_least32_t avgBlue = 0;
	uint_least32_t avgGreen = 0;

	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			avgRed += iData[i * iWidth * 3 + j * 3 + 0];
			avgGreen += iData[i * iWidth * 3 + j * 3 + 1];
			avgBlue += iData[i * iWidth * 3 + j * 3 + 2];
		}
	}

	avgRed /= iHeight * iWidth;
	avgGreen /= iHeight * iWidth;
	avgBlue /= iHeight * iWidth;

	printf("R:%u, G:%u, B:%u\n", avgRed, avgGreen, avgBlue);

}

void meanFilter(uint_least8_t* iData, uint_least16_t iWidth, uint_least16_t iHeight)
{
	uint_least16_t i;
	uint_least16_t j;

	for (i=1; i<iHeight-1; i++)
		{
			for (j=1; j<iWidth-1; j++)
			{

				int_least8_t k;
				uint_least16_t outputRed = 0;
				uint_least16_t outputGreen = 0;
				uint_least16_t outputBlue = 0;

				// Red
				for(k = -1; k <= 1; k++) {

					outputRed += iData[(i-1) * iWidth * 3 + (j+k) * 3 + 0];
					outputRed += iData[i * iWidth * 3 + (j+k) * 3 + 0];
					outputRed += iData[(i+1) * iWidth * 3 + (j+k) * 3 + 0];

					outputGreen += iData[(i-1) * iWidth * 3 + (j+k) * 3 + 1];
					outputGreen += iData[i * iWidth * 3 + (j+k) * 3 + 1];
					outputGreen += iData[(i+1) * iWidth * 3 + (j+k) * 3 + 1];

					outputBlue += iData[(i-1) * iWidth * 3 + (j+k) * 3 + 2];
					outputBlue += iData[i * iWidth * 3 + (j+k) * 3 + 2];
					outputBlue += iData[(i+1) * iWidth * 3 + (j+k) * 3 + 2];
				}

				iData[i * iWidth * 3 + j * 3 + 0] = outputRed / 9;
				iData[i * iWidth * 3 + j * 3 + 1] = outputGreen / 9;
				iData[i * iWidth * 3 + j * 3 + 2] = outputBlue / 9;


			}
		}
}
