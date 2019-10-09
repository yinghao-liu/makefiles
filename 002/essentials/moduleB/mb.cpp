#include <iostream>
#include "ma.h"
using namespace std;
int mb_init(void)
{
	cout<<"now in mb_init, will call ma_test"<<endl;
	ma_test();
	return 0;
}
int mb_test(void)
{
	cout<<"now in mb_test"<<endl;
	return 0;
}
