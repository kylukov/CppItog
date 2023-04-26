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
    unsigned short mark{};
};


struct Date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Student
{
    char surName[40]{};
    char name[40]{};
    char thirdName[40]{};
    struct Date date{};
    unsigned short year{};
    char fac[40]{};
    char cafedra[40]{};
    char group[40]{};
    char personal_number[40]{};
    char sex[40]{};
    Lesson marks[2][1];
};

/* {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}}

struct Student students[11] = {
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
*/

void download_students(){
    Student students[11];
    ifstream fin("students.dat", ios::binary);

    if(fin)
    {
        for(int i = 0; i < 11; i++)
        {
            fin.read((char*)&students[i], sizeof(Student));
        }
    }
    else
    {
        // Обработка ошибки открытия файла
        cout << "Ошибка открытия файла!" << endl;
    }
}

void current_update(char operand){
    system("clear");
    if (operand == '+'){
        if (current == 12) current = 0;
        else current++;
    }
    else if (operand == '-'){
        if (current == 0) current = 12;
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

void Draw_41_variant_choosen(struct Student* student, int amount_of_students, int current){
    system("clear");
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

    cout << "  >   ВАРИАНТ 41" << endl;
    cout << "      Добавить нового студента" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
}

void Draw_Add_New_Student(struct Student* student, int amount_of_students, int current){
    system("clear");
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
    cout << "  >   Добавить нового студента" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
}

void Draw_List_Of_Students(struct Student* student, int amount_of_students, int current) {
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Список студентов")) / 2 + sizeof("Список студентов")) << setfill(' ') << "Список студентов" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    if (current != 11 && current != 12){
        for (int i = 0; i < amount_of_students; i++) {
            string FIO = to_string(i+1) + " " + student[i].surName + " " + student[i].name + " " + student[i].thirdName + " " + student[i].group;
            if (i == current) {
                cout << "  >   " << setfill(' ') << FIO << endl; continue;
            }
            else {
                cout << "      "  << setfill(' ') << FIO << endl; }
        }

        cout << "      ВАРИАНТ 41" << endl;
        cout << "      Добавить нового студента" << endl;
        cout.width(64); cout.fill('-'); cout << "-" << endl;
    }
    else if(current == 11) {
        Draw_41_variant_choosen(student, amount_of_students, current);
    }
    else {
        Draw_Add_New_Student(student, amount_of_students, current);
    }
}

int show_how_many_male(struct Student *students, int amount_of_students){
    int amount = 0;
    for(int i = 0; i < amount_of_students; i++)
        if (strcmp(students[i].sex, "М") == 0) amount++;
    return amount;
}

int show_how_many_female(struct Student *students, int amount_of_students){
    int amount = 0;
    for(int i = 0; i < amount_of_students; i++)
        if (strcmp(students[i].sex, "Ж") == 0) amount++;
    return amount;
}

void make_41_variant(struct Student *students, int amount_of_students){
    char b;
    while((b = getchar())!= 113) {
        const int male_amount = show_how_many_male(students, amount_of_students);
        char male[male_amount][128];
        int male_index = 0;
        for (int i = 0; i < amount_of_students; i++) {
            char current_male[128];
            strcpy(current_male, "");
            strcpy(male[male_index], "");
            if (strcmp(students[i].sex, "М") == 0) {
                strcat(current_male, students[i].surName); strcat(current_male, " ");
                strcat(current_male, students[i].name); strcat(current_male, " ");
                strcat(current_male, students[i].thirdName);
                strcat(male[male_index], current_male);
                male_index++;
            }
        }

        for (int i = 0; i < male_amount; i++) {
            for (int j = i + 1; j < male_amount; j++) {
                if (strcmp(male[i], male[j]) > 0)
                    swap(male[i], male[j]);
            }
        }
        cout << "        Отсортированые списки" << endl;
        cout.width(64);
        cout.fill('-');
        cout << "-" << endl;
        cout << "        Мужчины" << endl;
        cout.width(64);
        cout.fill('-');
        cout << "-" << endl;
        for (int i = 0; i < male_amount; i++) {
            cout << "      " << male[i] << endl;
        }

        const int female_amount = show_how_many_female(students, amount_of_students);
        char female[female_amount][128];
        int female_index = 0;
        for (int i = 0; i < amount_of_students; i++) {
            char current_female[128];
            strcpy(current_female, "");
            strcpy(female[female_index], "");
            if (strcmp(students[i].sex, "Ж") == 0) {
                strcat(current_female, students[i].surName); strcat(current_female, " ");
                strcat(current_female, students[i].name); strcat(current_female, " ");
                strcat(current_female, students[i].thirdName);
                strcat(female[female_index], current_female);
                female_index++;
            }
        }
        cout.width(64); cout.fill('-'); cout << "-" << endl;
        cout << "        Женщины" << endl;
        cout.width(64); cout.fill('-'); cout << "-" << endl;

        for (int i = 0; i < female_amount; i++) {
            for (int j = i + 1; j < female_amount; j++) {
                if (strcmp(female[i], female[j]) > 0) {
                    swap(female[i], female[j]);
                }
            }
        }

        for (int i = 0; i < female_amount; i++) {
            cout << "      " << female[i] << endl;
        }
        cout.width(64);
        cout.fill('-');
        cout << "-" << endl;
    }


}

void Draw_Task_Menu(struct Student* student, int current, int current_menu){
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


void Edit_Student_Information(struct Student *students){
    system("clear");
    switch (current_menu) {
        case 0:
        {
            char edited_surname[40];
            cout << commands[0] << endl;
            cin >> edited_surname;
            strcpy(students[current].surName, edited_surname);
            break;
        }
        case 1:
        {
            char edited_name[40];
            cout << commands[1] << endl;
            cin >> edited_name;
            strcpy(students[current].name, edited_name);
            break;
        }
        case 2:
        {
            char edited_thirdname[40];
            cout << commands[2] << endl;
            cin >> edited_thirdname;
            strcpy(students[current].thirdName, edited_thirdname);
            break;
        }
        case 3:
        {
            char edited_cafedra[40];
            cout << commands[3] << endl;
            cin >> edited_cafedra;
            strcpy(students[current].cafedra, edited_cafedra);
            break;
        }
        case 4:
        {
            char edited_fac[40];
            cout << commands[4] << endl;
            cin >> edited_fac;
            strcpy(students[current].fac, edited_fac);
            break;
        }
        case 5:
        {
            char edited_group[40];
            cout << commands[5] << endl;
            cin >> edited_group;
            strcpy(students[current].group, edited_group);
            break;
        }
        case 6:
        {
            char edited_personal_number[40];
            cout << commands[6] << endl;
            cin >> edited_personal_number;
            strcpy(students[current].personal_number, edited_personal_number);
            break;
        }
        case 7:
        {
            char edited_sex[40];
            cout << commands[7] << endl;
            cout << "M - мужской; Ж - женский" << endl;
            cin >> edited_sex;
            strcpy(students[current].sex, edited_sex);
            break;
        }
        case 8:
        {
            unsigned short edited_year;
            cout << commands[8] << endl;
            cin >> edited_year;
            students[current].year = edited_year;
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
            students[current].date.day = day;
            students[current].date.month = month;
            students[current].date.year = year;
            break;
        }
        default:
            cout << "Ошибка отображения навигационного меню, попробуйте снова";
            current_menu = 0;
            break;
    }
}

void Add_new_student(struct Student *students){
    for (int i = 0; i < 9; i++){
        Edit_Student_Information(students);
    }
}

void create_navigation(struct Student *students, int amount_of_students){
    Draw_List_Of_Students(students, amount_of_students, current);
    char a;
    while((a = getchar()))
    {
        switch ((int)a) {
            case 115: // s - down
                system("clear");
                current_update('+');
                Draw_List_Of_Students(students, amount_of_students, current);
                break;
            case 119: // w - up
                system("clear");
                current_update('-');
                Draw_List_Of_Students(students, amount_of_students, current);
                break;
            case 102: // f - choose
                system("clear");
                if(current == 11) {
                    make_41_variant(students, amount_of_students);
                    current = 0;
                    system("clear");
                    create_navigation(students, amount_of_students);
                }
                else if(current == 12){
                    Add_new_student(students);
                    current = 0;
                    system("clear");
                    create_navigation(students, amount_of_students);
                }
                else {
                    Draw_Task_Menu(students, current, current_menu);
                    char b;
                    while((b = getchar())!= 113)
                    {
                        switch ((int)b) {
                            case 115: // s - down
                                current_menu_update('+');
                                Draw_Task_Menu(students, current, current_menu);
                                break;
                            case 119: // w - up
                                current_menu_update('-');
                                Draw_Task_Menu(students, current, current_menu);
                                break;
                            case 102: // f - choose
                                system("clear");
                                Edit_Student_Information(students);
                                Draw_Task_Menu(students, current, current_menu);
                                break;
                            case 113: // q - quit
                                break;
                        }
                    }
                    current_menu = 0;
                    system("clear");
                    Draw_List_Of_Students(students, amount_of_students, current);
                    break;
                }
            case 113:
                ofstream fout("students.dat", ios::binary);
                for(int i = 0; i < amount_of_students; i++)
                    fout.write((char*)&students[i], sizeof(Student));
                fout.close();
                return;
        }
    }
}


int main()
{
    ifstream fin("students.dat", ios_base::binary);

    if (!fin) {
        cout << "Failed to open students.dat!";
        return 1;
    }

    int count = 0;
    Student student;
    while (fin.read((char *)&student, sizeof(Student))) {
        count++;
    }
    fin.close();

    Student *students = new Student[count];
    ifstream fini("students.dat", ios::binary);

    if(fini)
    {
        for(int i = 0; i < count; i++)
        {
            fini.read((char*)&students[i], sizeof(Student));
        }
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
    }

    fin.close();
    int amounts_of_people = count;
    create_navigation(students, amounts_of_people);
    return 0;
}
