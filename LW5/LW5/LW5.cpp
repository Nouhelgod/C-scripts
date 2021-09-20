// Сурков Д. А. 8В01
// ЛР 5 Вариант 30

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int n_1, n_2, m;

    cout << "Введите n_1, n_2, m: \n";
    cin >> n_1 >> n_2 >> m;

    vector<int> p(m);

    if (!(m > n_1 && m > n_2)) {
        cout << "Значение m должно быть больше n_1 и n_2! \n";
    }

    else {
        int total = 0, sum = 0;

        for (int i = 0; i < m; i++) {
            p[i] = i;

            if (p[i] >= n_1 && p[i] <= n_2) {
                total++;
                sum += p[i];
            }
        }

        cout << "\nКоличество индексов находящихся в диапазоне: " << total << endl;
        cout << "Их сумма: " << sum << endl;

    }
}
