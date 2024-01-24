#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для обмена строк в массиве
template <typename T> void swapRows(T arr[][2], int row1, int row2) {
    for (int i = 0; i < 2; ++i) {
        swap(arr[row1][i], arr[row2][i]);
    }
}
// Главная функция для генерации, тестирования и вывода результатов
template <typename T,typename T2> void processArrays() {
    const int rows1 = 5;
    const int rows2 = 4;

    // Задаем seed для генератора случайных чисел
    srand(time(0));

    // Создаем и заполняем массивы
    T array1[rows1][2];
    T2 array2[rows2][2];

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < 2; ++j) {
            array1[i][j] = static_cast<T>(rand() % 100) / 10.0; // Пример заполнения случайными числами
        }
    }

    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < 2; ++j) {
            array2[i][j] = static_cast<T2>(rand() % 100) / 10.0; // Пример заполнения случайными числами
        }
    }

    // Выводим исходные массивы
    cout << "Оригинальный масив  1:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << setw(8) << fixed << setprecision(2) << array1[i][j] << " ";
        }
       cout << endl;
    }
   cout << endl;

   cout << "Оригинальный масив  2:" <<endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << setw(8) << fixed  << setprecision(2) << array2[i][j] << " ";
        }
        cout << endl;
    }
   cout << endl;
    
    // Меняем вторую и третью строки
    swapRows(array1, 1, 2);
    swapRows(array2, 1, 2);
    
    // Выводим результаты тестирования
    cout << "Модифицированный массив 1:" <<endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < 2; ++j) {
           cout << setw(8) << fixed  << setprecision(2) << array1[i][j] << " ";
        }
        cout << endl;
    }
    cout << std::endl;

    cout << "Модифицированный массив 2:" << std::endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << setw(8) << fixed << setprecision(2) << array2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    processArrays<double,double>();
    cout << "--------------------------------------" << endl;
    cout << "Второе задание первый int второй double" << endl;
    // Вызываем перегруженную функцию для int
    processArrays<int,double>();
    return 0;
}
