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
int amount_of_deleted_students = 0;

string commands[12] = {
        "Добавить/удалить фамилию",
        "Добавить/удалить имя",
        "Добавить/удалить отчество",
        "Добавить/удалить кафедру",
        "Добавить/удалить факультет",
        "Добавить/удалить группу",
        "Добавить/удалить номер зачетной книжки",
        "Добавить/удалить пол",
        "Добавить/удалить год поступления в ВУЗ" ,
        "Добавить/удалить дату рождения",
        "Посмотреть оценки",
        "Удалить студента"
};

struct Lesson
{
    char name[40]{};
    int mark;
};

struct Date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

class Student
{
    public:
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
        Lesson marks[9][11][2];
};

/* {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}}
*/


void current_update(char operand, int amount_of_students){
    system("clear");
    if (operand == '+'){
        if (current == amount_of_students+1) current = 0;
        else current++;
    }
    else if (operand == '-'){
        if (current == 0) current = amount_of_students+1;
        else current--;
    }

}

void current_menu_update(char operand){
    system("clear");
    if (operand == '+'){
        if (current_menu == 11) current_menu = 0;
        else current_menu++;
    }
    else if (operand == '-'){
        if (current_menu == 0) current_menu = 11;
        else current_menu--;
    }
}

void draw41VariantChosen(struct Student* student, int amount_of_students){
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
    cout.width(64); cout.fill('-'); cout << "-" << endl;
}

void Draw_List_Of_Students(struct Student* student, int amount_of_students) {
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Список студентов")) / 2 + sizeof("Список студентов")) << setfill(' ') << "Список студентов" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    if (current != amount_of_students+1-amount_of_deleted_students){
        for (int i = 0; i < amount_of_students-amount_of_deleted_students; i++) {
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
    else if(current == 11) {
        draw41VariantChosen(student, amount_of_students);
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
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Выберите команду")) / 2 + sizeof("Выберите команду")) << setfill(' ') << "Выберите команду" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    /// варианты команд
    for(int i = 0; i < 12; i++){
        if (i == current_menu) { cout << "  >   "  << setfill(' ') << commands[i] << endl; continue;}
        else cout << "      "  << setfill(' ') << commands[i] << endl;
    }
    cout.width(64); cout.fill('-'); cout << "-" << endl;
}

void show_marks(struct Student *students) {
    system("clear");
    char a;


    int chosen_period, pick_to_edit, edited_mark;
    cout.width(64);cout.fill('-');cout << "-" << endl;
    cout << "Выберите семестр за который хотите посмотреть оценки [1: 9]" << endl;
    cout.width(64);cout.fill('-');cout << "-" << endl;
    cin >> chosen_period;

    cout.width(64);cout.fill('-');cout << "-" << endl;
    cout << "       Оценки за " << chosen_period << " семестр" << endl;
    cout.width(64);cout.fill('-');cout << "-" << endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "\t" << i + 1 << ". " << students[current].marks[chosen_period - 1][i][0].name << ": "
                  << students[current].marks[chosen_period - 1][i][0].mark
                  << std::endl;
    }
    cout.width(64);
    cout.fill('-');
    cout << "-" << endl;
    cout << "Для выхода нажмите q" << endl;
    cout << "Для редактирования оценок введите номер строки для редактирования" << endl;
    cout.width(64);
    cout.fill('-');
    cout << "-" << endl;
    cin >> pick_to_edit;

    cout << "Введите новую оценку для предмета " << students[current].marks[chosen_period][pick_to_edit - 1][0].name
         << " за " << chosen_period << " семестр ";
    cin >> edited_mark;
    students[current].marks[chosen_period][pick_to_edit - 1][0].mark = edited_mark;

}

void delete_student(struct Student *students, int amount_of_students){
    for (int i = current; i < amount_of_students - 1; i++) {
        students[i] = students[i + 1];
    }

    amount_of_students--;
    amount_of_deleted_students++;


    ofstream fout("students.dat", ios::binary);
    for(int i = 0; i < amount_of_students; i++)
        fout.write((char*)&students[i], sizeof(Student));
    fout.close();
}

void Edit_Student_Information(struct Student *students, int amount_of_students){
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
        case 10:
        {
            show_marks(students);
            break;
        }
        case 11:
        {
            delete_student(students, amount_of_students);
            break;
        }
        default:
            cout << "Ошибка отображения навигационного меню, попробуйте снова" << endl;
            current_menu = 0;
            break;
    }
}

void create_navigation(){
    ifstream fin("students.dat", ios_base::binary);

    if (!fin) {
        cout << "Failed to open students.dat!";
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

    int amount_of_students = count;
    fin.close();

    Draw_List_Of_Students(students, count);
    char a;
    while((a = getchar()))
    {
        switch ((int)a) {
            case 115: // s - down
                system("clear");
                current_update('+', amount_of_students);
                Draw_List_Of_Students(students, amount_of_students);
                break;
            case 119: // w - up
                system("clear");
                current_update('-', amount_of_students);
                Draw_List_Of_Students(students, amount_of_students);
                break;
            case 102: // f - choose
                system("clear");
                if(current == 11) {
                    make_41_variant(students, amount_of_students);
                    current = 0;
                    system("clear");
                    create_navigation();
                }
                else {
                    Draw_Task_Menu(students);
                    char b;
                    while((b = getchar())!= 113)
                    {
                        switch ((int)b) {
                            case 115: // s - down
                                current_menu_update('+');
                                Draw_Task_Menu(students);
                                break;
                            case 119: // w - up
                                current_menu_update('-');
                                Draw_Task_Menu(students);
                                break;
                            case 102: // f - choose
                                system("clear");
                                Edit_Student_Information(students,amount_of_students);
                                Draw_Task_Menu(students);
                                break;
                            case 113: // q - quit
                                break;
                        }
                    }
                    current_menu = 0;
                    system("clear");
                    Draw_List_Of_Students(students, amount_of_students);
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
    create_navigation();
    return 0;
}
