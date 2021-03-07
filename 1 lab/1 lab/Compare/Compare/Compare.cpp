// Compare.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	const int numberOfArguments = 3;
	const string errorCountArguments = "Invalid arguments count";
	const string useCorrectArguments = "Usage: compare.exe <file name 1><file name 2>";
	const string failOpen = "Failed to open ";
	const string readError = " for reading";

	if (argc != numberOfArguments) //защита на неопределенное количество аргументов
	{
		cout << errorCountArguments << endl;
		cout << useCorrectArguments << endl;
		return 1;
	}

	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	if (!file1.is_open()) 
	{
		cout << failOpen << argv[1] << readError;
		return 1;
	}

	if (!file2.is_open())
	{
		cout << failOpen << argv[2] << readError;
		return 1;
	}


	if (file1 && file2)
	{
		int x = 0;   //счетчик
		char ch1, ch2;
		bool isSame = true;
		while (file1.get(ch1) && file2.get(ch2))
		{

			if (ch1 == '\n')
			{
				x++;
			}

			if (ch1 != ch2)
			{
				isSame = false;
				cout << "Files are different. Line number is " << ++x << endl;
				return 1;
			}
		}
		if (isSame) //если выполнено условие, то
		{
			cout << "Files are equal \n" << endl;
			return 0;
		}

	}
	file1.close(); //закрытие
	file2.close();
	return 0;

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
