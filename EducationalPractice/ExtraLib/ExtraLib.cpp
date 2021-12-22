#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "ExLib.h"
using namespace std;


namespace ExLib
{
    void Header::Name()// Имя
    {
        cout << "Автор программы: Федоров Ярослав Никитич" << endl; 
    }

    void Header::Group()//Группа
    {
        cout << "Группа: 501" << endl;
    }

    void Header::Day()//Дата
    {
        SYSTEMTIME lt;
        GetLocalTime(&lt);
        cout << "Дата: " << lt.wDay << "." << lt.wMonth << "." << lt.wYear << endl;
    }

    void Header::Time()//Время
    {
        SYSTEMTIME lt;
        GetLocalTime(&lt);
        cout << "Время: " << lt.wHour << ":" << lt.wMinute << ":" << lt.wSecond << endl;
    }

    void Header::file()//Вывод в файл
    {
        ifstream fs("../1.txt");//Открытие файла на чтение
        ofstream out;
        out.open("../2.csv");//Открытие файла на запись
        string buffer;
        getline(fs, buffer);
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                out << buffer.substr(j + 10 * i, 1) << ";"; // Запись в csv файл
            }
            out << buffer.substr(9 + 10 * i, 1) << endl;
        }
        SetFileAttributesW(L"../2.csv", FILE_ATTRIBUTE_READONLY);// Файл только для чтения
        out.close();
    }

}