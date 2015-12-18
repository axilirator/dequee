#include <iostream>
#include "node.h"
#include "fraction.h"

using namespace std;

template <class T>
node<T>::node( T val )
{
	value = val;
	next  = NULL;
	prev  = NULL;
}

template <class T>
node<T>::node( void )
{
	next  = NULL;
	prev  = NULL;
}

template <class T>
node<T>::~node( void )
{
	// Обнуляем указатели соседних элементов //
	if ( next != NULL ) next->prev = NULL;
	if ( prev != NULL ) prev->next = NULL;
}

template class node<int>;
template class node<float>;
template class node<Fraction>;