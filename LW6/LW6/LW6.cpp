// Сурков Д. А. 8В01
// ЛР 6 Вариант 30
// При данных условиях последовательность всегда будет 0 0 0 0 0 0

#include <iostream>
#include <random>
#include <stdio.h>
using namespace std;


int rnd() {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(-9, 9);
    return uni(rng);
}


void generate ()
{
    setlocale(LC_ALL, "Russian");

    const int level = 6;
    int M[level][level], N[level][level];
    int b[level];
    int positives_M = 0, positives_N = 0, negatives_M = 0, negatives_N = 0;

    for (int i = 0; i < level; i++) {
        for (int j = 0; j < level; j++) {
            M[i][j] = rnd();
            N[i][j] = rnd();

            if (M[i][j] > 0) {
                positives_M++;
            }
            else if (M[i][j] < 0) {
                negatives_M++;
            }

            if (N[i][j] > 0) {
                positives_N++;
            }
            else if (N[i][j] < 0) {
                negatives_N++;
            }
        }

        if (positives_M + positives_N <= 3 && negatives_M == positives_N) {
            b[i] = 1;
        }
        else {
            b[i] = 0;
        }

        positives_M = 0;
        positives_N = 0;
        negatives_M = 0;
        negatives_N = 0;
    }

    cout << "Матрица M\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout.width(4);
            cout << M[i][j];
        }
        cout << "\n";
    }

    cout << "Матрица N\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout.width(4);
            cout << N[i][j];
        }
        cout << "\n";
    }
    
    cout << "Последовательность b" << endl;
    for (int i = 0; i < level; i++) {
        cout.width(4);
        cout << b[i];
    }
    cout << "\n";
}


int main() {
    while (true)
    {
        generate();
        cin.get();
        //system("cls");
    }
}
