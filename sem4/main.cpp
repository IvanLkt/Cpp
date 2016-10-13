#include <cstdlib>
#include <iostream>
#include <cmath>

const int N_MAX = 10000;

using namespace std;

struct Node       //Структура являющаяся звеном списка
{
    int x;//Значение x будет передаваться в список
    Node *next, *prev; //Указатели на адреса следующего и предыдущего элементов списка
};


struct List   //Создаем тип данных Список
{
    Node *head;
    Node *tail;  //Указатели на адреса начала списка и его конца
};

int myHash(int x){   // ключ
    return x % N_MAX;
}

struct hashTable{          // создание хеш-таблицы
    List *values = new List[N_MAX];
};

void add( hashTable *table, int x)
{
    Node *temp = new Node(); // Выделение памяти под новый элемент структуры
    temp->next = NULL;       // Указываем, что изначально по следующему адресу пусто
    temp->x = x;
    int key = myHash(x);
    List &current = table->values[key];   //ереходим по пути таблица- список по заданому ключу
    if ( current.head != NULL ) // Если список не пуст
    {
        temp->prev = current.tail; // Указываем адрес на предыдущий элемент
        (table->values[key]).tail->next = temp; // Указываем адрес следующего за последним элемента
        (table->values[key]).tail = temp;       //Меняем адрес последнего элемента
    }
    else //Если список пустой
    {
        temp->prev = NULL;      // Предыдущий элемент указывает в пустоту
        (table->values[key]).head = (table->values[key]).tail = temp;    // новый элемнт по адресу первого и последнего элементов
    }
}

int find(hashTable *table, int checking_x){

    int key = myHash(checking_x);
    Node * temp = (table->values[key]).head;
    int i = -1;
    if (temp != NULL)
        i = 0;
    while (temp != NULL){
        if ((temp->x == checking_x)) {
            break;
        }
        temp = temp->next;
        i++;
    }
    return i;
}

int main(void){

    hashTable *table = new hashTable;
    for (int i = 0; i < 20; i++) {
        int x = rand() / 1000000;
        add(table, x);
    }
    cout << find(table, 198) << endl;
    cout << find(table, 19807) << endl;
    return 0;
}