#include <iostream>
#include <cstdlib>

struct Coordinate
{
    int x;
    int y;
    Coordinate *next;
    Coordinate *prev; //указатели на след. предыд. элементы списка
};

struct List
{
    Coordinate *head;
    Coordinate *tail; // указатели на начало и конец списка
};

void add_dot( List *list, int x, int y)
{
    Coordinate *temp = new Coordinate(); // Выделение памяти под новый элемент структуры
    temp->next = NULL;       // Указываем, что изначально по следующему адресу пусто
    temp->x = x;             // Записываем значение в структуру
    temp->y = y;

    if ( list->head != NULL ) // Если список не пуст
    {
        temp->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = temp; // Указываем адрес следующего за хвостом элемента
        list->tail = temp;       //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->prev = NULL; // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;    // Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void print_dot( List *list )
{
    Coordinate * temp = list->head;  // Временно указываем на адрес первого элемента
    while( temp != NULL )      // Пока не встретим пустое значение
    {
        std::cout <<"x:" <<temp->x << " " << "y:" << temp->y << " " << std::endl; //Выводим значение на экран
        temp = temp->next;     //Смена адреса на адрес следующего элемента
    }
    std::cout<<std::endl;
}


void findFirst (List *list, int check_x, int check_y){
    Coordinate * temp = list->head;
    int i = 1;
    while (temp != NULL){
        if ((temp->x == check_x) && (temp->y == check_y)) {
            std::cout << " place from the begin" << i << std::endl;
            break;
        }
        temp = temp->next;
        i++;
    }
}


void findLast (List *list, int check_x, int check_y) {
    Coordinate * temp = list->tail;
    int i = 1;
    while (temp != NULL){
        if ((temp->x == check_x) && (temp->y == check_y)) {
            std::cout << " place from the end" << i << std::endl;
            break;
        }
        temp = temp->prev;
        i++;
    }
}


void addIndex (List *list, int index, int X, int Y){
    Coordinate * temp = list->head;
    for(int i = 1; i < index; i++){
        temp = temp->next;
    }
    Coordinate * newElem = new Coordinate;
    newElem->x = X;
    newElem->y = Y;
    temp->prev->next = newElem;
    newElem->prev = temp->prev;
    temp->prev = newElem;
    newElem->next = temp;
}


void popIndex(List *list, int index){
    Coordinate * temp = list->head;
    for(int i = 2; i < index; i++){
        temp = temp->next;
    }
    Coordinate * new_tmp = temp->next->next;
    temp->next = new_tmp;
    new_tmp->prev = temp;
}


int main()
{
    List *List1 = new List;
    for (int i = 0; i < 20; i++)
    {
        int x;
        int y;
        x = std::rand();
        y = std::rand();

        //std::cin >> x >> y;
        add_dot(List1, x, y);
    }
    print_dot(List1);
    return 0;

}