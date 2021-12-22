#include <iostream>
#include <locale>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include "ExLib.h"
using namespace std;


void csv() // Процесс
{
    ifstream fs("../1.txt");
    ofstream out("../2.csv");
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
}
int main()
{
    setlocale(LC_ALL, "Russian");
    //Статическая библиотека
    ExLib::Header::Name();
    ExLib::Header::Group();
    ExLib::Header::Day();
    ExLib::Header::Time();
    vector<string> v1(10); // Создание вектора
    string buffer = "";
    ifstream fs("../1.txt");
    ofstream out("../2.csv");
    v1.clear();
    getline(fs, buffer);
    cout << "Ваш файл:\n" << buffer << endl; //Вывод файла
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(buffer.substr(i * 10, 10)); //Запись в вектор
    }
    thread Exel(csv); //Запуск параллельного процесса
    Exel.join();
    cout << "Ваш вектор:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << v1[i] << endl; //Вывод вектора
    }
    
    return 0;
}


