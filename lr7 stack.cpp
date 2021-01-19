// lr7 stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
    element* last;
};

void constructor(Stack& mystack)
{  
    mystack.last = nullptr;
}
void destructor(Stack& mystack) {

    while (mystack.last != nullptr) {
        element* abc = mystack.last;
        mystack.last = mystack.last->prev;
        delete abc;
    }
}

unsigned int size(Stack& mystack) {
    unsigned int counter = 0;
    element* abc = mystack.last;
    while (abc != nullptr) {
        abc = abc->prev;
        counter++;
    }
    cout << "stack contains " << counter << " elements";
    return counter;
}

void push(Stack& mystack, element& elem) {
    if (mystack.last == nullptr) {
        element* new_el = new element;
        new_el->value = elem.value;     
        mystack.last = new_el;
    }
    else {
        element* new_elem = new element;
        new_elem->value = elem.value;
        new_elem->prev = mystack.last;
        mystack.last = new_elem;
    }
    
}
element pop(Stack& mystack) {
    element* abc = mystack.last;
    mystack.last = mystack.last->prev;
    element elem = *abc;
    delete abc;
    return elem;
}
void print(Stack& mystack) {

    element* abc = mystack.last;
    while (abc != nullptr) {
        cout << abc->value << " ";
        abc = abc->prev;
    }
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
    print(mystack);
    cout << endl;
    size(mystack);
    pop(mystack);
    cout << endl;
    print(mystack);
    cout << endl;
    size(mystack);
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
