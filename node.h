#include <iostream>
using namespace std;

template <class T> class node
{
public:
	// Данные элемента очереди //
	T value;

	// Указатели на предыдущий и следующий элементы //
	node<T> *next;
	node<T> *prev;

	node( T val );
	node( void );
	~node( void );

	friend ostream &operator << ( ostream &stream, node<T>  o )
	{
		stream << o.value;
		return stream;
	}

	friend ostream &operator << ( ostream &stream, node<T> *o )
	{
		stream << o->value;
		return stream;
	}

	friend istream &operator >> ( istream &stream, node<T> &o )
	{
		cout << "Введите информацию:" << endl;
		stream >> o.value;
		return stream;
	}

	friend istream &operator >> ( istream &stream, node<T> *o )
	{
		cout << "Введите информацию:" << endl;
		stream >> o->value;
		return stream;
	}
};