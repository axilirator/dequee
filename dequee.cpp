#include <iostream>
#include "dequee.h"
#include "fraction.h"

using namespace std;

template <class T>
dequee<T>::dequee( void )
{
	// Инициализируем счетчик //
	count = 0;

	// Обнуляем указатели //
	first = NULL;
	last  = NULL;
}

template <class T>
dequee<T>::~dequee( void )
{
	node<T> *current = first;
	node<T> *next;
	while ( current != NULL )
	{
		next = current->next;
		delete current;
		current = next;
	}

	cout << "All dequee has been destructed." << endl;
}

template <class T>
bool dequee<T>::is_empty( void )
{
	return count == 0;
}

/*
	Метод поиска узла цепи по индексу.
	В случае успеха возвращает указатель на узел,
	в противном случае возвращает NULL.
 */
template <class T>
node<T> *dequee<T>::find( int n )
{
	int i = 0;
	node<T> *current = first;

	while ( current != NULL )
	{
		if ( i == n ) return current;

		current = current->next;
		i++;
	}

	return NULL;
}

/*
	Метод добавления нового узла перед существующим другим.
 */
template <class T>
bool dequee<T>::add_before( int n )
{
	// Находим узел, перед которым будет добавлен новый //
	node<T> *target = find( n );
	if ( target == NULL )
	{
		cout << "Node #" << n << " does not exist!" << endl;
		return false;
	}

	// Создаем новый узел //
	node<T> *new_node = new node<T>;
	cin >> new_node;

	// Добавляем в дэк //
	if ( target->prev == NULL )
	{
		// Если это первый узел //
		first = new_node;
		first->next = target;
		target->prev = first;
	} else {
		// Перестановка указателей //
		target->prev->next = new_node;
		new_node->prev = target->prev;
		target->prev = new_node;
		new_node->next = target;
	}

	cout << "A new node added." << endl;
	count++;

	return true;
}

/*
	Метод добавления узла после другого существующего.
 */
template <class T>
bool dequee<T>::add_after( int n )
{
	// Находим узел, после которого будет добавлен новый //
	node<T> *target = find( n );
	if ( target == NULL )
	{
		cout << "Node #" << n << " does not exist!" << endl;
		return false;
	}

	// Создаем новый узел //
	node<T> *new_node = new node<T>;
	cin >> new_node;

	// Добавляем в дэк //
	if ( target->next == NULL )
	{
		// Если это последний узел //
		last = new_node;
		last->prev = target;
		target->next = last;
	} else {
		// Перестановка указателей //
		target->next->prev = new_node;
		new_node->next = target->next;
		target->next = new_node;
		new_node->prev = target;
	}

	cout << "A new node added." << endl;
	count++;

	return true;
}

template <class T>
bool dequee<T>::remove( int n )
{
	// Находим удаляемый узел //
	node<T> *target = find( n );
	if ( target == NULL )
	{
		cout << "Node #" << n << " does not exist!" << endl;
		return false;
	}

	if ( target->prev == NULL && target->next == NULL )
	{
		// Если в цепи только один узел //
		first = NULL;
		last = NULL;
	} else if ( target->prev == NULL ) {
		// Узел является первым //
		first = target->next;
		first->prev = NULL;
	} else if ( target->next == NULL ) {
		// Узел является последним //
		last = target->prev;
		last->next = NULL;
	} else {
		// Узел окружен другими узлами //
		target->prev->next = target->next;
		target->next->prev = target->prev;
	}

	// Удаляем сам узел //
	delete target;
	count--;
	cout << "Node was removed!" << endl;

	return true;
}

template <class T>
bool dequee<T>::add_first( void )
{
	if ( is_empty() )
	{
		// Создаем новый узел //
		node<T> *new_node = new node<T>;
		cin >> new_node;

		cout << "A new node added." << endl;
		first = new_node;
		last  = new_node;
		count++;

		return true;
	} else {
		return add_before( 0 );
	}
}

template <class T>
bool dequee<T>::add_last( void )
{
	if ( is_empty() )
	{
		// Создаем новый узел //
		node<T> *new_node = new node<T>;
		cin >> new_node;

		cout << "A new node added." << endl;
		first = new_node;
		last  = new_node;
		count++;

		return true;
	} else {
		return add_after( count - 1 );
	}
}

template <class T>
bool dequee<T>::read( int n )
{
	// Находим требуемый узел //
	node<T> *target = find( n );
	if ( target == NULL )
	{
		cout << "Node #" << n << " does not exist!" << endl;
		return false;
	}

	cout << "Requested value of node #" << n << endl;
	cout << "Value = " << target->value << endl;

	return true;
}

template <class T>
bool dequee<T>::read_all( void )
{
	if ( is_empty() )
	{
		cout << "Dequee is empty." << endl;
		return false;
	}

	node<T> *current = first;
	cout << "[ ";
	while ( current != NULL )
	{
		if ( current != first ) cout << ", ";
		cout << current->value;
		current = current->next;
	}
	cout << " ]" << endl;
	
	return true;
}

template <class T>
bool dequee<T>::remove_first( void )
{
	return remove( 0 );
}

template <class T>
bool dequee<T>::remove_last( void )
{
	return remove( count - 1 );
}

template class dequee<int>;
template class dequee<float>;
template class dequee<Fraction>;