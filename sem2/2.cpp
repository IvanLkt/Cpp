#include <iostream>
#include <stdio.h>

void bad_incrementor(int *x)
{


    (*x)++;
    std::cout << "x changed: "<< *x << std::endl;
}

int main()
{
    int x = 1;
    //std::cin >> x;
    std::cout << "x before changed:"<< x << std::endl;
    bad_incrementor(&x);
    std::cout << "x after changed:"<< x << std::endl;

    return 0;
}
