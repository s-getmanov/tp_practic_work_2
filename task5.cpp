// Задача 5:
//  Реализовать упрощённый вариант стека –структуры, где всегда доступен только последний добавленный элемент.
//  Элементом стека должна быть структура, хранящая целое число и указатель на элемент.
//  Количество элементов и сами элементы пользователь вводит с консоли, после чего они должны быть выведены в корректно порядке.
//  Не забудьте в конце корректно удалить все элементы стека.

#include <iostream>

using namespace std;

struct Stack
{
    int val = 0;
    Stack *priv = nullptr;
};

int main()
{

    int n = 0;
    cout << "Kolichestvo elementov: ";
    cin >> n;
    cout << "Znacheniya lementov: ";
      
   Stack *stack = new Stack();

    for (size_t i = 0; i < n; i++)
    {
        int tek_val;
        Stack *tec_ptr = stack;

        cin >> tek_val;

        // Это первый элемент, только присвоим значение.
        if (i == 0)
        {
            stack->val = tek_val;
        }
        else
        {
            stack = new Stack();
            stack->priv = tec_ptr;
            stack->val = tek_val;
        }
    }

    // Не совсем понятно, что такое корректный порядок в случае стека, поэтому выведем оба варианта - FIFO и LIFO
    string fifo, lifo = "";
    //Будем получать элементы, пока не дойдем до первого, после чего прервем цикл.
    for (auto it = stack; true; it = it->priv)
    {
        fifo = fifo + " " + to_string(it->val);
        lifo = to_string(it->val) + " " + lifo;

        if (it->priv == nullptr)
        {
           break;
        }        
    }

    cout << "FIFO - " << fifo << endl;
    cout << "LIFO - " << lifo << endl;

    auto it = stack;
    //Будем elfkznm элементы, пока не дойдем до первого, после чего прервем цикл.
    for (; true; )
    {
        Stack *priv_ptr = it->priv;
        delete it;
        it = priv_ptr;
        
        if (it->priv == nullptr)
        {
           break;
        }        
    }
 
}