#include <iostream>

const char* SearchStartChar(const char* LineChar, int SearchChar)		//Метод принимающий строку симводов, и искомый элемент (символ преобразован в число)
{
	int StartIndex = 0;								//инициализация элемента int индекса начала
	const char* rest_of_string = NULL;				//присвоение массиву символов нулевой ссылки (пустоты)
	while (LineChar[StartIndex] != '\0')			//Цикл выполняющий повторения пока не дойдет до конца страки
	{
		if (LineChar[StartIndex] == SearchChar) {
			rest_of_string = LineChar + StartIndex;			//Поиск нужного эелемента и если найдено совподение, то в массив записывается строка начиная с этого символа
			break;											//Преждевременный выход из цикла в случае успеха
		}
		StartIndex++;										//Увеличение индекса на 1
	}
	return rest_of_string;									//Возврат результатов поиска
}

int main() {
	char Line[] = "Hi! Join our group - 'www.some_link.com'";		//Строка символов в которой будем искать
	const char ToSearchChar = '.';									//Искомый элемент
	
	const char* StandardMethod = strchr(Line, ToSearchChar);		//Стандартный метод встроенный в библиотеку С++ . Запись его результата
	
	const char* MyMethod = SearchStartChar(Line, ToSearchChar);		//Наш метод описанный выше . Запись нашего результата

	printf("Initial string: %s\nStandard: %s\nMy version: %s\n",	//Вывод результатов на консоль %s - строка символов
		Line, StandardMethod, MyMethod);
	return 0;														//Конец программы
}