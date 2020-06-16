// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define PROMPT ':'
#pragma warning(disable : 4996)

int Lab1()
{
	float a, b, rez;
	char oper;
	int repeat = 1;
	while (repeat == 1)
	{
		putchar(PROMPT);
		scanf("%f%c%f", &a, &oper, &b);
		switch (oper)
		{
		case '+': rez = a + b; break;
		case '-': rez = a - b; break;
		case '*': rez = a * b; break;
		case '/': rez = a / b; break;
		default:
			cout << ("Ошибка!\n");
			exit(1);
		}
		cout << ("Результат:%f\n", rez);
		cout << ("Продолжить?(1-да, 0-нет)\n");
		cin >> repeat;
	}
}

void Lab2()
{
	int x, n, b, i, zn, j;
	float y = 0, z = 0;
	int repeat = 1;
	while (repeat == 1)
	{
		cout << ("Введите x\n");
		cin >> x;
		cout << ("Введите n\n");
		cin >> n;
		cout << ("Введите b\n");
		cin >> b;
		for (j = 0; j <= n; j++)
		{
			float fact = 1;
			zn = 2 * j + 1;
			for (i = 1; i <= zn; i++)
			{
				fact *= i;
			}
			y += (pow(-1, j) * pow(x, 2 * j)) / fact;
		}
		z = sin(x) / x + b;
		cout << "y(x) = " << y << endl;
		cout << "z(x) = " << z << endl;
		cout << ("Продолжить?(1-да, 0-нет)\n");
		cin >> repeat;
	}
}

void Lab3()
{
	int n;
	int repeat = 1;
	while (repeat == 1)
	{
		int min = 9999;
		int sum = 0;
		bool check = false;
		cout << ("Введите размер массива\n");
		cin >> n;
		int *arr = new int[n];
		cout << ("Введите элементы массива\n");
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++)
		{
			if (abs(arr[i]) < min)
			{
				min = arr[i];
			}
			if (check == true)
			{
				sum += abs(arr[i]);
			}
			if (arr[i] == 0)
			{
				check = true;
			}
			cout << arr[i] << "\t";
		}
		cout << endl << ("Минимальный по модулю элемент = ") << min << endl;
		cout << ("Сумма модулей элементов после 0 = ") << sum << endl;
		delete[] arr;
		cout << ("Продолжить?(1-да, 0-нет)\n");
		cin >> repeat;
	}
}

struct Car
{
	string Model;
	string Maker;
	int Year;
	int EPower;
};



void AddCar(Car *&Cars, int &size ,Car add)
{
	bool rep = false;
	for (int i = 0; i < size; i++)
	{
		if (Cars[i].Model == add.Model)
		{
			rep = true;
			cout << "Такая модель уже существует\n";
		}
	}
	if (rep == false)
	{
		Car* newArr = new Car[size + 1];
		for (int i = 0; i < size; i++)
		{
			newArr[i] = Cars[i];
		}
		newArr[size] = add;
		size++;
		delete[] Cars;
		Cars = newArr;
	}
}

void DeleteByModel(Car *&Cars, int &size, string model)
{
	int d = -1;
	for (int i = 0; i < size; i++)
	{
		if (Cars[i].Model == model)
		{
			d = i;
		}
	}
	if (d >= 0)
	{
		Car* newArr = new Car[size - 1];
		for (int i = 0, j =0; i < size; i++, j++)
		{
			if (Cars[i].Model != model)
			{
				newArr[j] = Cars[i];
			}
			else
			{
				j--;
			}
		}
		size--;
		delete[] Cars;
		Cars = newArr;
	}
	else
	{
		cout << "Такая модель не существует\n";
	}
}

void GetCars(Car *&Cars, int &size)
{
	cout << "Модель\t Производитель\t Год выпуска\t Мощность\n";
	for (int i = 0; i < size; i++)
	{
		cout << Cars[i].Model << "\t" << Cars[i].Maker << "\t" << Cars[i].Year << "\t" << Cars[i].EPower << endl;
	}
}

void EditCar(Car *&Cars, int &size, string model)
{
	int d = -1;
	for (int i = 0; i < size; i++)
	{
		if (Cars[i].Model == model)
		{
			d = i;
		}
	}
	if (d >= 0)
	{
		bool check = false;
		string maker, newmodel;
		int year, epower;
		cout << "Модель\t";
		cin >> newmodel;
		for (int i = 0; i < size; i++)
		{
			if (Cars[i].Model == newmodel)
			{
				check = true;
				cout << "Такая модель уже существует\n";
			}
		}
		if (check == false)
		{
			cout << "Производитель\t";
			cin >> maker;
			cout << "Год производства\t";
			cin >> year;
			cout << "Мощность\t";
			cin >> epower;
			Cars[d].Model = newmodel;
			Cars[d].Maker = maker;
			Cars[d].EPower = epower;
			Cars[d].Year = year;
		}
	}
	else
	{
		cout << "Такая модель не существует\n";
	}
}

void GetCarsWithFilter(Car *&Cars, int &size, string maker)
{
	cout << "Модель\t Производитель\t Год выпуска\t Мощность\n";
	for (int i = 0; i < size; i++)
	{
		if (Cars[i].Maker == maker)
		{
			cout << Cars[i].Model << "\t" << Cars[i].Maker << "\t" << Cars[i].Year << "\t" << Cars[i].EPower;
		}
	}
}

void Lab4()
{
	string model, maker;
	int year, epower, act = 9, count, size = 0;
	Car* Cars = new Car[size];
	while (act != 0)
	{
		cout << ("Выберете действие(1-добавить, 2-удалить, 3-просмотр всех, 4-изменение, 5-поиск, 0-выход)\n");
		cin >> act;
		switch (act)
		{
		case 1:
		{
			cout << "Модель\t";
			cin >> model;
			cout << "Производитель\t";
			cin >> maker;
			cout << "Год производства\t";
			cin >> year;
			cout << "Мощность\t";
			cin >> epower;
			Car add;
			add.Model = model;
			add.Maker = maker;
			add.EPower = epower;
			add.Year = year;
			AddCar(Cars, size, add);
		} 
		break;
		case 2:
		{
			cout << "Введите название модели для удаления\n";
			cin >> model;
			DeleteByModel(Cars, size, model);
		}
		break;
		case 3: GetCars(Cars, size); break;
		case 4:
		{
			cout << "Введите название модели для редактирования\n";
			cin >> model;
			EditCar(Cars, size, model);
		}
		break;
		case 5:
		{
			cout << "Введите название производителя\n";
			cin >> maker;
			GetCarsWithFilter(Cars, size, maker);
		}
		break;
		}
	}
	delete[] Cars;
}

void main()
{
	int lab = 9;
	setlocale(LC_ALL, "Russian");
	while (lab != 0)
	{
		cout << ("Введите номер лабораторной (0-выход)\n");
		cin >> lab;
		switch (lab)
		{
		case 1: Lab1(); break;
		case 2: Lab2(); break;
		case 3: Lab3(); break;
		case 4: Lab4(); break;
		default:
			break;
		}
	}
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
