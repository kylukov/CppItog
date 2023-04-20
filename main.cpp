//
//  main.cpp
//  CppLast
//
//  Created by Andrey Kulikov on 22.03.2023.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int current = 0;
int current_menu = 0;

string commands[10] = {
        "Добавить/удалить фамилию",
        "Добавить/удалить имя",
        "Добавить/удалить отчество",
        "Добавить/удалить кафедру",
        "Добавить/удалить факультет",
        "Добавить/удалить группу",
        "Добавить/удалить номер зачетной книжки",
        "Добавить/удалить пол",
        "Добавить/удалить год поступления в ВУЗ" ,
        "Добавить/удалить дату рождения"
};

struct Lesson {
    string name_of_lesson;
    unsigned short mark;
};


struct Date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Student
{
    char surName[40];
    char name[40];
    char thirdName[40];
    struct Date date;
    unsigned short year;
    char fac[40];
    char cafedra[40];
    char group[40];
    char personal_number[40];
    char sex[40];
    //vector<Lesson> marks;
};
// {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}}
struct Student student[11] = {
        {"Иванов",     "Иван",       "Иванович",      {01, 02, 2010}, 1975, "Привет",       "КБ - 2", "БИСО-01-19", "1231Б4123", "М"},
        {"Кузнецов",   "Тимур",      "Николаевич",    {02, 07, 2012}, 2000, "Привет",       "КБ - 2", "БИСО-01-19", "1231Б4123", "М"},
        {"Сидоров",    "Николай",    "Андреевич",     {21, 06, 2014}, 1990, "Добрый день",  "ПТ - 1", "МТ-03-19",   "1233Б4123", "М"},
        {"Ковалев",    "Дмитрий",    "Сергеевич",     {15, 12, 2011}, 1985, "Здравствуйте", "ТР - 4", "ИКТ-01-19",  "1234Б4123", "М"},
        {"Новикова",   "Елена",      "Ивановна",      {03, 01, 2015}, 1995, "Добрый день",  "КБ - 1", "БИСО-02-19", "1235Б4123", "Ж"},
        {"Федоров",    "Вячеслав",   "Игоревич",      {22, 05, 2016}, 1996, "Привет",       "КДМ-2",  "ФИТ-01-19",  "1236Б4123", "М"},
        {"Шишкин",     "Анатолий",   "Петрович",      {10, 01, 2018}, 2000, "Здравствуйте", "ПТ - 3", "МТ-02-19",   "1237Б4123", "М"},
        {"Козлова",    "Анастасия",  "Васильевна",    {27, 11, 2017}, 1999, "Добрый день",  "ТР - 1", "ИКТ-02-19",  "1238Б4123", "Ж"},
        {"Михайлов",   "Максим",     "Валерьевич",    {05, 02, 2019}, 2001, "Привет",       "КБ - 3", "БИСО-03-19", "1239Б4123", "М"},
        {"Григорьева", "Александра", "Александровна", {18, 07, 2016}, 1996, "Здравствуйте", "КДМ-1",  "ФИТ-03-19",  "1240Б4123", "Ж"},
        {"Попов",      "Илья",       "Олегович",      {30, 03, 2013}, 1988, "Добрый день",  "ПТ - 2", "МТ-01-19",   "1241Б4123", "М"}
};
int amount_of_students = sizeof(student) / sizeof(Student);

void current_update(char operand){
    system("clear");
    if (operand == '+'){
        if (current == 11) current = 0;
        else current++;
    }
    else if (operand == '-'){
        if (current == 0) current = 11;
        else current--;
    }

}

void current_menu_update(char operand){
    system("clear");
    if (operand == '+'){
        if (current_menu == 9) current_menu = 0;
        else current_menu++;
    }
    else if (operand == '-'){
        if (current_menu == 0) current_menu = 9;
        else current_menu--;
    }
}

void Draw_List_Of_Students(struct Student* student) {
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Список студентов")) / 2 + sizeof("Список студентов")) << setfill(' ') << "Список студентов" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    for (int i = 0; i < amount_of_students; i++) {
        string FIO = to_string(i+1) + " " + student[i].surName + " " + student[i].name + " " + student[i].thirdName + " " + student[i].group;
        if (i == current) {
            cout << "  >   " << setfill(' ') << FIO << endl; continue;
        }
        else {
            cout << "      "  << setfill(' ') << FIO << endl; }
    }

    cout << "      ВАРИАНТ 41" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;

}

void Draw_Task_Menu(struct Student* student){
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    /// данные о студенте
    cout << setw( (64 - sizeof("Информация о студенте")) / 2 + sizeof("Информация о студенте")) << setfill(' ') << "Информация о студенте" << endl;
    cout << "      ФИО: " << student[current].surName << " " << student[current].name << " " << student[current].thirdName << endl;
    cout << "      Кафедра: " << student[current].cafedra << endl;
    cout << "      Факультет: " << student[current].fac << endl;
    cout << "      Группа: " << student[current].group << endl;
    cout << "      Номер зачетной книжки: " << student[current].personal_number << endl;
    cout << "      Пол: " << student[current].sex << endl;
    cout << "      Год поступления в ВУЗ: " << student[current].date.day << "." << student[current].date.month << "." << student[current].date.year << endl;
    cout << "      Дата рождения: " << student[current].year << endl;
    /*
    cout << "      Текущие оценки" << endl;
    for(int i = 0; i < student[current].marks.size(); i++){
        cout << "      - " << student[current].marks[i].name_of_lesson << ": " << student[current].marks[i].mark << endl;
    }
    */
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Выберите команду")) / 2 + sizeof("Выберите команду")) << setfill(' ') << "Выберите команду" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    /// варианты команд
    for(int i = 0; i < 10; i++){
        if (i == current_menu) { cout << "  >   "  << setfill(' ') << commands[i] << endl; continue;}
        else cout << "      "  << setfill(' ') << commands[i] << endl;
    }
    cout.width(64); cout.fill('-'); cout << "-" << endl;
}

void Edit_Student_Information(){
    system("clear");
    switch (current_menu) {
        case 0:
        {
            char edited_surname[40];
            cout << commands[0] << endl;
            cin >> edited_surname;
            strcpy(student[current].surName, edited_surname);
            break;
        }
        case 1:
        {
            char edited_name[40];
            cout << commands[1] << endl;
            cin >> edited_name;
            strcpy(student[current].name, edited_name);
            break;
        }
        case 2:
        {
            char edited_thirdname[40];
            cout << commands[2] << endl;
            cin >> edited_thirdname;
            strcpy(student[current].thirdName, edited_thirdname);
            break;
        }
        case 3:
        {
            char edited_cafedra[40];
            cout << commands[3] << endl;
            cin >> edited_cafedra;
            strcpy(student[current].cafedra, edited_cafedra);
            break;
        }
        case 4:
        {
            char edited_fac[40];
            cout << commands[4] << endl;
            cin >> edited_fac;
            strcpy(student[current].fac, edited_fac);
            break;
        }
        case 5:
        {
            char edited_group[40];
            cout << commands[5] << endl;
            cin >> edited_group;
            strcpy(student[current].group, edited_group);
            break;
        }
        case 6:
        {
            char edited_personal_number[40];
            cout << commands[6] << endl;
            cin >> edited_personal_number;
            strcpy(student[current].personal_number, edited_personal_number);
            break;
        }
        case 7:
        {
            char edited_sex[40];
            cout << commands[7] << endl;
            cout << "M - мужской; Ж - женский" << endl;
            cin >> edited_sex;
            strcpy(student[current].sex, edited_sex);
            break;
        }
        case 8:
        {
            unsigned short edited_year;
            cout << commands[8] << endl;
            cin >> edited_year;
            student[current].year = edited_year;
            break;
        }
        case 9:
        {
            unsigned short day, month, year;
            cout << commands[9] << endl;

            cout << "Введите день: ";
            cin >> day;

            cout << "Введите месяц: ";
            cin >> month;

            cout << "Введите год: ";
            cin >> year;
            student[current].date.day = day;
            student[current].date.month = month;
            student[current].date.year = year;
            break;
        }
        default:
            cout << "Ошибка отображения навигационного меню, попробуйте снова";
            current_menu = 0;
            break;
    }
}

void create_navigation(){
    Draw_List_Of_Students(student);
    char a;
    while((a = getchar()))
    {
        switch ((int)a) {
            case 115: // s - down
                system("clear");
                current_update('+');
                Draw_List_Of_Students(student);
                break;
            case 119: // w - up
                system("clear");
                current_update('-');
                Draw_List_Of_Students(student);
                break;
            case 102: // f - choose
                system("clear");
                Draw_Task_Menu(student);
                char b;
                while((b = getchar())!= 113)
                {
                    switch ((int)b) {
                        case 115: // s - down
                            current_menu_update('+');
                            Draw_Task_Menu(student);
                            break;
                        case 119: // w - up
                            current_menu_update('-');
                            Draw_Task_Menu(student);
                            break;
                        case 102: // f - choose
                            system("clear");
                            Edit_Student_Information();
                            Draw_Task_Menu(student);
                            break;
                        case 113: // q - quit
                            break;
                    }
                }
                current_menu = 0;
                system("clear");
                Draw_List_Of_Students(student);
                break;
            case 113:
                ofstream fout("STR.bin", ios::binary);

                fout.write((char *) &student[0], sizeof(Student));

                fout.close();
                return;
        }
    }
}

int main()
{
    create_navigation();
    return 0;
}
