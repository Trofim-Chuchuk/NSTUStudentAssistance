#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> void printVector(vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout <<endl;
}
template <typename T> void processArrays(vector<vector<T>>& Arr, int rows, int colum) {
    Arr = vector<vector<T>>(rows, vector<T>(colum));

    // Задаем seed для генератора случайных чисел
    srand(time(0));
    
    // Генерируем случайное число от 1 до 100 
    for (auto& row : Arr) {
        generate(row.begin(), row.end(), []() { return rand() % 100; });
    }
    cout << "Матрица:" << endl;
    for (const auto& row : Arr) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    auto maxRow = max_element(Arr.begin(), Arr.end(),
                              [](const vector<int>& row1, const vector<int>& row2) {
                                  return *max_element(row1.begin(), row1.end()) < *max_element(row2.begin(), row2.end());
                              });
    auto maxColumn = max_element((*maxRow).begin(), (*maxRow).end());
    size_t maxRowIndex = distance(Arr.begin(), maxRow);
    size_t maxColumnIndex = distance((*maxRow).begin(), maxColumn);

    // Перестановка строк с использованием std::swap
    swap_ranges(Arr[0].begin(), Arr[0].end(), Arr[maxRowIndex].begin());

    // Перестановка столбцов с использованием std::swap
    for (auto& row : Arr) {
        swap(row[0], row[maxColumnIndex]);
    }

    // Вывод исходной и измененной матриц
    cout << "Исходная матрица:" << endl;
    for (const auto& row : Arr) {
        for (int element : row) {
            cout << element << "\t";
        }
        cout << endl;
    }
    
    cout<<"Конец"<<endl;
}

int main(int argc, char* argv[])
{
    // Первое задание
    cout << "Первое задание: "<< endl;
    vector<int> a(5,1);
    printVector(a);

    cout << "---------------------------------------- "<< endl;
    
    // Второе задание
    cout << "Второе задание: "<< endl;
    vector<vector<int>> Arr;
    cout << "Введите через enter количество строк, а затем количество колонок  "<< endl;
    int rows, colum;
    cin >> rows >> colum;
    processArrays(Arr, rows, colum);
    return 0;
}
