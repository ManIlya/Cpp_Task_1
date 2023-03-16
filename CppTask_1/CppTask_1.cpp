// CppTask_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int** createArray(int row, int column)
{
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[column];
    return arr;

}
void deleteArray(int** arr, int row)
{
    for (int i = 0; i < row; i++)
        delete arr[i];
    delete arr;

}
void initArray(int** arr, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void printArray(int** arr, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << arr[i][j];
        }
    }
}

void initVector(int** arr, bool* vec, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        vec[i] = true;
        for (int j = 1; j < column; j++)
        {
            if (arr[i][j] <= arr[i][j - 1])
            {
                vec[i] = false;
                break;
            }
        }
    }
}

void printVector(bool* vec, int size) {
    for (int i = 0; i < size; i++) 
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите количество строк и столбцов:" << endl;
    int n, m;
    cin >> n >> m;
    int ** arr = createArray(n, m);

    cout << "Заполните массив:" << endl;
    initArray(arr, n, m);

    bool* vec = new bool[n];

    initVector(arr, vec, n, m);
    
    deleteArray(arr, n);

    printVector(vec, n);
    delete vec;




}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
