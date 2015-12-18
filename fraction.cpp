#include <iostream>
#include <string>
#include "fraction.h"

#define DEBUG 0
using namespace std;

void debug( string str )
{
	if ( DEBUG == 1 )
		cout << str << endl;
}

// Конструктор без параметров //
Fraction::Fraction( void )
{
	// Default values //
	this->top    = 0;
	this->bottom = 1;

	debug( "Fraction null was created." );
}

// Основной конструктор //
Fraction::Fraction( int top, int bottom )
{
	this->top    = top;
	this->bottom = bottom;

	debug( "Number was created!" );
}

// Конструктор копирования //
Fraction::Fraction( Fraction &copy )
{
	copy.top    = this->top;
	copy.bottom = this->bottom
;
	debug( "Number object was copied!" );
}

// Деструктор //
Fraction::~Fraction()
{
	debug( "Object was destructed!" );
}

// Ввод числа //
void Fraction::update( int top, int bottom )
{
	this->top    = top;
	this->bottom = bottom;
}

// Вывод числа //
void Fraction::print( void )
{
	cout << this->top << '\\' << this->bottom;
}

// Функция упрощения //
void Fraction::simplify( void )
{
	int i = 2;

	// Если числитель делится на знаменатель без остатка //
	if ( this->top % this->bottom == 0 ) {
		this->top    = this->top / this->bottom;
		this->bottom = 1;
	} else {
		while ( i <= this->bottom ) {
			if ( this->top % i == 0 && this->bottom % i == 0 ) {
				this->top /= i;
				this->bottom /= i;
				i = 2;
			} else {
				i++;
			}
		}
	}

	// Работа со знаками //
	if ( this->top < 0 && this->bottom < 0 || this->bottom < 0 ) {
		this->top    *= -1;
		this->bottom *= -1;
	}
}

// Функция умножения //
Fraction Fraction::multiply( Fraction *second )
{
	int top    = this->top * second->top;
	int bottom = this->bottom * second->bottom;

	Fraction result( top, bottom );
	result.simplify();
	result.print();

	return result;
}

// Функция деления //
Fraction Fraction::divide( Fraction *second )
{
	int top    = this->top * second->bottom;
	int bottom = this->bottom * second->top;

	Fraction result( top, bottom );
	result.simplify();
	result.print();

	return result;
}

// Функция сложения //
Fraction Fraction::plus( Fraction *second )
{
	int top    = this->top * second->bottom + second->top * this->bottom;
	int bottom = this->bottom * second->bottom;

	Fraction result( top, bottom );
	result.simplify();
	result.print();

	return result;
}

// Функция вычитания //
Fraction Fraction::minus( Fraction *second )
{
	int top    = this->top * second->bottom - second->top * this->bottom;
	int bottom = this->bottom * second->bottom;

	Fraction result( top, bottom );
	result.simplify();
	result.print();

	return result;
}

ostream& operator<<( ostream& os, Fraction& p )
{
	cout << "Вывод дроби в консоль: ";
	p.print();

	return os;
}

istream& operator>>( istream& is, Fraction& p )
{
	cout << "Сработал оператор ввода данных!" << endl;
	cout << "Введите числитель: ";
	cin  >> p.top;
	cout << "Введите знаменатель: ";
	cin  >> p.bottom;

	p.simplify();
	cout << "Дробь обновлена!" << endl;

	return is;
}