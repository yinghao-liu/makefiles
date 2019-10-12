#include <stdio.h>
// config
#include "mainConfig.h"

// components
#include "3rdparty.h"
#include "opensource.h"

// essentials
#include "ma.h"
#include "mb.h"

// applications



void usage(void)
{
	printf("Usage:%s arg\n", PROJECT_NAME);
}
int main(int argc, char *argv[])
{
	if (argc < 2) {
		usage();
		return -1;
	}
	printf("PROJECT_NAME: %s\n", PROJECT_NAME);
	printf("PROJECT_SOURCE_DIR: %s\n", PROJECT_SOURCE_DIR);
	printf("PROJECT_BINARY_DIR: %s\n", PROJECT_BINARY_DIR);
	printf("PROJECT_VERSION: %s\n", PROJECT_VERSION);
	
	printf("-------------------------------------\n");
	ma_init();
	mb_init();
	thirdparty_init();
	opensource_init();
	return 0;
}
