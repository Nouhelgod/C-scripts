// Сурков Д. А. 8В01
// ЛР 4 Вариант 30

#include <iostream>
using namespace std;


class FazzyNumber {
private:
    int x, e1, e2, a, b, c;

public:
    FazzyNumber(int x_ = 1, int e1_ = 1, int e2_ = 1) {
        x = x_;
        e1 = e1_;
        e2 = e2_;

        a = x - e1;
        b = x;
        c = x + e2;
    }

    int & get_x() { return x; }
    int & get_e1() { return e1; }
    int & get_e2() { return e2; }
    int & get_a() { return a; }
    int & get_b() { return b; }
    int & get_c() { return c; }
    
    void set_a(int A) {
        a = A;
    }

    void  set_b(int B) {
        b = B;
    }

    void  set_c(int C) {
        c = C;
    }

    FazzyNumber operator + (FazzyNumber R) {
        FazzyNumber result;
        result.set_a(b + R.get_b() - a - R.get_a());
        result.set_b(b + R.get_b());
        result.set_c(b + R.get_b() + c + R.get_c());

        return result;
    }

    FazzyNumber operator - (FazzyNumber R) {
        FazzyNumber result;
        result.set_a(b - R.get_b() - a - R.get_a());
        result.set_b(b - R.get_b());
        result.set_c(b - R.get_b() + c + R.get_c());

        return result;
    }

    FazzyNumber operator * (FazzyNumber R) {
        FazzyNumber result;
        result.set_a(b * R.get_b() - R.get_b() * a - b * R.get_a() + a * R.get_a());
        result.set_b(b * R.get_b());
        result.set_c(b * R.get_b() + R.get_b() * a + b * R.get_a() + a * R.get_a());

        return result;
    }

    FazzyNumber operator !() {
        FazzyNumber result;
        if (b > 0) {
            result.set_a(1 / (b + a));
            result.set_b(1 / b);
            result.set_c(1 / (b - c));
        }
        
        return result;
        
    }

    FazzyNumber operator /(FazzyNumber R) {
        FazzyNumber result;
        if (R.get_b() > 0) {
            result.set_a((b - a) / (R.get_b() + R.get_c()));
            result.set_b(b / R.get_b());
            result.set_c((b + c) / (R.get_b() - R.get_a()));
        }

        return result;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    FazzyNumber num1(1, 3, 5);
    FazzyNumber num2(2, 4, 6);

    cout << "num1: (" << num1.get_x() << "-"
        << num1.get_e1() << ", " << num1.get_x() 
        << ", " << num1.get_x() << "+" << num1.get_e2() 
        << ") = (" << num1.get_a() << ", "<< num1.get_b()
        << ", " << num1.get_c() << ")\n";

    cout << "num2: (" << num2.get_x() << "-"
        << num2.get_e1() << ", " << num2.get_x()
        << ", " << num2.get_x() << "+" << num2.get_e2()
        << ") = (" << num2.get_a() << ", " << num2.get_b()
        << ", " << num2.get_c() << ")\n";


    FazzyNumber sum;
    sum = num1 + num2;
    cout << "Сложение: (" << sum.get_a() << ", " << sum.get_b() << ", " << sum.get_c() << ")\n";

    FazzyNumber diff;
    diff = num1 - num2;
    cout << "Вычитание: (" << diff.get_a() << ", " << diff.get_b() << ", " << diff.get_c() << ")\n";

    FazzyNumber mult;
    mult = num1 * num2;
    cout << "Умножение: (" << mult.get_a() << ", " << mult.get_b() << ", " << mult.get_c() << ")\n";

    FazzyNumber rev;
    rev = !num1;
    cout << "Обратное число num1: (" << rev.get_a() << ", " << rev.get_b() << ", " << rev.get_c() << ")\n";

    FazzyNumber div;
    div = num1 / num2;
    cout << "Деление: (" << div.get_a() << ", " << div.get_b() << ", " << div.get_c() << ")\n";
}

