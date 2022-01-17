// Сурков Д. А. 8В01 
// ЛР 1 Вариант 30

#include <iostream>
#include <math.h>
using namespace std;

double logbase(double x, double base)
{
    return log(x) / log(base);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // n
    
    double x, y, z;
    double n;
    cout << "Решение n. Задайте x y z разделив пробелом.\n";
    cin >> x >> y >> z;

    n = (logbase((abs(tan(x)+y)), 2) / ((pow(x, 2)-pow(z, 3)+sqrt(5*y))));
    cout << "n = " << n << "\n\n";

    // s

    double a, b, c;
    double s;
    cout << "Решение s. Задайте a b c разделив пробелом.\n";
    cin >> a >> b >> c;

    if (a < 0) {
        s = (a + pow(b, 2)) / pow(c, 2);
    }
    else if (a >= 0 && a <= 2) {
        s = a + b - sqrt(abs(a + b) / abs(pow(c, 2)));
    }
    else if (a > 2) {
        s = log(a) + b * c - a / b;
    }

    cout << "s = " << s;
}