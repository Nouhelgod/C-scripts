// Сурков Д. А. 8В01
// ЛР 2 Вариант 30

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


class Triangle {
private:
	int vertex[6];
public:
	void set_vertex(int min, int max) {
		for(int i = 0; i < 6; i++) {
			vertex[i] = min + rand() % (max - min);
		}
	}

	void display() {
		string j;
		for (int i = 0; i < 6; i += 2) {
			switch (i) {
			case(0):
				j = "A"; break;
			case(2):
				j = "B"; break;
			case(4):
				j = "C"; break;
			default: break;
			}
		cout << "(" << j << ") : " << "[" << vertex[i] << ":" << vertex[i + 1] << "]" << endl;
		}
	}

	void perimeter() {
		double side[3], perimeter = 0.0;

		side[0] = sqrt(pow(vertex[0] - vertex[2], 2) + pow(vertex[1] - vertex[3], 2));
		side[1] = sqrt(pow(vertex[2] - vertex[4], 2) + pow(vertex[3] - vertex[5], 2));
		side[2] = sqrt(pow(vertex[4] - vertex[0], 2) + pow(vertex[5] - vertex[1], 2));

		for (int i=0; i < 3; i++) {
			perimeter += side[i];
		}
		cout << "Perimeter: " << perimeter << endl;
	}

	~Triangle() { /*delete vertex;*/ }
};


int main()
{
	Triangle tr1, tr2, tr3;
	cout << "\ntr1" << endl;
	tr1.set_vertex(-10, 10);
	tr1.display();
	tr1.perimeter();

	cout << "\ntr2" << endl;
	tr2.set_vertex(-100, 100);
	tr2.perimeter();

	cout << "\ntr3" << endl;
	tr3.set_vertex(-10, 0);
	tr3.display();
}