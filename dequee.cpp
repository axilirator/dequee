#include <iostream>
#include "dequee.h"

using namespace std;

node::node( int _value )
{
	value = _value;
	next  = NULL;
	prev  = NULL;
}

node::~node( void )
{
	// Обнуляем указатели соседних элементов //
	if ( next != NULL ) next->prev = NULL;
	if ( prev != NULL ) prev->next = NULL;
}

dequee::dequee( void )
{
	// Инициализируем счетчик //
	count = 0;

	// Обнуляем указатели //
	first = NULL;
	last  = NULL;
}

dequee::~dequee( void )
{
	node *current = first;
	node *next;
	while ( current != NULL )
	{
		next = current->next;
		delete current;
		current = next;
	}

	cout << "All dequee has been destructed." << endl;
}

bool dequee::is_empty( void )
{
	return count == 0;
}

/*
	Метод поиска узла цепи по индексу.
	В случае успеха возвращает указатель на узел,
	в противном случае возвращает NULL.
 */
node *dequee::find( int n )
{
	int i = 0;
	node *current = first;

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
bool dequee::add_before( int n )
{
	// Находим узел, перед которым будет добавлен новый //
	node *target = find( n );
	if ( target == NULL )
	{
		cout << "Node #" << n << " does not exist!" << endl;
		return false;
	}

	// Создаем новый узел //
	int init_value;
	cout << "Please enter a new value: ";
	cin >> init_value;
	node *new_node = new node( init_value );

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
bool dequee::add_after( int n )
{
	// Находим узел, после которого будет добавлен новый //
	node *target = find( n );
	if ( target == NULL )
	{
		cout << "Node #" << n << " does not exist!" << endl;
		return false;
	}

	// Создаем новый узел //
	int init_value;
	cout << "Please enter a new value: ";
	cin >> init_value;
	node *new_node = new node( init_value );

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

bool dequee::remove( int n )
{
	// Находим удаляемый узел //
	node *target = find( n );
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

bool dequee::add_first( void )
{
	if ( is_empty() )
	{
		// Создаем новый узел //
		int init_value;
		cout << "Please enter a new value: ";
		cin >> init_value;
		node *new_node = new node( init_value );

		cout << "A new node added." << endl;
		first = new_node;
		last  = new_node;
		count++;

		return true;
	} else {
		return add_before( 0 );
	}
}

bool dequee::add_last( void )
{
	if ( is_empty() )
	{
		// Создаем новый узел //
		int init_value;
		cout << "Please enter a new value: ";
		cin >> init_value;
		node *new_node = new node( init_value );

		cout << "A new node added." << endl;
		first = new_node;
		last  = new_node;
		count++;

		return true;
	} else {
		return add_after( count - 1 );
	}
}

bool dequee::read( int n )
{
	// Находим требуемый узел //
	node *target = find( n );
	if ( target == NULL )
	{
		cout << "Node #" << n << " does not exist!" << endl;
		return false;
	}

	cout << "Requested value of node #" << n << endl;
	cout << "Value = " << target->value << endl;

	return true;
}

bool dequee::read_all( void )
{
	if ( is_empty() )
	{
		cout << "Dequee is empty." << endl;
		return false;
	}

	node *current = first;
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

bool dequee::remove_first( void )
{
	return remove( 0 );
}

bool dequee::remove_last( void )
{
	return remove( count - 1 );
}