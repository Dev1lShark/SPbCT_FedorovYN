#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float a, b, c;
		cout << "\na = "; cin >> a;
		cout << "\nb = "; cin >> b;
		cout << "\nc = "; cin >> c;
		if ((a <= 0) || (b <= 0) || (c <= 0) || (a + b < c) || (a + c < b) || (b + c < a))
			cout << "\n Некорректно введённые данные";
		else if (a == b || a == c || b == c)
			cout << "\n Треугольник равнобедренный";
		else 
			cout << "\n Треугольник не равнобедренный.";
}