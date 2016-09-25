#include <iostream>

void bad_incrementor(int x)
{
    x++;
    std::cout << "x changed: "<< x << std::endl;
}

int main()
{
    int x = 0;
    std::cin >> x;
    std::cout << "x before changed:"<< x << std::endl;
    bad_incrementor(x);
    std::cout << "x after changed:"<< x << std::endl;
}
