// Сурков Д. А. 8В01
// ЛР 7 Вариант 30

#include <iostream>


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    int WIDTH = 5;
    
    cout << "Значение порядка матрицы: ";
    cin >> n;

    const int range = n;
    int** array = new int* [range];
    srand(time(0));

    // Создание матрицы порядка n и вывод на экран
    for (int i = 0; i < range; i++) {
        array[i] = new int[range];
    }

    for (int i = 0; i < range; i++) {
        cout.width(WIDTH);
        for (int j = 0; j < range; j++) {
            array[i][j] = rand() % 100;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Замена элементов главной диагонали на сумму предыдущих и вывод на экран
    for (int i = 0; i < range; i++) {
        cout.width(WIDTH);
        for (int j = 0; j < range; j++) {
            if (i == j) {
                int sum = 0;

                for (int i = 0; i < j; i++) {
                    sum = sum + array[j][i];
                }

                array[i][j] = sum;
            }
            cout  << array[i][j] << " ";
        }
        cout << endl;
    }


    // Удаление матрицы
    for (int i = 0; i < range; i++) {   
        delete[] array[i];
    }
}

