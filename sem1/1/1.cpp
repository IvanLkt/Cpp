#include <iostream>

int A[20] = {31, 30, 69, 8, 74, 11, 40, 7, 48, 26, 65, 43, 73, 89, 44, 67, 41, 95, 55, 68};


int main()
{
    for (int j = 0; j < 20; j ++)
    {
            for (int i = 0; i < 20; i ++)
        {
            if (A[i] > A[i + 1])
            {
                int tmp = 0;
                tmp = A[i + 1];
                A[i + 1] = A[i];
                A[i] = tmp;

            }

        }

    }
    for(int i = 0; i < 20; i++)
    std::cout << A [i] <<' ';
}
