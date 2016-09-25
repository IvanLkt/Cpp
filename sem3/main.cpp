#include <iostream>
#include <cstdlib>

struct Coordinate
{
    int x;
    int y;
    Coordinate *next;
    Coordinate *prev; //��������� �� ����. ������. �������� ������
};

struct List
{
    Coordinate *head;
    Coordinate *tail; // ��������� �� ������ � ����� ������
};

void add_dot( List *list, int x, int y)
{
        Coordinate *temp = new Coordinate(); // ��������� ������ ��� ����� ������� ���������
        temp->next = NULL;       // ���������, ��� ���������� �� ���������� ������ �����
        temp->x = x;             // ���������� �������� � ���������
        temp->y = y;

        if ( list->head != NULL ) // ���� ������ �� ����
        {
                temp->prev = list->tail; // ��������� ����� �� ���������� ������� � �����. ����
                list->tail->next = temp; // ��������� ����� ���������� �� ������� ��������
                list->tail = temp;       //������ ����� ������
        }
        else //���� ������ ������
        {
                temp->prev = NULL; // ���������� ������� ��������� � �������
                list->head = list->tail = temp;    // ������=�����=��� �������, ��� ������ ��������
        }
}

void print_dot( List *list )
{
        Coordinate * temp = list->head;  // �������� ��������� �� ����� ������� ��������
        while( temp != NULL )      // ���� �� �������� ������ ��������
        {
                std::cout <<"x:" <<temp->x << "y:" << temp->y << " "; //������� �������� �� �����
                temp = temp->next;     //����� ������ �� ����� ���������� ��������
        }
        std::cout<<"\n";
}


int main()
{
        //std::cout << "������� 20 ��� ���������"<<"\n";
        List *List1 = new List;
        for (int i = 0; i < 20; i++)
        {
            int x = 2;
            int y = 2;
            //x = std::rand();
            //y = std::rand();

            //std::cin >> x >> y;
            add_dot(List1, x, y);
        }
        std::cout<<"List is full";
        //print_dot(List1);
        return 0;

}
