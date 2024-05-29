#include<iostream>
using namespace std;

#define tab "\t"

void Fillrand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива"; cin >> n;
	int* arr = new int[n];

	Fillrand(arr, n);
	Print(arr, n);

	int value;
	cout << "Веедите добавляемое значение"; cin >> value;
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr [n] = value;
	n++;
	Print(arr, n);
	delete[]arr;
}

void Fillrand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;

	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
	cout << *(arr + i) << tab;
	}
	cout << endl;
}
