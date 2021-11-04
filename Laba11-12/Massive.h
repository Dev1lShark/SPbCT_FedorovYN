#pragma once
#include <iostream>
#include "Complex.h"
using namespace std;

//задание шаблога класса
template <class T> class mas {
    T* a;
    int n;
    void Create() {
        a = new T[n];
    }

public:
    mas(int size) : n(size) { Create(); }; //конструктор
    ~mas() { /*delete[] a;  */ } //деструктор

    void input() { //ввод элементов
        cout << "\nВведите " << n << " элемента(-ов): ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void print() { //вывод массива на экран
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }


    /*bool operator==(const (mas a)& (mas b)) const
    {
        if (number != array2.number) return false;
        for (int i = 0; i < number; i++) {
            if (arr[i] != array2.arr[i]) return false;
        }
        return true;
    }

    bool operator!=(const array& array2) const
    {
        if (number == array2.number) return false;
        for (int i = 0; i < number; i++) {
            if (arr[i] == array2.arr[i]) return false;
        }
        return true;
    }*/

    //Перегрузка оператора ==.
    bool operator == (mas  b)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b.a[i]);
            else return  false;
        }
        return true;
    }
    //Перегрузка оператора !=.
    bool operator != (mas  b)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b.a[i]);
            else return true;
        }
        return false;
    }
  

    /* В строках следующих строках перегружаем оператор индексирования[].
    На место вызова[] вернется по ссылке сам объект и в ячейку его массива mas под номером i
    мы сможем записать целое число.*/
    T& operator[](int i) //перегрузка []     
    {
        return a[i];
    }

    //перегруженный оператор присваивания =
    mas<T> operator=(mas b)
    {
        a = b.a;
        return *this;
    }

};
