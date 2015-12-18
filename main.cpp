#include <iostream>
#include "dequee.h"
#include "fraction.h"

using namespace std;

int main( void )
{
	dequee<Fraction> first;
	first.add_first();
	first.add_first();
	first.read_all();

	cout << endl;

	dequee<int> second;
	second.add_first();
	second.add_first();
	second.add_last();
	second.read_all();

	return 0;
}