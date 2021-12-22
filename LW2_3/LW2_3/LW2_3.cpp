// Сурков Д. 8В01
// ЛР 3 Вариант 30

#include <iostream>
using namespace std;

class Triad {
    public:
    int d,  m,  y;


    void set(int X = 0, int Y = 0, int Z = 0) {
        d = (X);
        m = (Y);
        y = (Z);
    }


    void compare() {
        if (d > m) cout << d << " > " << m;
        else if (m > d) cout << d << " < " << m;

        if (m > y) cout << " > " << y << endl;
        else if (y > m) cout << " < " << y << endl;

        else { cout << d << m << y << "cho?"; };
    }
};


class Date : public Triad {
    public:
    void print_date(Date input) {
        cout << input.d << "." << input.m << "." << input.y << " ";
    }


    void compare_with_date(Date input) {
        if (y > input.y) {
            print_date(*this);
            cout << "> ";
            print_date(input);
        }

        else if (y < input.y) {
            print_date(*this);
            cout << "< ";
            print_date(input);
        }

        else if (m > input.m) {
            print_date(*this);
            cout << "> ";
            print_date(input);
        }

        else if (m < input.m) {
            print_date(*this);
            cout << "< ";
            print_date(input);
        }
        else if (d > input.d) {
            print_date(*this);
            cout << "> ";
            print_date(input);
        }

        else if (d < input.d) {
            print_date(*this);
            cout << "< ";
            print_date(input);
        }
        else {
            print_date(*this);
            cout << "= ";
            print_date(input);
        }

    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Triad tr1;
    tr1.set(3, 2, 4);

    cout << "Метод класса Triad: ";
    tr1.compare();


    Date d1, d2;

    d1.set(23, 12, 2000);
    d2.set(14, 10, 1999);

    cout << "Метод класса Date: ";
    d1.compare_with_date(d2);
    cout << endl;

    cout << "Метод класса Triad вызываемый объектом типа Date: ";
    d2.compare();
    cout << endl;
}

