//Задача 2:
//Написать программу, которая считывает строку из файла, созданного в предыдущем задании, и выводит эту строку в консоль.

#include <iostream>
#include <fstream>

using namespace std;

int main(){

    string file_data = "";
    ifstream fin("outstream.txt");

    if (!fin.is_open()){
        cout << "No open file!";
        return -1;
    }  

    fin >> file_data;
    fin.close();

    cout << "Stroka : " << endl << file_data << endl<< "prochitana is faila" ;

    return 0;
}