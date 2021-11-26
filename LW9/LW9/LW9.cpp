// Сурков Д. А. 8В01
// ЛР 9 Вариант 30

#include <iostream>
#include <math.h>
using namespace std;


double f(double x) {
    return(x / (pow(x, 4) + 3 * pow(x, 2) + 2));
}


double s(double f(double), int a, int b, double n = 0.1) {
    double total_s = 0;
    double h = 0;

    for (double i = a; i <= b; i += n) {
        h = f(i);
        double s = h * n;
        total_s += s;
    }

    return total_s;
}


int main()
{
    double a = 1.0;
    double b = 2.0;

    cout << "1) " << s(f, a, b) << endl;
    cout << "2) " << s(f, a, b, 0.00000001) << endl;
    cout << "3) " << f(b) - f(a) << endl;
}

