#include <iostream>
#include <Windows.h>
#include <iomanip> 

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void Insert(Elem*& L, int start, int N)
{
    if (start <= N)
    {
        Info value;
        cout << "a" << start << "="; cin >> value;
        Elem* tmp = new Elem;
        tmp->info = value;
        if (L != NULL)
        {
            Elem* T = L;
            while (T->link != L)
                T = T->link;
            T->link = tmp;
        }
        else
        {
            L = tmp;
        }
        tmp->link = L;
        Insert(L, start + 1, N);
    }
}

void Print(Elem* L, Elem* first, bool check) 
{
    if (L == NULL)
        return;
    if (check == 0)
    {
        first = L;
        cout << setw(0) << L->info;
    }
    if (L->link != first)
    {
        L = L->link;
        cout << setw(3) << L->info;
        Print(L, first, 1);
    }
}

void increm(Elem* L, Elem* first, Info value)
{
    if (L->link != first)
    {
        L->info += value;
        L = L->link;
        if (L->link == first)
        {
            L->info += value;
        }
        increm(L, first, value);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* L = NULL;

    int N, incr;

    cout << "¬вед≥ть к≥льк≥сть елемент≥в: "; cin >> N;

    Insert(L, 1, N);

    cout << endl;

    cout << "—писок: "; Print(L, L, 0); cout << endl;

    cout << "¬вед≥ть число, на €ке потр≥бно зб≥льшити ≥нформац≥йне поле кожного елементу: ";
    cin >> incr; cout << endl;

    increm(L, L, incr);

    cout << "«м≥нений список: "; Print(L, L, 0); cout << endl << endl;

    system("pause");
    return 0;
}