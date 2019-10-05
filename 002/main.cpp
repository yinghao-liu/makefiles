#include <stdio.h>
#include "mainConfig.h"
//#include "3rdparty.h"
//#include "ma.h"
//#include "mb.h"

int main(void)
{
	//printf(VERSION);
	//thirdparty_init();
	//ma_init();
	//mb_init();
	printf("PROJECT_NAME: %s\n", PROJECT_NAME);
	printf("PROJECT_SOURCE_DIR: %s\n", PROJECT_SOURCE_DIR);
	printf("PROJECT_BINARY_DIR: %s\n", PROJECT_BINARY_DIR);
	printf("PROJECT_VERSION: %s\n", PROJECT_VERSION);
	return 0;
}
