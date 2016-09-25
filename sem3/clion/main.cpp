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


int main()
{
        //std::cout << "Введите 20 пар координат"<<"\n";
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
        //std::cout<<"List is full";
        print_dot(List1);
        return 0;

}
