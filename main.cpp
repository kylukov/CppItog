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

int currentStudent = 0;
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
    Lesson marks[9][11][2];
};

/* {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}}
*/


void updatePositionOnStudentMenu(char operand, int amount_of_students){
    system("clear");
    if (operand == '+'){
        if (currentStudent == amount_of_students - amount_of_deleted_students) currentStudent = 0;
        else currentStudent++;
    }
    else if (operand == '-'){
        if (currentStudent == 0) currentStudent = amount_of_students - amount_of_deleted_students;
        else currentStudent--;
    }

}

void updatePositionOnEditingMenu(char operand){
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

void Draw_79_variant_chosen(struct Student* student, int amount_of_students){
    system("clear");
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Список студентов")) / 2 + sizeof("Список студентов")) << setfill(' ') << "Список студентов" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    for (int i = 0; i < amount_of_students-amount_of_deleted_students; i++) {
        string FIO = to_string(i+1) + " " + student[i].surName + " " + student[i].name + " " + student[i].thirdName + " " + student[i].group;
        if (i == currentStudent) {
            cout << "  >   " << setfill(' ') << FIO << endl; continue;
        }
        else {
            cout << "      "  << setfill(' ') << FIO << endl; }
    }

    cout << "  >   ВАРИАНТ 79" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
}

void DrawAllStudentsMenu(struct Student* student, int amount_of_students) {
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Список студентов")) / 2 + sizeof("Список студентов")) << setfill(' ') << "Список студентов" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    if (currentStudent != amount_of_students){
        for (int i = 0; i < amount_of_students; i++) {
            string FIO = to_string(i+1) + " " + student[i].surName + " " + student[i].name + " " + student[i].thirdName + " " + student[i].group;
            if (i == currentStudent) {
                cout << "  >   " << setfill(' ') << FIO << endl; continue;
            }
            else {
                cout << "      "  << setfill(' ') << FIO << endl; }
        }

        cout << "      ВАРИАНТ 79" << endl;
        cout.width(64); cout.fill('-'); cout << "-" << endl;
    }
    else if(currentStudent == 11) {
        Draw_79_variant_chosen(student, amount_of_students);
    }
}

bool compareByYear(const Student &a, const Student &b)
{
    return a.year < b.year;
}


void make79Variant(struct Student *students, int amount_of_students) {
    char b;
    unsigned short *years = new unsigned short[amount_of_students];
    while ((b = getchar()) != 113) {
        std::sort(students, students + amount_of_students, compareByYear); // сортировка массива студентов по возрастанию поля year

        std::cout << "После сортировки:" << std::endl;
        for (int i = 0; i < amount_of_students; ++i)
        {
            std::cout << students[i].surName << " " << students[i].name << " " << students[i].thirdName << ", "
                      << students[i].year << std::endl;
        }


    }
}




void drawTaskMenu(struct Student* student){
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Информация о студенте")) / 2 + sizeof("Информация о студенте")) << setfill(' ') << "Информация о студенте" << endl;
    cout << "      ФИО: " << student[currentStudent].surName << " " << student[currentStudent].name << " " << student[currentStudent].thirdName << endl;
    cout << "      Кафедра: " << student[currentStudent].cafedra << endl;
    cout << "      Факультет: " << student[currentStudent].fac << endl;
    cout << "      Группа: " << student[currentStudent].group << endl;
    cout << "      Номер зачетной книжки: " << student[currentStudent].personal_number << endl;
    cout << "      Пол: " << student[currentStudent].sex << endl;
    cout << "      Год поступления в ВУЗ: " << student[currentStudent].date.day << "." << student[currentStudent].date.month << "." << student[currentStudent].date.year << endl;
    cout << "      Дата рождения: " << student[currentStudent].year << endl;
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
        std::cout << "\t" << i + 1 << ". " << students[currentStudent].marks[chosen_period - 1][i][0].name << ": "
                  << students[currentStudent].marks[chosen_period - 1][i][0].mark
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

    cout << "Введите новую оценку для предмета " << students[currentStudent].marks[chosen_period][pick_to_edit - 1][0].name
         << " за " << chosen_period << " семестр ";
    cin >> edited_mark;
    students[currentStudent].marks[chosen_period][pick_to_edit - 1][0].mark = edited_mark;

}

void delete_student(struct Student *students, int amount_of_students){
    for (int i = currentStudent; i < amount_of_students - 1; i++) {
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
            strcpy(students[currentStudent].surName, edited_surname);
            break;
        }
        case 1:
        {
            char edited_name[40];
            cout << commands[1] << endl;
            cin >> edited_name;
            strcpy(students[currentStudent].name, edited_name);
            break;
        }
        case 2:
        {
            char edited_thirdname[40];
            cout << commands[2] << endl;
            cin >> edited_thirdname;
            strcpy(students[currentStudent].thirdName, edited_thirdname);
            break;
        }
        case 3:
        {
            char edited_cafedra[40];
            cout << commands[3] << endl;
            cin >> edited_cafedra;
            strcpy(students[currentStudent].cafedra, edited_cafedra);
            break;
        }
        case 4:
        {
            char edited_fac[40];
            cout << commands[4] << endl;
            cin >> edited_fac;
            strcpy(students[currentStudent].fac, edited_fac);
            break;
        }
        case 5:
        {
            char edited_group[40];
            cout << commands[5] << endl;
            cin >> edited_group;
            strcpy(students[currentStudent].group, edited_group);
            break;
        }
        case 6:
        {
            char edited_personal_number[40];
            cout << commands[6] << endl;
            cin >> edited_personal_number;
            strcpy(students[currentStudent].personal_number, edited_personal_number);
            break;
        }
        case 7:
        {
            char edited_sex[40];
            cout << commands[7] << endl;
            cout << "M - мужской; Ж - женский" << endl;
            cin >> edited_sex;
            strcpy(students[currentStudent].sex, edited_sex);
            break;
        }
        case 8:
        {
            unsigned short edited_year;
            cout << commands[8] << endl;
            cin >> edited_year;
            students[currentStudent].year = edited_year;
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
            students[currentStudent].date.day = day;
            students[currentStudent].date.month = month;
            students[currentStudent].date.year = year;
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

void createNavigation(){
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

    DrawAllStudentsMenu(students, count);
    char a;
    while((a = getchar()))
    {
        switch ((int)a) {
            case 115: // s - down
                system("clear");
                updatePositionOnStudentMenu('+', amount_of_students);
                DrawAllStudentsMenu(students, amount_of_students);
                break;
            case 119: // w - up
                system("clear");
                updatePositionOnStudentMenu('-', amount_of_students);
                DrawAllStudentsMenu(students, amount_of_students);
                break;
            case 102: // f - choose
                system("clear");
                if(currentStudent == 11) {
                    make79Variant(students, amount_of_students);
                    currentStudent = 0;
                    system("clear");
                    createNavigation();
                }
                else {
                    drawTaskMenu(students);
                    char b;
                    while((b = getchar())!= 113)
                    {
                        switch ((int)b) {
                            case 115: // s - down
                                updatePositionOnEditingMenu('+');
                                drawTaskMenu(students);
                                break;
                            case 119: // w - up
                                updatePositionOnEditingMenu('-');
                                drawTaskMenu(students);
                                break;
                            case 102: // f - choose
                                system("clear");
                                Edit_Student_Information(students,amount_of_students);
                                drawTaskMenu(students);
                                break;
                            case 113: // q - quit
                                break;
                        }
                    }
                    current_menu = 0;
                    system("clear");
                    DrawAllStudentsMenu(students, amount_of_students);
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
    struct Student students[11] = {
            {"Иванов",     "Иван",       "Иванович",      {01, 02, 2010}, 1975, "Привет",       "КБ - 2", "БИСО-01-19", "1231Б4123", "М",
                    {{{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}},
                            {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}},
                            {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}},
                            {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}},
                            {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}},
                            {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}},
                            {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}},
                            {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}},
                            {{"Физическая культура", 5}, {"Математика", 4}, {"Биология", 5}, {"Литература", 3}, {"Физика", 4}, {"Философия", 3}, {"Химия", 5}, {"Английский язык", 4}, {"Информатика", 5}, {"История", 5}}}},
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

    ofstream fout("students.dat", ios::binary);
    for(int i = 0; i < 11; i++)
        fout.write((char*)&students[i], sizeof(Student));
    fout.close();

    createNavigation();
    return 0;
}