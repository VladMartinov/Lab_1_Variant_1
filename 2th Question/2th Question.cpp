#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>

using namespace std;


void initializeArray1D(double* Array1D, unsigned int Length)
{
    for (unsigned int i = 0; i < Length; ++i)
    {
        *(Array1D + i) = i * sin(M_PI * i / 25);
    }
}

double** makeArray2D(double* Array1D, unsigned int rows, unsigned int cols)
{
    double** Array2D = new double* [rows];
    for (unsigned int i = 0; i < rows; ++i)
    {
        *(Array2D + i) = new double[cols];
    }
    for (unsigned int i = 0; i < rows; ++i)
    {
        *(*(Array2D + i) + 0) = 0;

        for (unsigned int j = 1; j < cols; ++j)
        {
            *(*(Array2D + i) + j) = *(Array1D + i * cols + j);
            *(*(Array2D + i) + 0) += *(*(Array2D + i) + j);
        }
    }
    return Array2D;
}

void printArray1D(double Array1D[], unsigned Length) {
    cout<<"[ ";
    for (unsigned int i = 0; i < Length; ++i)
    {
        cout << *(Array1D + i) << "  ";
    }
    cout<<"]\n";
}

void printArray2D(double** Array2D, int rows, int cols, unsigned Length) {
    cout << "\n" << "=>\n\n";

    for (unsigned int i = 0; i < rows; ++i)
    {
        if (i != 0)
            cout << "\n";
        for (unsigned int j = 0; j < cols; ++j)
        {
            if (i == 0 && j == 0)
                cout<< "[" << setfill(' ') << setw(9) << *(*(Array2D + i) + j);
            else
                cout << setfill(' ') << setw(10) << *(*(Array2D + i) + j);
        }
    }
    cout << "  ]\n";
}

void freeArray1D(double* Array1D) {
    delete Array1D;
    Array1D = NULL;
}

void freeArray2D(double** Array2D) {
    for (size_t i = 0; i < 2; ++i)
    {
        delete[] Array2D[i];
    }
    delete[] Array2D;
}

int main()
{
    const unsigned int Length = 25;
    const unsigned int rows = 5;
    const unsigned int cols = 5;

    double* Array1D = new double[Length];
    initializeArray1D(Array1D, Length);

    printArray1D(Array1D, Length);

    double** Array2D = makeArray2D(Array1D, rows, cols);

    printArray2D(Array2D, rows, cols, Length);

    freeArray1D(Array1D);
    freeArray2D(Array2D);
    return 0;
}
