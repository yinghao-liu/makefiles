#include <iostream>
#include "3rdparty.h"
#include "ma.h"
using namespace std;
int app1_init(void)
{
	cout<<"-----now in app1_init-----"<<endl;
	thirdparty_init();
	ma_init();
	cout<<"-----end of app1_init-----"<<endl;
	return 0;
}
