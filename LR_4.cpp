#include "bankDeposit.h"

#include <list>
#include <vector>
#include <fstream> // функция clear
#include <algorithm> // функция sort

 void CustomOutput(const Bank_deposit & bank_dep) {
    std::ofstream output("output.txt", std::ios::app);  // Открытие файла для записи

    output << bank_dep << std::endl;    // Запись объекта в файл
    std::cout << bank_dep << std::endl; // Вывод объекта на консоль

    output.close();  // Закрытие файла
}

 void CustomOutput(std::string& bank_dep) {
     std::ofstream output("output.txt", std::ios::app);  // Открытие файла для записи

     output << bank_dep << std::endl;    // Запись объекта в файл
     std::cout << bank_dep << std::endl; // Вывод объекта на консоль

     output.close(); // Закрытие файла
 }

 void CustomOutput(double& bank_dep) {
     std::ofstream output("output.txt", std::ios::app);   // Открытие файла для записи

     output << bank_dep << std::endl;    // Запись объекта в файл
     std::cout << bank_dep << std::endl; // Вывод объекта на консоль

     output.close(); // Закрытие файла
 }

int main()
{
    std::ofstream clear("output.txt"); // Очистка файла вывода
    clear.close(); // Закрытие файла

    std::ifstream input("input.txt"); // Открытие файла для чтения

    std::list<Bank_deposit> BANK; // вектор объектов класса Bank_deposit

    for (size_t i = 0; i < 5; ++i) {
        Bank_deposit bank_dep;             // Создание временного объекта Bank_deposit
        input >> bank_dep;            // Чтение данных из файла и инициализация объекта
        BANK.push_back(bank_dep);    // Добавление объекта в конец вектора
    }
    
    // если не использовать переменную строкового типа, то по умолчанию будет char,
    // то по умолчанию будет char, для которого нет перегрузки функции CustomOutput
     
    std::string a = "   before SORT: ";
    CustomOutput(a);

    for (const auto& _EL : BANK) CustomOutput(_EL);
   
    a = "   after SORT: ";
    CustomOutput(a);

    BANK.sort();

    // Вывод отсортированных элементов
    for (auto _EL : BANK)
        CustomOutput(_EL);

    a = "   Vector copied from List: ";
    CustomOutput(a);

    // Создание двусвязного списка объектов Bank_deposit
    std::vector<Bank_deposit> _RES;

    // Копирование элементов из списка в вектор
    std::copy(
        BANK.begin(), BANK.end(),
        std::back_inserter(_RES));

    // Вывод каждого элемента из скопированного списка
    for (const auto& _EL : _RES)
        CustomOutput(_EL);
	return 0;
}

