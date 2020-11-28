// lr7stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

    struct element
    {
        element* prev = nullptr;
        int value;
    };

    struct Stack
    {
        element* first;
        element* last;
    };

    void constructor(Stack & mystack)
    {
        mystack.first = nullptr;
        mystack.last = nullptr;
    }
    void destructor(Stack& mystack) {
        while (mystack.first != nullptr) {
            element* abc = mystack.last;
            mystack.last = mystack.last->prev;
            delete mystack.last;        
        }
    }

    unsigned int size(Stack& mystack) {
        unsigned int counter = 0;
        element* abc = mystack.last;
        while (mystack.last != nullptr) {
            mystack.last = mystack.last->prev;
            counter++;
        }
        return counter;
    }

    void push(Stack& mystack, element& elem) {
        if (mystack.first == nullptr) {
            element* new_el = new element;
            new_el->value = elem.value;
            mystack.first = new_el;
            mystack.last = new_el;
        }
        else if (mystack.first != nullptr) {
            element* new_elem = new element;
            new_elem->value = elem.value;
            mystack.last->prev = new_elem;
            mystack.last = new_elem;
        }
    }
    element pop(Stack& mystack) {
        int a = mystack.last->value;
        element elem;
        element* abc = mystack.last;
        mystack.last = mystack.last->prev;
        elem.value = a;
        elem.prev = mystack.last;
        return elem;
    }
    int main()
    {

        Stack mystack;
        constructor(mystack);
        element elem;
        int a;
        for (int i = 0; i < 5; ++i) {
            std::cin >> a;
            elem.value = a;
            push(mystack, elem);
        }
        elem = pop(mystack);
        cout << " element " << elem.value << " was deleted" << endl;
        cout << " size of the stack is :" << size(mystack) << endl;
        destructor(mystack);
        return 0;




    }

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
