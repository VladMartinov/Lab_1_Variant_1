#include <iostream>

const char* SearchStartChar(const char* LineChar, int SearchChar)		//����� ����������� ������ ��������, � ������� ������� (������ ������������ � �����)
{
	int StartIndex = 0;								//������������� �������� int ������� ������
	const char* rest_of_string = NULL;				//���������� ������� �������� ������� ������ (�������)
	while (LineChar[StartIndex] != '\0')			//���� ����������� ���������� ���� �� ������ �� ����� ������
	{
		if (LineChar[StartIndex] == SearchChar) {
			rest_of_string = LineChar + StartIndex;			//����� ������� ��������� � ���� ������� ����������, �� � ������ ������������ ������ ������� � ����� �������
			break;											//��������������� ����� �� ����� � ������ ������
		}
		StartIndex++;										//���������� ������� �� 1
	}
	return rest_of_string;									//������� ����������� ������
}

int main() {
	char Line[] = "Hi! Join our group - 'www.some_link.com'";		//������ �������� � ������� ����� ������
	const char ToSearchChar = '.';									//������� �������
	
	const char* StandardMethod = strchr(Line, ToSearchChar);		//����������� ����� ���������� � ���������� �++ . ������ ��� ����������
	
	const char* MyMethod = SearchStartChar(Line, ToSearchChar);		//��� ����� ��������� ���� . ������ ������ ����������

	printf("Initial string: %s\nStandard: %s\nMy version: %s\n",	//����� ����������� �� ������� %s - ������ ��������
		Line, StandardMethod, MyMethod);
	return 0;														//����� ���������
}