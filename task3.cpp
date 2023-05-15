//Задача 3:
//Создать целочисленную переменную, а также указатель ну эту целочисленную переменную. 
//Вывести в консоль адрес переменной двумя способами (используя саму переменную и указатель на переменную). 
//Также вывести в консоль значение переменной, используя указатель на неё.

#include <iostream>

using namespace std;

int main()
{

    int x = 4;
    int *p_x = &x;

    cout << "Adres peremennoy (&x) = " << &x << endl;
    cout << "Znachenie ukazatelya (p_x) = " << p_x << endl;

    cout << "Znachenie peremennoy (x) = " << x << endl;
    cout << "Znachenie cherez ukazatel (*p_x) = " << *p_x << endl;

}