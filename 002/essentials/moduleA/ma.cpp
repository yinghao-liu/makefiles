#include <iostream>
#include "include_in/in.h"
#include "mb.h"
using namespace std;
int ma_init(void)
{
	cout<<"now in ma_init,"<<g_system_conf<<endl;
	cout<<"now in ma_init, will call mb_test"<<endl;
	mb_test();
	return 0;
}

int ma_test(void)
{
	cout<<"now in ma_test"<<endl;
	return 0;
}
