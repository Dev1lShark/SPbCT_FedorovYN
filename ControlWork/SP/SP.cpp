#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include <locale.h>
using namespace std;
class Course
{
private:
    string subject, date;
    int auditory, time;
public:
    Course(string, int, string, int);
    string to_string() {                                        
        string out = "\n\tДень недели: " + date +
            "\n\tВремя: " + std::to_string(time) +
            "\n\tПредмет: " + subject +
            "\n\tАудитория: " + std::to_string(auditory);
        return out;
    }
    string to_string_ff() {                                     
        string out = date +
            "\n" + std::to_string(time) +
            "\n" + subject +
            "\n" + std::to_string(auditory) + "\n";
        return out;
    }
    bool is_req_date(string c_date){                               
        return c_date == date;
    }
};

Course::Course(string c_date, int c_time, string c_subject, int c_auditory) {
    date = c_date;
    time = c_time;
    subject = c_subject;
    auditory = c_auditory;
}

class Schedule 
{
    list <Course> courses;                              
    public:
    void add_course(Course c) {                   
        courses.push_back(c);
    }
    string to_string_all() {                                   
        string str = "";  
        int i;
        list <Course>::iterator pos_begin;
        for (pos_begin = courses.begin(), i = 1; pos_begin != courses.end(); ++pos_begin, i++) {
            Course c = *pos_begin;
            str += "\nCourse[" + std::to_string(i) + "]";
            str += c.to_string();  
        }
        return str;
    }
    string to_string_all_ff() {                        
        string str = "";
        int i;
        list <Course>::iterator pos_begin;
        for (pos_begin = courses.begin(), i = 1; pos_begin != courses.end(); ++pos_begin, i++) {
            Course c = *pos_begin;
            str += c.to_string_ff();
        }
        return str;
    }

    void list_clear() {                                 
        courses.clear();
    }
    string to_string_by_date(string date) {                  
        string str = "";
        int i;
        list <Course>::iterator pos_begin;
        for (pos_begin = courses.begin(), i = 1; pos_begin != courses.end(); ++pos_begin, i++) {
            Course c = *pos_begin;
            if (c.is_req_date(date)) {
                str += "\nCourse[" + std::to_string(i) + "]";
                str += c.to_string();
            }
        }
        return str;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Schedule schedule = Schedule();
    int num;
    string req_date, c_date, c_subject;
    int c_auditory, c_time;
    cout << "Меню: \n[0]-Выход, \n[1]-Ввод, \n[2]-Импорт, \n[3]-Печать, \n[4]-Распечатать на день, \n[5]-Удалить всё, \n[6]-Загрузить в файл, \n[7]-Удалить из файла";
    cout << "\nВведите число: ";
    cin >> num;
    for (; num != 0;) {
        switch (num) {
        case(0): break;                                         //выход
        case(1):                                                //запись ногого урока в список
            cout << "День: ";
            cin >> c_date;
            cout << "\n Время: ";
            cin >> c_time;
            cout << "\n Предмет: ";
            cin >> c_subject;
            cout << "\n Аудитория: ";
            cin >> c_auditory;
            schedule.add_course(Course(c_date, c_time, c_subject, c_auditory));
            break;
        case(2): {                                                //загрузка записей из файла
            ifstream file("../a.txt");
            if (!file.is_open()) {
                cout << "Файл не найден";
                break;
            };
            if (file.eof()) {
                cout << "Файл пустой";
                break;
            };
            for (; !file.eof();) {
                string date_str, time_str, c_subject, auditory_str;
                getline(file, date_str);
                cout << date_str << endl;
                getline(file, time_str);
                cout << time_str << endl;
                getline(file, c_subject);
                cout << c_subject << endl;
                getline(file, auditory_str);
                cout << auditory_str << endl;
                c_date = date_str;
                c_time = stoi(time_str);
                c_subject = c_subject;
                c_auditory = stoi(auditory_str);

                schedule.add_course(Course(c_date, c_time, c_subject, c_auditory));
            };
            cout << "\nУспешно импортированно из файла.";
            file.close();
            break;
        };
        case(3):                                             //вывод всех записей, имеющихся в списке
            cout << "\nРезультат: " << schedule.to_string_all();
            break;
        case(4):           //вывод всех уроков, которые заисаны на день, который был введен пользователем
            cout << "\nВведите день:"; cin >> req_date;
            cout << "\nРезультат: " << schedule.to_string_by_date(req_date);
            break;
        case(5):                                                //удаление всех записей из списка
            schedule.list_clear();
            cout << "\n Лист был очищен";
            break;
        case(6):                                                 //загрузка всего списка в файл
        {
            ofstream out;
            out.open("../a.txt");
            if (out.is_open())
            {
                out << schedule.to_string_all_ff();
            }
            cout << "Записи обновлены";
            out.close();
            break;
        };
        case(7):                                                  //удаление всех записей из файла
        {
            ofstream out;
            out.open("../a.txt");
            if (out.is_open())
            {
                out << " " << std::endl;
            }
            cout << "Записи удалены";
            out.close();
            break;
        };
        };
        cout << "\nВведите номер: ";
        cin >> num;
    };
};
