#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "ceasar.h"
#include "rot13.h"

#define CEASAR_SHIFT  3


int main(void)
{
	char in[100] = "the QUICK brown FOX jumps over THE lazy DOG";
	char encrypted[100];
	char decrypted[100];

	char* error;
	void* handle;


#if 1
	// libcaesar12.so

	void (*encrypt)(const char*, char*, int_fast16_t);
	void (*decrypt)(const char*, char*, int_fast16_t);
	handle = dlopen("libcaesar12.so", RTLD_LAZY);
	if (handle == NULL)
	{
		fputs(dlerror(), stderr);
		exit(1);
	}

	encrypt = dlsym(handle, "encryptCeasar");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	(*encrypt)(in, encrypted, CEASAR_SHIFT);
	printf("%s\n", encrypted);

	decrypt = dlsym(handle, "decryptCeasar");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	(*decrypt)(encrypted, decrypted, CEASAR_SHIFT);
	printf("%s\n", decrypted);

	dlclose(handle);
#endif
	// librot12.so
#if 0
	strcpy(encrypted,"");
	strcpy(decrypted,"");

	void (*encrypt_rot)(const char*, char*);
	void (*decrypt_rot)(const char*, char*);
	handle = dlopen("librot12.so", RTLD_LAZY);
	if (handle == NULL)
	{
		fputs(dlerror(), stderr);
		exit(1);
	}

	encrypt_rot = dlsym(handle, "encryptROT13");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	(*encrypt_rot)(in, encrypted);
	printf("%s\n", encrypted);

	decrypt_rot = dlsym(handle, "decryptROT13");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	(*decrypt_rot)(encrypted, decrypted);
	printf("%s\n", decrypted);

	dlclose(handle);
#endif

	return EXIT_SUCCESS;
}




