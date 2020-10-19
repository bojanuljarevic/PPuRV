/*
 ============================================================================
 Name        : e_bitmap.c
 Author      : rt-rk
 Version     :
 Copyright   : Your copyright notice
 Description : image processing example
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "imageProcessing.h"

static const int ARG_NUM = 2;

int main(int argc, char* argv[])
{
	int_least32_t err = 0;
	BITMAPFILEHEADER bitmapFileHeader;
	BITMAPINFOHEADER bitmapInfoHeader;
	uint_least8_t* bitmapData;

	if ( argc != ARG_NUM )
	{
		printf("Enter input file path \n");
		return EXIT_FAILURE;
	}
	
	printf("Applying brightness\n");	
	bitmapData = LoadBitmapFile(argv[1],&bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	adjustImageBrightness(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight, false, 70);
	err = SaveBitmapFile("out_brightness.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err) 
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	printf("Applying dark image\n");
	bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	bwImage(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight);
	err = SaveBitmapFile("out_bw.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err)
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	printf("Applying effect\n");
	bitmapData = LoadBitmapFile(argv[1], &bitmapFileHeader, &bitmapInfoHeader);
	if(!bitmapData)
	{
		printf("Error! Can't open input bitmap file: %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	//effect(bitmapData, bitmapInfoHeader.biWidth,
	//	bitmapInfoHeader.biHeight);

	err = SaveBitmapFile("out_effect.bmp", &bitmapFileHeader,
			&bitmapInfoHeader, bitmapData);

	//averageColors(bitmapData, bitmapInfoHeader.biWidth,
	//		bitmapInfoHeader.biHeight);

	bitmapData = LoadBitmapFile(argv[1],&bitmapFileHeader, &bitmapInfoHeader);
		if(!bitmapData)
		{
			printf("Error! Can't open input bitmap file: %s\n", argv[1]);
			return EXIT_FAILURE;
		}

	meanFilter(bitmapData, bitmapInfoHeader.biWidth,
			bitmapInfoHeader.biHeight);

	err = SaveBitmapFile("out_mean.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);

	if (err) 
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	return EXIT_SUCCESS;
}
