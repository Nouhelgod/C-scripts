// Сурков Д. А. 
// ЛР 2 Вариант 30

#include <iostream>
//#include <iomanip>
#include <math.h>
using namespace std;


int main() {
	double x1 = -1, x2 = 3;
	double h = 0.2;
	double y;
	double x = x1;

	cout.precision(2);
	cout.width(20);
	cout << "x" << " | " << "y\n";

	while (x >= x1 && x <= x2 + h) {

		if (x > 0) {
			y = x * sinh(x);
		} 

		else if (x <= 0)
		{
			y = (1 - cos(x)) / (1 + 2 * sin(3 * x));
		}

		cout.width(20);
		cout << x << " | " << y << "\n";

		x += h;

	}
}