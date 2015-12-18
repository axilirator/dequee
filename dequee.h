#include "node.h"

template <class T> class dequee
{
private:
	// Количество элементов в деке //
	unsigned short count;

	// Указатели на первый и последний элементы //
	node<T> *first;
	node<T> *last;
public:
	dequee( void );
	~dequee( void );

	/*
		Возвращает true, если дек пуст.
	 */
	bool is_empty( void );

	/*
		Метод поиска узла цепи по индексу.
		В случае успеха возвращает указатель на узел,
		в противном случае возвращает NULL.
	 */
	node<T> *find( int n );

	/*
		Метод добавления нового узла перед существующим другим.
	 */
	bool add_before( int n );

	/*
		Метод добавления узла после другого существующего.
	 */
	bool add_after( int n );

	/*
		Метод удаления узла.
	 */
	bool remove( int n );

	bool add_first( void );
	bool add_last( void );

	bool remove_first( void );
	bool remove_last( void );

	/*
		Метод чтения значения определенного узла.
	 */
	bool read( int n );

	/*
		Читает значения всех узлов цепи и выводит в формате массива.
	 */
	bool read_all( void );
};