#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Структура для хранения информации о человеке
template<typename T>
struct Person {
    T surname;
    T name;
    int age;
};

// Функция для подсчета количества людей с именем "Elena"
template<typename T>
 vector<int> countElenas(const vector<Person<T>>& people) {
    vector<int> index;
    for (int i=0;i < people.size();i++)
    {
        if (people[i].name == "Elena") {
           index.push_back(i);
        }
    }
    
    return index;
}

int main() {
    setlocale(LC_ALL, ".866");
    
    // Создание и запись данных в файл
    ofstream outputFile("people.txt");
    outputFile << "Smith John 25\n";
    outputFile << "Doe Elena 30\n";
    outputFile << "Johnson Elena 22\n";
    outputFile << "Brown Robert 28\n";
    outputFile << "Diego Elena 20\n";
    outputFile.close();

    // Чтение данных из файла
    ifstream inputFile("people.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    // Хранение данных о людях в векторе
    vector<Person<string>> people;
    Person<string> person;

   while (inputFile >> person.surname >> person.name >> person.age) {
        people.push_back(person);
    }

    vector<int> index = countElenas(people);

    if (index.size()!=0){
        for (int i=0;i < index.size();i++){
            cout<< people[index[i]].name<<  "   " << people[index[i]].surname<<  "   " << people[index[i]].age << endl;
        }
    }
    
    return 0;
}
