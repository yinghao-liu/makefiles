#include <stdio.h>
#include <stdint.h> // for uint32_t ..
// config
#include "mainConfig.h"

// components
#include "3rdparty.h"
#include "opensource.h"

// essentials
#include "ma.h"
#include "mb.h"

// applications
#include "app1.h"
#include "app2.h"



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
	uint32_t i = 32;
	printf("uint32_t %I32d\n", i);

	printf("PROJECT_NAME: %s\n", PROJECT_NAME);
	printf("PROJECT_SOURCE_DIR: %s\n", PROJECT_SOURCE_DIR);
	printf("PROJECT_BINARY_DIR: %s\n", PROJECT_BINARY_DIR);
	printf("PROJECT_VERSION: %s\n", PROJECT_VERSION);
	
	printf("-------------------------------------\n");
	ma_init();
	mb_init();
	thirdparty_init();
	opensource_init();
	app1_init();
	app2_init();
	return 0;
}
