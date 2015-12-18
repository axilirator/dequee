#include <iostream>
#include <string>

using namespace std;

void debug( string str );

class Fraction
{
private:
	int top;    // Числитель
	int bottom; // Знаменатель
public:
	// Конструктор без параметров //
	Fraction( void );

	// Основной конструктор //
	Fraction( int top, int bottom );

	// Конструктор копирования //
	Fraction( Fraction &copy );

	// Деструктор //
	~Fraction();

	// Ввод числа //
	void update( int top, int bottom );

	// Вывод числа //
	void print( void );

	// Функция упрощения //
	void simplify( void );

	// Функция умножения //
	Fraction multiply( Fraction *second );

	// Функция деления //
	Fraction divide( Fraction *second );

	// Функция сложения //
	Fraction plus( Fraction *second );

	// Функция вычитания //
	Fraction minus( Fraction *second );

	// Перегрузка оператора вывода //
	friend ostream& operator<<( ostream& os, Fraction& p );

	// Перегрузка оператора ввода //
	friend istream& operator>>( istream& is, Fraction& p );
};