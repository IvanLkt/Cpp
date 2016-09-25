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
        if (result < 0)       // если искомое меньше значени€ в €чейке
            left = mid;      // смещаем правую границу поиска
        else if (result > 0)  // если искомое больше значени€ в €чейке
            right = mid;       // смещаем левую границу поиска
        else                      // иначе (значени€ равны)
            return mid;           // функци€ возвращает индекс €чейки

        std::cout << 'result'<< '\n';
        /*double tochnost = fabs(result_old - result);
        if (tochnost < 0.0001)         // если границы
        {
            std::cout << "tochnost:  " << tochnost << '\n';
            break;
        }

        result_old = result;*/

    }
    std::cout << "result:  " << result;;
}
