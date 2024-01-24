#include <iostream>
#include <string>
using namespace std;

struct Film {
    string title;
    double cost;
    string director;
};

int main() {

    setlocale(LC_ALL, "Russian");
    const int librarySize = 5; // Задайте необходимый размер библиотеки

    Film videoLibrary[librarySize];

    // Ввод информации о видеотеке
    for (int i = 0; i < librarySize; ++i) {
        cout << "Введите информацию о фильме " << i + 1 << ":" << endl;
        cout << "Название: ";
        getline(cin, videoLibrary[i].title);
        cout << "Стоимость: ";
        cin >> videoLibrary[i].cost;
        cin.ignore(); // Очистка буфера после ввода числа
        cout << "Режиссер: ";
        getline(cin, videoLibrary[i].director);
        cout << endl;
    }

    // Поиск фильмов с максимальной и минимальной стоимостью
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < librarySize; ++i) {
        if (videoLibrary[i].cost > videoLibrary[maxIndex].cost) {
            maxIndex = i;
        }
        if (videoLibrary[i].cost < videoLibrary[minIndex].cost) {
            minIndex = i;
        }
    }

    // Вывод информации о фильмах между максимальной и минимальной стоимостью
    cout << "Фильмы между фильмами с максимальной и минимальной стоимостью:" << endl;
    for (int i =0; i < librarySize; ++i) {
        if (maxIndex!=i&&minIndex!=i){
            cout << "Название: " << videoLibrary[i].title << ", Стоимость: " << videoLibrary[i].cost
                << ", Режиссер: " << videoLibrary[i].director << endl;
        }
    }
    return 0;
}
