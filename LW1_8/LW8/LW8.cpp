// Сурков Д. А. 8В01
// ЛР 8 Вариант 29


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string PATH = "D:\\Docks\\C++ scripts\\LW8\\LW8\\nums.txt";

int main()
{
    setlocale(LC_ALL, "Russian");

    int i = 0;
    char sim;
    char last = 'e';

    ifstream orig(PATH);
    if (orig.is_open()) {
        while (orig.get(sim)) {
            cout << sim;
        }
        cout << endl;
        orig.close();
    }


    ifstream mod(PATH);
    if (mod.is_open()) {
        while (mod.get(sim)) {
            if (sim != last) {
                cout << sim;
                last = sim;
            }
            else {
                last = sim;
            }
            i++;
        }
        mod.close();
    }
}