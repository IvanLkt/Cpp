#include <iostream>
#include <cmath>



int main()
{
    double mid = 0.0;
    double left = 0.0;
    double right = 1.0;
    double result = 0.0;
    double result_old = 0.0;
    while (1)
    {
        mid = (left + right) / 2;
        result = exp(mid)-1-cos(mid);
        if (result < 0)       // ���� ������� ������ �������� � ������
            left = mid;      // ������� ������ ������� ������
        else if (result > 0)  // ���� ������� ������ �������� � ������
            right = mid;       // ������� ����� ������� ������
        else                      // ����� (�������� �����)
            return mid;           // ������� ���������� ������ ������

        std::cout << 'result'<< '\n';
        /*double tochnost = fabs(result_old - result);
        if (tochnost < 0.0001)         // ���� �������
        {
            std::cout << "tochnost:  " << tochnost << '\n';
            break;
        }

        result_old = result;*/

    }
    std::cout << "result:  " << result;;
}
