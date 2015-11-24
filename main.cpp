#include <iostream>
#include "dequee.h"

int main( void )
{
	dequee a;
	a.add_first();
	a.add_first();
	a.add_first();
	a.add_first();
	a.add_last();
	a.remove_first();
	a.remove_last();

	a.read_all();

	return 0;
}