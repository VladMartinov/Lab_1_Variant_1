#include <iostream>
#include <stdio.h>
#include <clocale>
using namespace std;

int processArray(int Array[], unsigned Length, int ArrayResult[], int a, int b ) {
	for (unsigned i = 0; i < Length; i++) {
		Array[i] *= (int)(rand() % (-a+b)) + a;
	}

	unsigned int count = 0;

	for (unsigned i = 0, j = 0; i < Length || i < count - 1; i++) {
		if (Array[i] < 0) {
			ArrayResult[j] = Array[i];
			count++;
			j++;
		}
	}

	return count;
}

void printArray(int Array[], unsigned Length, int a, int b) {
	printf("\nВход:\t\t[ ");
	for (unsigned int i = 0; i < Length; ++i)
	{
		printf("%i ", Array[i]);
	}
	printf("]\t\ta: %i  b: %i\n", a, b);
}

void printArrayDouble(int ArrayResult[], unsigned result) {
	printf("Выход:\t\t[ ");
	for (unsigned int i = 0; i < result; ++i)
	{
		printf("%i ", ArrayResult[i]);
	}
	printf("]\t\tcount: %i\n", result);
}

int main() {
	setlocale(LC_ALL, "Russian");
	const unsigned int Length = 15;
	int a, b;
	
	int Array[Length]{};
	for (unsigned int i = 0; i < Length; i++) Array[i] = 1;

	int ArrayResult[Length]{ 0 };

	scanf_s("%i", &a);
	if (a >= 0) {
		printf("The number \"a\" must be less than 0!");
		exit(0);
	}
	scanf_s("%i", &b);

	srand(0);

	unsigned int result = processArray(Array, Length, ArrayResult, a, b);

	printArray(Array, Length, a, b);
	printArrayDouble(ArrayResult, result);
}

