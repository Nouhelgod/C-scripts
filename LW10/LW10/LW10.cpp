// Сурков Д. А. 8В01    
// ЛР10 Вариант 30

#include <iostream>
#include <sstream>

using namespace std;

void selectionSort(int data[], int lenD)
{
    int j = 0;
    int tmp = 0;

    for (int i = 0; i < lenD; i++) {
        j = i;

        for (int k = i; k < lenD; k++) {

            if (data[j] > data[k]) {
                j = k;
            }

        }

        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}


int main()
{   
    int origin;
    
    cin >> origin;
    int* arr = new int[sizeof(origin)];

    for (int i = 1; i < sizeof(origin); i++) {
        arr[i] = origin % int(pow(10, i)) / int(pow(10, i-1));
    }

    selectionSort(arr, sizeof(arr));

    for (int i = 1; i < sizeof(arr); i++) {
        cout << arr[sizeof(arr) - i];
    }
}

