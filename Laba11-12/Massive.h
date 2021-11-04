#pragma once
#include <iostream>
#include "Complex.h"
using namespace std;

//������� ������� ������
template <class T> class mas {
    T* a;
    int n;
    void Create() {
        a = new T[n];
    }

public:
    mas(int size) : n(size) { Create(); }; //�����������
    ~mas() { /*delete[] a;  */ } //����������

    void input() { //���� ���������
        cout << "\n������� " << n << " ��������(-��): ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void print() { //����� ������� �� �����
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

    //���������� ��������� ==.
    bool operator == (mas  b)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b.a[i]);
            else return  false;
        }
        return true;
    }
    //���������� ��������� !=.
    bool operator != (mas  b)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b.a[i]);
            else return true;
        }
        return false;
    }
  

    /* � ������� ��������� ������� ����������� �������� ��������������[].
    �� ����� ������[] �������� �� ������ ��� ������ � � ������ ��� ������� mas ��� ������� i
    �� ������ �������� ����� �����.*/
    T& operator[](int i) //���������� []     
    {
        return a[i];
    }

    //������������� �������� ������������ =
    mas<T> operator=(mas b)
    {
        a = b.a;
        return *this;
    }

};
