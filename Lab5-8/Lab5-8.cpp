// Lab5-8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
#pragma warning(disable : 4996)
int raz;
#define MAXDL 9
#include <conio.h>
#include <cstdio>
#include "Lab5-8.h"

#pragma region Lab5

void First(int *&r, int &c)
{
	int min = r[0];
	int index = 0;
	for (int i = 0; i < c; i++)
	{
		if (r[i] < min)
		{
			min = r[i];
			index = i;
		}
	}
	r[index] = 0;
	for (int i = 0; i < c; i++)
	{
		cout << r[i] << "\t";
	}
}

void Second(int *&r, int &c)
{
	int sum = 0;
	for (int i = 0; i < c; i++)
	{
		if (r[i] > 0)
		{
			sum += r[i];
		}
		cout << r[i] << "\t";
	}
	cout << "Сумма положительныx элементов : " << sum;
}

void Inter(int **&m, int &c, int &r, int &n)
{
	for (int i = 0; i < r; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			if (n == 1)
			{
				First(m[i], c);
			}
			if (n == 2)
			{
				Second(m[i], c);
			}
		}
		else
		{
			for (int j = 0; j < c; j++)
			{
				cout << m[i][j] << "\t";
			}
		}
		cout << endl;
	}
}

void Lab5()
{
	int r1, c1, r2, c2, el, n;

	cout << "Введите количество строк 1 массива" << endl;
	cin >> r1;

	cout << "Введите количество столбцов 1 массива" << endl;
	cin >> c1;
	int **m1 = new int*[r1];

	for (int i = 0; i < r1; i++)
	{
		m1[i] = new int[c1];
	}

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			cin >> el;
			cout << " ";
			m1[i][j] = el;
		}
		cout << endl;
	}

	cout << "Введите количество строк 2 массива" << endl;
	cin >> r2;

	cout << "Введите количество столбцов 2 массива" << endl;
	cin >> c2;
	int** m2 = new int* [r2];

	for (int i = 0; i < r2; i++)
	{
		m2[i] = new int[c2];
	}

	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			cin >> el;
			cout << " ";
			m2[i][j] = el;
		}
		cout << endl;
	}

	cout << "Первый массив" << endl;
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			cout << m1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Второй массив" << endl;
	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			cout << m2[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------------------";
	n = 1;
	Inter(m1, c1, r1, n);
	cout << "-------------------";
	n = 2;
	Inter(m2, c2, r2, n);




	for (int i = 0; i < r1; i++)
	{
		delete[] m1[i];
	}
	delete[] m1;
	for (int i = 0; i < r2; i++)
	{
		delete[] m2[i];
	}
	delete[] m2;
}
#pragma endregion

#pragma region Lab6
double PnRec(double x, double n)
{
	raz++;
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}
	double res = ((2 * n - 1) * PnRec(x, n - 1) - (n - 1) * PnRec(x, n - 2)) / n;

	return res;
}



double PnIter(double x, double n)
{
	double pol; //полином
	double pol1;//предыдущий полином
	double poln;//вычисляемый полином
	double i = 0;
	for (i; i <= n; i++)
	{
		if (i != 0)
		{
			if (i != 1)
			{
				poln = ((((2 * i - 1) * pol) - ((i - 1) * pol1)) / i);
				pol1 = pol;
				pol = poln;
			}
			else
			{
				pol = x;
				pol1 = 1;
			}
		}
		else
		{
			pol = 1;
			pol1 = 0;
		}
	}
	cout << "Результат: " << pol;
	cout << "Количество итераций: " << i;
	return pol;
}

void Lab6()
{
	double x, n, resR;
	cout << "Введите x";
	cin >> x;
	cout << "Введите n";
	cin >> n;
	clock_t t1 = clock();
	raz = 0;
	resR = PnRec(x, n);
	cout << "Результат: " << resR;
	cout << "Глубина рекурсии: " << raz;
	clock_t t2 = clock();
	cout << "Время выполнения рекурсивным методом: " << (t2 - t1) << endl;
	raz = 0;
	clock_t t3 = clock();
	resR = PnIter(x, n);
	clock_t t4 = clock();
	cout << "Время выполнения итерационным методом: " << (t4 - t3) << endl;
}
#pragma endregion

#pragma region Lab7

void Lab7()
{
	string line;
	int rowsc = 0;
	ifstream in(".\\lab7.txt"); //Lab5-8\lab7.txt
	int i = 0;
	string *ArrString;
	char mr = 'a', nr = 'a';
	int max = 0;
	int now = 1;
	if (in.is_open())
	{
		getline(in, line);
		{
			rowsc = stoi(line);
			cout << "Количество строк: " << rowsc << endl;
			ArrString = new string[rowsc];
		}
		while (getline(in, line))
		{
			ArrString[i] = line;
			cout << line << endl;
			for (int j = 0; j < static_cast<int>(line.length()); j++)
			{
				if (nr == line[j])
				{
					now++;
				}
				else
				{
					now = 1;
				}
				if (now > max)
				{
					mr = nr;
					max = now;
				}
				nr = line[j];
			}
			i++;
		}
	}
	in.close();
	cout << "Символ: " << mr << " повторяется " << max << " раз" << endl;
}
#pragma endregion

#pragma region Lab8

struct EL_SP /* тип элемента списка */
{
	char id[MAXDL]; /* идентификатор */
	struct EL_SP* sled;/* ссылка на следующий элемент */
};
/*----------------------------------------------*/
/*функция включения очередного идентиф. в список*/
/*----------------------------------------------*/
void Vkl(struct EL_SP **p, char t_id[])
/* Вх. данные: *p - указатель списка
идентификаторов в лексикографическом порядке,
t_id - включаемый в список (текущий) ид-р */
/* Вых. данные: *p */
{
	struct EL_SP *pt, *k, *j;
	/* указатели очередного и предыдущего
	элементов списка */
	/* выделение памяти для нового эл-та списка */
	pt = (struct EL_SP*)malloc(sizeof(struct EL_SP));
	strcpy(pt->id, t_id);
	if (*p == NULL || strcmp(pt->id, (*p)->id) < 0)
	{ /* включение ид-ра в начало списка */
		pt->sled = *p; *p = pt;
	}
	else
	{ /* поиск элемента списка, после которого
	нужно включить идентификатор */
		k = *p;
		j = k;
		while (k != NULL && strcmp(pt->id, k->id) >= 0)
		{
			j = k; k = k->sled;
		}
		/* включение эл-та *pt после элемента *j */
		j -> sled = pt; pt -> sled = k;
	}
}
/*-------------------------------------------------*/
/* функция печати списка */
/*-------------------------------------------------*/
void PechSp(struct EL_SP *p)
	/* Вх. данные: p - указатель начала списка */
{
	struct EL_SP* i;
	/* указатель текущего элемента списка */
	printf("\nРезультат:\n");
	for (i = p; i != NULL; i = i->sled)
		puts(i->id);
}
EL_SP* DelId(struct EL_SP **p, string zi)
{
	//1 Удалить из списка л) все идентификаторы, совпадающие с заданным;
	EL_SP* prev = *p;
	EL_SP* head = *p;
	while (head)
	{
		EL_SP* sled = head->sled;
		if (head->id == zi)
		{
			if (prev == head)//если элемент первый
			{
				*p = head->sled;
				prev = head->sled;
			}
			else if ((prev))//если элемент не первый
			{
				prev->sled = sled;
			}
			delete head;
		}
		else
		{
			prev = head;
		}
		head = sled;
	}
	head = *p;
	return head;
}

void Change(struct EL_SP* p, char zi[])
{
	EL_SP* head = p;
	if (head->sled != NULL)
	{
		while (head->sled->sled != NULL)
		{
			head = head->sled;
		}
		strncpy(head->id, zi, MAXDL);
	}
	else
	{
		cout << "Недостаточно элементов" << endl;
	}
}
void CountAft(struct EL_SP** p, string zi)
{
	EL_SP* head = *p;
	int f = 0;
	int c = 0;
	while (head)
	{
		if (f == 1)
		{
			c++;
		}
		if (head->id == zi)
		{
			f = 1;
		}
		head = head->sled;
	}
	cout << "Количество элементов после заданного идентификатора: " << c << endl;
}

void ToA(struct EL_SP** p, int n)
{
	EL_SP* head = *p;
	int i = 0;
	string* A = new string[n];
	while (head)
	{
		A[i] = head->id;
		head = head->sled;
		i++;
	}
	cout << "Массив А: ";
	for (int j = 0; j < i; j++)
	{
		cout << A[j] << "\t";
	}
	cout << endl;
}
	/*--------------------------------------------------*/
	/* О С Н О В Н А Я П Р О Г Р А М М А */
	/*--------------------------------------------------*/
void Lab8()
{
	struct EL_SP *p;
	/* указатель начала списка */
	unsigned n; /* количество идентификаторов */
	unsigned i; /* параметр цикла */
	char t_id[MAXDL]; /* текущий идентификатор */
	printf("\nВведите число идентификаторов\n n=");
	scanf("%u", &n);
	getchar(); /* пропуск символа "перевод строки" */
	p = NULL; /* список пока пуст */
	printf("Введите идентификаторы ");
	printf("после каждого нажимайте клавишу <Enter>\n");
	for (i = 1; i <= n; i++)
	{
		gets_s(t_id);
		Vkl(&p, t_id); /* включение ид-ра в список */
	}
	PechSp(p); /* печать списка */
	int d = 9;
	while (d != 0)
	{
		cout << "Введите заданный идентификатор" << endl;
		string zi;
		cin >> zi;
		char* cstr = new char[zi.length() + 1];
		strcpy(cstr, zi.c_str());
		cout << ("Введите номер действия 1-удаление, 2-изменение, 3-количество после, 4-запись в массив A (0-выход)\n");
		cin >> d;
		switch (d)
		{
		case 1:
			p = DelId(&p, zi); 
			PechSp(p); break;
		case 2:
			Change(p, cstr);
			PechSp(p);
			break;
		case 3: 
			CountAft(&p, zi);
			break;
		case 4:
			ToA(&p, n);
			break;
		default:
			break;
		}
	}
}

#pragma endregion

int main()
{
	int lab = 9;
	setlocale(LC_ALL, "Russian");
	while (lab != 0)
	{
		cout << ("Введите номер лабораторной (0-выход)\n");
		cin >> lab;
		switch (lab)
		{
		case 5: Lab5(); break;
		case 6: Lab6(); break;
		case 7: Lab7(); break;
		case 8: Lab8(); break;
		default:
			break;
		}
	}
}

//Первое действие : Заменить нулем минимальный элемент строки.
//Второе действие : Вывести на экран сумму положительных элементов в строке.
//Промежуточная функция : Выполнить действия для строк с четным индексом.

//Вычислить значение полинома Лежандра порядка n в точке x :
//P0(x) = 1,
//P1(x) = x,
//Pn(x) = (((2n - 1)Pn - 1(x)-(n - 1)Pn - 2(x)) / n.

//Определить наибольшее число подряд идущих одинаковых символов

//1 Удалить из списка л) все идентификаторы, совпадающие с заданным;
//2 Заменить на заданный идентификатор значение б) предпоследнего элемента списка;
//3 Определить количество идентификаторов в списке, б) следующих после заданного идентификатора;
//4 Записать в массив A а) все идентификаторы из списка;

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
