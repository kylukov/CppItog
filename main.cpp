#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int current = 0;
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
void current_update(char operand){
    if (operand == '+'){
        if (current == 10) current = 0;
        else current++;
    }
    else if (operand == '-'){
        if (current == 0) current = 10;
        else current--;
    }
}



struct Date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Student
{
    string surName;
    string name;
    string thirdName;
    struct Date date;
    unsigned short year;
    string fac;
    string cafedra;
    string group;
    string personal_number;
    string sex;
};

/*
void DrawLine() {
    for (int i = 0; i < 80; i++) {
        cout << "-";
    }
    cout << "\n";
}

char* GetSpacebar(int count) {
    char* msg = new char[count];
    for (int i = 0; i < count; i++)
    {
        msg[i] = ' ';
    }
    msg[count] = '\0';
    return msg;
}

int GetSize(char* msg) {
    int size = 0;
    while (msg[size] != '\0')
        size++;
    return size;
}

void DrawWrong(struct Student* student) {
    DrawLine();
    cout << "| Отдел кадров" << GetSpacebar(80 - sizeof("| Отдел кадров")) << "|\n";
    DrawLine();
    //|Фамилия |Инициалы |Год рожд | Оклад|
    cout << "| Фамилия" << GetSpacebar(21 - sizeof("| Фамилия"));
    cout << "| Инициалы" << GetSpacebar(21 - sizeof("| Инициалы"));
    cout << "| Год рожд" << GetSpacebar(21 - sizeof("| Год рожд"));
    cout << "| Оклад" << GetSpacebar(20 - sizeof("| Оклад")) << "|\n";
    DrawLine();
    for (int i = 0; i < 3; i++) {
        cout << "| " << student[i].surName << GetSpacebar(18 - GetSize(student[i].surName));
        cout << "| " << student[i].ident << GetSpacebar(18 - GetSize(student[i].ident));
        cout << "| " << student[i].year << GetSpacebar(18 - to_string(student[i].year).size());
        cout << "| " << student[i].salary << GetSpacebar(22 - to_string(student[i].salary).size()) << "|\n";
        //cout << "| " << student[i].salary << GetSpacebar(22 - to_string(student[i].salary).size()) << "|\n";
        DrawLine();
    }
    cout << "| Примечание: оклад установлен по состоянию на 1 января 2000 года" << GetSpacebar(80 - sizeof("| Примечание: оклад установлен по состоянию на 1 января 2000 года")) << "|\n";
    DrawLine();
}


void myCentr(string s, int wLine) {

    int w = s.length();
    int delta = (wLine - w) / 2;
    cout << left;
    cout.width(delta); cout << " ";
    cout << s;
    cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
    int w = 10;
    int delta = (wLine - w) / 2 - 1;
    cout << left;
    cout.width(delta); cout << " ";
    if (day > 9) {
        cout << day;
    }
    else {
        cout << "0" << day;
    }
    cout << ".";
    if (month > 9) {
        cout << month;
    }
    else {
        cout << "0" << month;
    }
    cout << ".";
    cout << year;
    cout.width(delta); cout << " ";
}
*/

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


void Draw_List_Of_Students(struct Student* student) {
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Список студентов")) / 2 + sizeof("Список студентов")) << setfill(' ') << "Список студентов" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    for (int i = 0; i < 11; i++) {
        string FIO = to_string(i) + " " + student[i].surName + " " + student[i].name + " " + student[i].thirdName + " " + student[i].group;
        if (i == current) {
            cout << "  >   " << setfill(' ') << FIO << endl; continue;
        }
        else {
            cout << "      "  << setfill(' ') << FIO << endl; }
    }
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

    cout.width(64); cout.fill('-'); cout << "-" << endl;
    cout << setw( (64 - sizeof("Выберите команду")) / 2 + sizeof("Выберите команду")) << setfill(' ') << "Выберите команду" << endl;
    cout.width(64); cout.fill('-'); cout << "-" << endl;
    /// варианты команд
    for(int i = 0; i < 10; i++){
        if (i == current) { cout << "  >   "  << setfill(' ') << commands[i] << endl; continue;}
        else cout << "      "  << setfill(' ') << commands[i] << endl;
    }
    cout.width(64); cout.fill('-'); cout << "-" << endl;
}

void Edit_Student_Information(){
    if (current == 0){
        cout << current;
        string edited_surname;
        cout << commands[1] << endl;
        cin >> edited_surname;
        student[current].surName = edited_surname;
    }
    if (current == 1){
        cout << current;
        string edited_name;
        cout << commands[2] << endl;
        cin >> edited_name;
        student[current].name = edited_name;
    }
}


/*
void task_menu_navigation(struct Student* student){
    char a;
    cout << (int)a << " " << current << endl;
    while((a = getch())!= 27) {
        switch ((int) a) {
            case 115: // s - down
                current_update('+');
                Draw_Task_Menu(student);
                break;
            case 119: // w - up
                current_update('-');
                Draw_Task_Menu(student);
                break;
            case 101: // e - edit
                Edit_Student_Information();
                break;
        }
    }
}

void student_navigation(struct Student* student, char a){
    switch ((int)a) {
        case 115: // s - down
            current_update('+');
            Draw_List_Of_Students(student);
            break;
        case 119: // w - up
            current_update('-');
            Draw_List_Of_Students(student);
            break;
        case 102: // f - choose
            current = 0;
            Draw_Task_Menu(student);
            task_menu_navigation(student);
    }
}
*/

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "Исходные данные:" << endl;
    Draw_List_Of_Students(student);

    char a;
    while((a = getch())!= 113)
    {
        switch ((int)a) {
            case 115: // s - down
                current_update('+');
                Draw_List_Of_Students(student);
                break;
            case 119: // w - up
                current_update('-');
                Draw_List_Of_Students(student);
                break;
            case 102: // f - choose
                Draw_Task_Menu(student);
                current = 0;
                char b;
                while((b = getch())!= 113)
                {
                    cout << (int)b << endl;
                    switch ((int)b) {
                        case 115: // s - down
                            current_update('+');
                            Draw_Task_Menu(student);
                            break;
                        case 119: // w - up
                            current_update('-');
                            Draw_Task_Menu(student);
                            break;
                        case 102: // f - choose
                            Edit_Student_Information();
                            Draw_Task_Menu(student);
                            break;
                        case 113: // q - quit
                            break;
                    }
                }
                Draw_List_Of_Students(student);
                break;
        }
    }

    Draw_Task_Menu(student);





    return 0;
}