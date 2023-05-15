//Задача 4:
//Реализуйте программу «Заметки». В начале программы должен выводиться список доступных заметок – список текстовых файлов в директории программы.
//Пользователь может выбрать заметку и считать с неё информацию или создать новую заметку.

#include <iostream>
#include <cstdio>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <locale>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

using namespace std;
namespace fs = filesystem;

const string current_path = fs::current_path().string();

enum mode
{
    command_request
};

struct Note
{
    string header;
    string filename;
    Note(const string &h, const string &f)
    {
        this->header = h;
        this->filename = f;
    }
};

string read_file_header(const string f_name)
{

    string file_data = "";
    ifstream fin(f_name);

    if (!fin.is_open())
    {
        fin.close();
        return "No open file!";
    }

    getline(fin, file_data);
    fin.close();

    return file_data;
}

string read_file_text(const string f_name)
{

    string file_data, current_str = "";
    ifstream fin(f_name);

    if (!fin.is_open())
    {
        fin.close();
        return "No open file!";
    }

    //Первая строка - заголовок. Пропустим
    getline(fin, current_str);

    while (getline(fin, current_str))
    {
        file_data = file_data + "\n" + current_str;
    }

    fin.close();

    return file_data;
}

void fill_note_list(vector<Note> &note_list)
{
    note_list.clear();

    for (const auto &entry : fs::directory_iterator(current_path))
    {
        if (entry.path().extension() == ".txt")
        {
            note_list.push_back(Note(read_file_header(entry.path().filename().string()), entry.path().filename().string()));
        }
    }

    // cout << entry.path() << " - " << entry.path().filename() << " - "<< fs::is_directory(entry.path()) << " - " << entry.path().extension() << endl;
};

void inter_note()
{
    string current_line;
    vector<std::string> v;
    string f_name = "";
    int i = 1;

    ifstream fin;

    while (true)
    {
        f_name = "note" + to_string(i) + ".txt";
        fin.open(f_name);

        if (fin.fail())
        {
            fin.close();
            break;
        }

        fin.close();
        i++;
    }

    ofstream fout(f_name, ios_base::trunc);

    if (!fout.is_open())
    {
        cout << "No open file!";
        return;
    }

    cout << "Введите заголовок заметки:";

    while (getline(cin, current_line))
    {
        if (!current_line.empty())
        {
            break;
        }
    }

    fout << current_line << endl;

    cout << endl;
    cout << "Введите текст заметки (пустая строка - окончание ввода):";
    cout << endl;

    while (getline(cin, current_line))
    {
        if (current_line.empty())
        {
            break;
        }
        v.push_back(current_line);
    }

    for (string &s : v)
    {
        fout << s << endl;
    }
}

void delete_note(string f_name)
{
    // char f[f_name.length()];
    // f_name.copy(f, f_name.length());

    char *f = new char[f_name.length() + 1];
    f_name.copy(f, f_name.length());
    f[f_name.length()] = '\0';

    // cout << f;
    // cout <<
    remove(f);

    // int i;
    // cin >> i;
}

void draw(string &command, vector<Note> &note_list)
{

    string note_text = "";
    int note_number = 0;

    if (command == "n")
    {

        inter_note();
        // fill_note_list(note_list);
    }

    fill_note_list(note_list);

    if (command == "r")
    {
        cout << endl
             << "Введите номер заметки :";
        cin >> note_number;

        if ((note_number > 0) && (note_number <= note_list.size()))
        {
            note_text = read_file_text(note_list[note_number - 1].filename);
        }
        else
        {
            note_text = "Неверный номер заметки " + to_string(note_number);
        }
    }

    if (command == "d")
    {

        cout << endl
             << "Введите номер заметки :";
        cin >> note_number;

        if ((note_number > 0) && (note_number <= note_list.size()))
        {
            delete_note(note_list[note_number - 1].filename);
            fill_note_list(note_list);
        }
    }

    string current_path = fs::current_path().string();

    system("cls");

    cout << "Текущая директория: ";
    cout << current_path << endl;
    cout << "================================================================================================" << endl;
    cout << "Список команд: n - новая заметка; r - прочитать заметку; d - удалить заметку; q - выйти из программы." << endl;
    cout << "================================================================================================" << endl;
    cout << "Список заметок:" << endl;
    for (size_t i = 0; i < note_list.size(); i++)
    {
        cout << "Заметка № " << i + 1 << "   - " << note_list[i].header << "  (" << note_list[i].filename << ")" << endl;
    };
    cout << endl;
    cout << "================================================================================================" << endl;

    if (command == "r")
    {

        cout << "Содержание заметки № " << note_number << ":" << endl;
        cout << "Заголовок: " << note_list[note_number - 1].header << endl
             << endl;
        cout << note_text;
        cout << endl;
        cout << "================================================================================================" << endl;
        cout << endl;
    }

    cout << endl
         << endl;

    command = "";

    cout << "Введите команду: ";
    cin >> command;
};

int main()
{
    string command = "";
    vector<Note> note_list;

    while (command != "q")
    {
        draw(command, note_list);
    }

    system("cls");
    return 0;
}