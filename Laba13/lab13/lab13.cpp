#include <iostream>
#include "Car.h"
#include "Lorry.h"
using namespace std;
void f1(Car& c)
{
	c.Setmark("skoda"); cout << c;
}

Car f2()
{
	Lorry l("Mercedes", 1, 2, 3);
	return l;
}

int main()
{
	Car a;
	cin >> a;
	cout << a;
	Car b("BMW", 4, 115);
	cout << b;
	a = b;
	cout << a;
	a = f2();
	cout << a;
	Lorry c; //создать объект
	cin >> c;//ввести значения атрибутов
	cout << c;//вывести значенияатрибутов
	system("pause");
}