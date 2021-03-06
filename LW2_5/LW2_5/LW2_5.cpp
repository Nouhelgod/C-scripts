// Сурков Д. А. 8В01
// ЛР 5 Вариант 2

#include <iostream>
#include <fstream>
#include <string> 

using namespace std;
string FILEPATH = "D:\\Docks\\C++ scripts\\LW2_5\\LW2_5\\input_string.txt";


template<typename T>
class Arr {
public:
    T* arr;
    int size;

    Arr(int s) {
        size = s;
        arr = new T[size];
    }

    ~Arr() {
        delete[] arr;
    }

    void operator = (Arr& other) {
        this.size = other.size;
        this.arr = new T[size];

        for (int i = 0; i < size; i++) {
            this->arr[i] = other.arr[i];
        }
    }

    T& operator [] (int index) {
        return this->arr[index];
    }

    void print() {
        for (int i = 0; i < this->size; i++) {
            cout.width(4);
            cout << arr[i];
        }

        cout << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    string line;
    int length = 0;
    

    ifstream file(FILEPATH);
    getline(file, line);

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',') {
            length++;
        }
    }
    length++;

    Arr<int> input_string(length);
    string op_str;
    int point = 0;

    for (int i = 0; i < (line.length() + 1); i++) {
        if (line[i] == ',' or i == line.length()) {
            input_string[point] = stoi(op_str);
            op_str = "";
            point++;
        }
        else {
            op_str += line[i];
        }
    }

    input_string.print();

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            input_string[i] *= 2;
        }
        else {
            input_string[i] *= 3;
        }
    }

    input_string.print();
}

