#pragma once
#include <iostream>

using namespace std;
class Complex
{
public:
	int re; // действительная часть
	int im; // мнимая часть
	// необходимые функции и перегруженные операции
	Complex(); //конструктор
	//конструкторы с параметрами
	Complex(int a, int b);
	Complex(const Complex& ob);
	~Complex(); //деструктор

	//перегрузка оператора * для комплексных чисел
	bool operator == (Complex& val)
	{
		if ((this->re == val.re) && (this->im == val.im))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator != (Complex& val)
	{
		if ((this->re == val.re) && (this->im == val.im))
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	//перегрузка оператора = для комплексных чисел
	Complex operator =(Complex com)
	{
		this->re = com.re;
		this->im = com.im;
		return *this;
	}

};
//тело конструктора
Complex::Complex()
{
	re = 0;
	im = 0;
}

//тело конструктора с параметрами
Complex::Complex(int a, int b)
{
	re = a;
	im = b;
}

//тело конструктора с параметрами
Complex::Complex(const Complex& ob)
{
	re = ob.re; im = ob.im;
}

Complex::~Complex() {}

//перегрузка оператора вывода для комплексных чисел
ostream& operator << (ostream& out, const Complex& com)
{
	if (com.im < 0)
		out << com.re << "-" << com.im << "*i\t";
	else
		out << com.re << "+" << com.im << "*i\t";
	return out;
}

//перегрузка оператора ввода для комплексных чисел
istream& operator >> (istream& in, Complex& com) {
	cout << "\nre: ";
	in >> com.re;
	cout << "im: ";
	in >> com.im;
	return in;
}


