// Перевірити, чи елементи списку – впорядковані за не спаданням.
#include <iostream>
#include <Windows.h>
#include <time.h>

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

using namespace std;
void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
bool check(Elem* L);


int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    Elem* first = NULL,
        * last = NULL;
    for (int i = 1; i <= 10; i++) {
        Info value = 1 + rand() % 10;
        enqueue(first, last, value);
    }


    cout << endl;

    if (check(first)) { // перевірка на те, як елементи впорядковані
        cout << "Елементи впорядковані не за спаданням!" << endl << endl; // якщо елементи не впорядковані за спаданням
    }
    else {
        cout << "Елементи впорядковані за спаданням!" << endl << endl;  // якщо елементи впорядковані за спаданням
    }

    while (last != NULL) {
        cout << dequeue(first, last) << " ";
    }
    cout << endl << endl;


}


void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
    return value;
}

bool check(Elem* L) {
    Info value = L->info;
    while (L->next != NULL)
    {
        L = L->next;
        if (L->info <= value) { // перевірка чи елементи впорядковані за спаданням
            value = L->info;
        }
        else {
            return true;  // якщо не впорядковані за спаданням, то функція поверне true
        }
    }
    return false; // якщо впорядковані за спаданням, то false
}