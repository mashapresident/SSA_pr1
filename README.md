# Practice #1

# 8 варіант

**ТЕКСТ ЗАВДАННЯ**
*Напишіть програму на ANSI C для заповнення масиву випадковими числами з плаваючою точкою. Реалізуйте функцію для пошуку всіх індексів заданого числа у масиві.*


Програма працюватиме на будь-якій ОС, за умови наявності [GCC compiler](https://https://gcc.gnu.org/).

Усі використані бібліотеки є вбудованими.

Автор працював на [FreeBSD](https://https://hyperhost.ua/info/uk/freebsd-u-detalyax-pro-plyusi-ta-minusi-sistemi). [Віртуальна машина](https://https://www.freebsd.org/) встановлена на [Oracle VirtualBox](https://https://www.virtualbox.org/).


Почнемо з підключення бібліотек та оголошення функцій

```
#include stdio.h
#include stdlib.h
#include time.h
#include math.hint choose_array_type();
float* create_1d_array(int size);
float** create_2d_array(int rows, int cols);
void fill_random_values_1d(float* array, int size);
void fill_random_values_2d(float** array, int rows, int cols);
void show_array_1d(float* array, int size);
void show_array_2d(float** array, int rows, int cols);
void find_indexes_1d(float* array, int size);
void find_indexes_2d(float** array, int rows, int cols);
```

У самій програмі ми дізнаємось про потреби користувача : тип та розмір масиву. Відповідно до потреб використовуємо функції для створення, заповнення масиву та знаходження цільового значення.

```

int main() {
    int type = choose_array_type();
    if (type == 0) {
        printf("Invalid choice.\n");
        return 1;
    }
    else if (type == 1) {
        int size;
        printf("Enter the size of the 1D array: ");
        scanf("%d", &size);
        float* arr = create_1d_array(size);
        fill_random_values_1d(arr, size);
        show_array_1d(arr, size);
        find_indexes_1d(arr, size);
        free(arr);
    } else {
        int rows, cols;
        printf("Enter the number of rows and columns for the 2D array: ");
        scanf("%d %d", &rows, &cols);
  
        float** arr = create_2d_array(rows, cols);
        fill_random_values_2d(arr, rows, cols);
        show_array_2d(arr, rows, cols);
        find_indexes_2d(arr, rows, cols);
  
        for (int i = 0; i < rows; i++) {
            free(arr[i]);
        }
        free(arr);
    }
    return 0;
}
```

У ході виконання практичної роботи використовувались наступні ресурси

* [Згадуємо С та основні бібліотеки](https://[https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm)
* [Робота з freeBSD](https://https://acode.com.ua/search-files-linux/#toc-14)
* [Робота з Readme
