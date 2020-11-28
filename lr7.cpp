// lr7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct element
{
    element* next = nullptr;
    int value ;
};


struct queue
{
    element* first;
    element* last;
};

void constructor(queue& que) {

    que.first = nullptr;
    que.last = nullptr;
}

void destructor(queue& que) {

    while (que.first != nullptr) {
        element* abc = que.first;
        que.first = que.first->next;
        delete abc;
    }
}

unsigned int size( queue& que) {
    unsigned int counter = 0;
    element* abc = que.first;
    while (que.first != nullptr) {
      que.first = que.first->next;
        counter++;
    }
    return counter;
}

void push(queue& que, element& elem) {
    if (que.first == nullptr) {
        element* new_el = new element;
        new_el->value = elem.value;
        que.first = new_el;
        que.last = new_el;
    }
    else if (que.first != nullptr) {
        element* new_elem = new element;
        new_elem->value = elem.value; 
        que.last->next = new_elem;
        que.last = new_elem;
    }
}

element pop(queue& que)
{
    int a = que.first->value;
    element elem;
    element* abc = que.first;
    que.first = que.first->next;
    elem.value = a;
    elem.next = que.first;
    return elem;
}
int main()
{
    queue que;
    constructor(que);
    element elem;
    int a;
    for (int i = 0; i < 5; ++i) {
        std::cin >> a;
       elem.value = a;
        push(que, elem);
    }  
    elem = pop(que);
    cout << " element " << elem.value << " was deleted" <<  endl;
    cout << "there is " << size(que) << " in queue." << endl;
    destructor(que);
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
