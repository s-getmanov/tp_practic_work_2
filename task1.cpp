//Задача 1:
//Написать программу, которая создаёт текстовый файл и записывает в него строку, введённую пользователем в консоль.

#include <iostream>
#include <fstream>

using namespace std;

int main(){

    string user_input = "";
    ofstream fout("outstream.txt", ios_base::trunc);

    if (!fout.is_open()){
        cout << "No open file!";
        return -1;
    }

    cout << "Vvedite stroku: ";
    cin >> user_input;

    cout << "Stroka : " << user_input << " zapisana v fail";

    fout << user_input;
    fout.close();

    return 0;
}