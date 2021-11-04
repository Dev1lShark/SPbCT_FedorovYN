#include <iostream>
#include "Complex.h"
#include "Massive.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n; cout << "Введите размер массивов "; cin >> n;
    mas <float> a(n);
    a.input();

    mas <float> b(n);
    b.input();

    cout << "\n*re - действительная часть, im - мнимая часть \n";
    mas <Complex> c(n);
    c.input();

    mas <Complex> d(n);
    d.input();

    cout << "\nМассив A: ";
    a.print();
    cout << "Массив B: ";
    b.print();
    cout << "Массив C: ";
    c.print();
    cout << "Массив D: ";
    d.print();

    if (a==b) cout << "\nМассив A равен массиву B";
    if (a != b) cout << "\nМассив A не равен массиву B";
    if (c == d) cout << "\nМассив C равен массиву D";
    if (c != d) cout << "\nМассив C не равен массиву D";

    cout << "\n\nВведите номер массива, в котором хотите заменить элемент: ";
    int x; cin >> x;
    cout << "Введите номер элемента, в котором хотите заменить: ";
    int l; cin >> l;
    switch (x)
    {
    case 1:
    {
        cout << "Введите число, на которое хотите заменить: ";
        int p; cin >> p;
        a[l - 1] = p;
        cout << "Массив после замены элемента: ";
        a.print();
        break;
    }
    case 2:
    {
        cout << "Введите число, на которое хотите заменить: ";
        int p; cin >> p;
        b[l - 1] = p;
        cout << "Массив после замены элемента: ";
        b.print();
        break;
    }
    case 3:
    {
        cout << "Введите число, на которое хотите заменить действительную часть: ";
        int p; cin >> p;
        c[l - 1].re = p;
        cout << "Введите число, на которое хотите заменить мнимую часть: ";
        int n; cin >> n;
        c[l - 1].im = n;
        cout << "Массив после замены элемента: ";
        c.print();
        break;
    }
    case 4:
    {
        cout << "Введите число, на которое хотите заменить действительную часть: ";
        int p; cin >> p;
        d[l - 1].re = p;
        cout << "Введите число, на которое хотите заменить мнимую часть: ";
        int n; cin >> n;
        d[l - 1].im = n;
        cout << "Массив после замены элемента: ";
        d.print();
        break;
    }
    default:
    {
        cout << "default case\n";
        break;
    }
    }

    if (a == b) cout << "\nМассив A равен массиву B";
    if (a != b) cout << "\nМассив A не равен массиву B";
    if (c == d) cout << "\nМассив C равен массиву D";
    if (c != d) cout << "\nМассив C не равен массиву D";

    cout << "\n\nМассивы после присваивания значений массива B массиву A:" << endl;
    a = b;
    cout << "Массив A ";
    a.print();
    cout << "Массив B ";
    b.print();

    cout << "Массивы после присваивания значений массива D массиву C:" << endl;
    c = d;
    cout << "Массив C: ";
    c.print();
    cout << "Массив D: ";
    d.print();


    return 0;
}