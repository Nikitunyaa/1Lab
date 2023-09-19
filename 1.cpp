#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

// Функция для вычисления суммы элементов массива
float calculateSum(const std::vector<float>& arr) {
    float sum = 0;
    for (float num : arr) {
        sum += num;
    }
    return sum;
}

// Функция для вычисления среднего арифметического элементов массива
float calculateAverage(const std::vector<float>& arr) {
    if (arr.empty()) {
        return 0.0;
    }

    float sum = calculateSum(arr);
    return static_cast<float>(sum) / arr.size();
}

// Функция для вывода результатов всех операций
void printResults(const std::vector<float>& arr) {

    //std::cout << "Результаты всех операций: ";
    for (float num : arr) {
        std::cout << std::fixed<<std::setprecision(3) << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    //std::cout << "Введите размерность исходного массива: ";
    std::cin >> n;

    std::vector<float> original_array(n);

    //std::cout << "Введите элементы массива через пробел: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> original_array[i];
    }

std::cout << original_array.size() << std::endl;

   // std::cout << "Исходный массив: ";
    for (float num : original_array) {
        std::cout <<std::fixed<<std::setprecision(3)<< num << " ";
    }
    std::cout << std::endl;

    // Добавление суммы и среднего арифметического в конец массива
    float sum_of_elements = calculateSum(original_array);
    double average_of_elements = calculateAverage(original_array);

    original_array.push_back(sum_of_elements);
    original_array.push_back(static_cast<float>(average_of_elements));

    // Вывод массива после добавления элементов
    //std::cout << "Массив после добавления суммы и среднего арифметического: ";
    for (float num : original_array) {
        std::cout <<std::fixed<<std::setprecision(3)<< num << " ";
    }
    std::cout << std::endl;

    // Выполнение дополнительного действия (вычитание из каждого числа наибольшего числа)
    float max_element = *std::max_element(original_array.begin(), original_array.end());

    for (float &num : original_array) {
        num -= max_element;
    }

    // Вывод массива после выполнения дополнительного действия
    //std::cout << "Массив после вычитания наибольшего элемента: ";
    for (float num : original_array) {
        std::cout <<std::fixed<<std::setprecision(3)<< num << " ";
    }
    std::cout << std::endl;

    // Меню для добавления или удаления элементов
    while (true) {
        int choice;
        //std::cout << "Выберите действие (1 - добавить элемент, 2 - удалить последний элемент, 0 - выход): ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            float element_to_add;
            //std::cout << "Введите элемент для добавления: ";
            std::cin >> element_to_add;
            original_array.push_back(element_to_add);
        } else if (choice == 2) {
            if (!original_array.empty()) {
                original_array.pop_back();
            } else {
                std::cout << "Массив пуст. Невозможно удалить элемент." << std::endl;
            }
        }
       
       if  (choice == 1) {
         std::cout << "+: " << original_array.size() << std::endl;  
       }
        if  (choice == 2) {
         std::cout << "-: " << original_array.size() << std::endl;  
       }

// Вывод результатов после действия
        printResults(original_array);
        
        // Добавление суммы и среднего арифметического после операции
        sum_of_elements = calculateSum(original_array);
        average_of_elements = calculateAverage(original_array);

        original_array.push_back(sum_of_elements);
        original_array.push_back(static_cast<float>(average_of_elements));

        // Вывод результатов после действия
        printResults(original_array);
        
        // Выполнение дополнительного действия (вычитание из каждого числа наибольшего числа)
    max_element = *std::max_element(original_array.begin(), original_array.end());

    for (float &num : original_array) {
        num -= max_element;
    }
    // Вывод результатов после действия
        printResults(original_array);
    }

    return 0;
}
