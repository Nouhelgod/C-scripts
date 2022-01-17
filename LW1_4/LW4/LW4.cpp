// Сурков Д. А. 8В01
// ЛР 4 Вариант 30

#include <iostream>
#include <math.h>

using namespace std;


double A(int i, double A_1, double A_2) {
	double A_i;

	A_i = (cos(A_1 + 1.1 * i) / sin(A_2)) - 0.5 * (A_1);

	return A_i;
}

int main()
{
	setlocale(LC_ALL, "rus");
	double A_1 = 1.2, A_2 = 0.9;
	double A_i_min = A_2;
	double A_i;
	int i_min = 3, i_max = 20;
	int i = i_min;

	while (i >= i_min && i <= i_max) {
		A_i = A(i, A_1, A_2);
		A_1 = A_2;
		A_2 = A_i;

		if (A_i < A_i_min) {
			A_i_min = A_i;
		}
		
		cout << "i = " << i;
		cout << " A_i = " << A_i << "\n";
		i++;
	}

	cout << endl << "Минимальное значение функции: " << A_i_min << endl;
}