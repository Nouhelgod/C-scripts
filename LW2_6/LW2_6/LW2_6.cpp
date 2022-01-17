// Сурков Д. А. 8В01
// ЛР 6 Вариант 30

#include <iostream>
#include <random>
using namespace std;

int rnd() {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(0, 9);
    return uni(rng);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int N;

    cout << "Введите N (0 - 99): ";
    cin >> N;

    const int range = N;
    int* array = new int[range];

    int even = 0;
    int odd = 0;

    for (int i = 0; i < range; i++) {
        array[i] = rnd();

        if (array[i] % 2 == 0) {
            even += 1;
        }
        else {
            odd += 1;
        }

        cout << array[i] << " ";
    }

    int* modarray = new int[range + odd];

    int shift = 0;
    even = 0;
    for (int i = 0; i < (range); i++) {
        if (array[i] % 2 == 0) {
            modarray[i + shift] = array[i];
            even += 1;
            cout << modarray[i + shift] << " ";
        }
        else {
            modarray[i + shift] = array[i];
            cout << modarray[i + shift] << " ";
            shift += 1;
            modarray[i + shift] = even;
            cout << "(" << modarray[i + shift] << ") ";
        }
    }
}

