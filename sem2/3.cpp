#include <iostream>
#include <stdio.h>

void bad_incrementor(int &x)
{
    int* px = &x;

    (*px)++;
    std::cout << "x changed: "<< *px << std::endl;
}

int main()
{
    int x = 1;
    //std::cin >> x;
    std::cout << "x before changed:"<< x << std::endl;
    bad_incrementor(x);
    std::cout << "x after changed:"<< x << std::endl;

    return 0;
}
