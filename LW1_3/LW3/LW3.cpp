// Сурков Д. А. 8В01 
// ЛР 3 Вариант 30

#include <iostream>
#include <stdio.h>
using namespace std;


void oct_sys(int num) {
	printf("%o", num);
}


int main() {
	
	int width = 6;
	cout.width(width);
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	const int n = 8;
	unsigned short x[n];


	for (int i = 0; i < n; i++) {
		x[i] = rand();

		cout.width(width);
		cout << x[i] << " ";
		oct_sys(x[i]);

		if (x[i] % 2 == 1) {

			for (int j = 0; j < 15; j += 2) {
				x[i] &= ~(1 << j);
			}

		}
		else {
			for (int j = 1; j < 15; j += 2) {
				x[i] |= (1 << j);
			}
		}


		cout.width(width);
		cout << x[i] << " ";
		oct_sys(x[i]);
		cout << "\n";

	}
}