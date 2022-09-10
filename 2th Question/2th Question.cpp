#define _USE_MATH_DEFINES       //Нужно для использование чилса PI (без его самостоятельной инициализации)
#include <iostream>             //Для вывода информации на консоль
#include <iomanip>              //Для редактирование выводимого поля

using namespace std;


void initializeArray1D(double* Array1D, unsigned int LENGTH)        //Метод принимающий одномерный массив и его длинну
{
    for (unsigned int i = 0; i < LENGTH; ++i)
    {
        *(Array1D + i) = i * sin(M_PI * i / 25);                    //Заполнение каждого элемента одномерного массива с помощью цикла (Значение записываемое в массив взято из варинта задния)
    }
}

double** makeArray2D(double* Array1D, unsigned int ROWS, unsigned int COLS)         //Метод принимающий одномерный массив, кол-во строк и столбцов (для инициализации двухмерного массива)
{
    double** Array2D = new double* [ROWS];          // Выделение памяти для двух мерногомассива 
    for (unsigned int i = 0; i < ROWS; ++i)
    {
        *(Array2D + i) = new double[COLS];          // Выделение памяти для каждой строки двухмерного массива
    }

    for (unsigned int i = 0; i < ROWS; ++i)         // Пробегаемся по строками массива 2Д
    {
        *(*(Array2D + i) + 0) = 0;                  // Первый элемент массива заполняется 0

        for (unsigned int j = 1; j < COLS; ++j)     // Пробегаемя по столбцам массива 2Д
        {
            *(*(Array2D + i) + j) = *(Array1D + i * COLS + j);          //заполням элементы массива 2Д  
            *(*(Array2D + i) + 0) += *(*(Array2D + i) + j);             //прибавляем заполненный элемент к первому элементу массива (по заданию)
        }
    }
    return Array2D;                                 //Возврат двухмерного массива
}

void printArray1D(double Array1D[], unsigned LENGTH) {                  //Метод принимающий одномерный массив и его длинну для вывода его на консоль
    cout<<"[ ";
    for (unsigned int i = 0; i < LENGTH; ++i)                           
    {
        cout << *(Array1D + i) << "  ";                                 //Вывод каждого элемента массива
    }
    cout<<"]\n";                                                        //Переход на следующую строку
}

void printArray2D(double** Array2D, int ROWS, int COLS) {               //Метод принимающий двухмерный массив, его кол-во строк и длинну
    cout << "\n" << "=>\n";                                             //Разделение одномерого и двухмерного массива в консоли

    for (unsigned int i = 0; i < ROWS; ++i)                             //Пробегаемя по строкам
    {
        cout << "\n";                                                   //Переход на следующую строку
        for (unsigned int j = 0; j < COLS; ++j)
        {
            if (i == 0 && j == 0)
                cout<< "[" << setfill(' ') << setw(9) << *(*(Array2D + i) + j); //Вывод первого эоемента первой строки (из-за квадратной скобки)
            else
                cout << setfill(' ') << setw(10) << *(*(Array2D + i) + j);      //Вывод всех эл-ов массива
        }
    }
    cout << "  ]\n";                                                    //Завершающая скобка
}

void freeArray1D(double* Array1D) {             //Метод принимает одномерный массив для его удаления из памяти
    delete Array1D;                             //Удаление из памяти массива
    Array1D = NULL;                             //Присвоение нулевой ссылки (то есть ничего)
}

void freeArray2D(double** Array2D, int ROWS) {              //Метод принимающий двухмерный массив для его удаления из памяти
    for (int i = 0; i < ROWS; ++i)
    {
        delete[] *(Array2D + i);                            //Удаление каждой строки двухмерного массива
    } 
    delete[] Array2D;                                       //Удаление массива 
}

int main()
{
    const unsigned int Length = 25;         //Инициализация длинны одномерного массива
    const unsigned int ROWS = 5;            //Инициализация кол-ва строк
    const unsigned int COLS = 5;            //Инициализация кол-ва столбцов

    double* Array1D = new double[Length];   //Выделение памяти под одномерный массив
    initializeArray1D(Array1D, Length);     //Вызов метода для его заполнения

    printArray1D(Array1D, Length);          //Вывод одномерного массива на консоль

    double** Array2D = makeArray2D(Array1D, ROWS, COLS);    //Вызов метода возвращающего двухмерный массив

    printArray2D(Array2D, ROWS, COLS);      //Вывод двухмерного массива на консоль

    freeArray1D(Array1D);                   //Удаление из памяти одномерного массива
    freeArray2D(Array2D, ROWS);             //Удаление из памяти двухмерного массива
    return 0;                               //Конец
}
