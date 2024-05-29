#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	//1) создаем буферный массив нужного размера
	int* buffer = new int[n + 1];
	//2)копируем значени€ из исходноого буферного массива
	for (int i = 0; i <n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)удал€ем исходный массив
	delete[] arr;
	//4)подмен€ем адрес старого массива адресом нового массива
	arr = buffer;
	//5) только после всего этого  в конец масива по€вл€етс€ эелемент,
	//в который можно сохранить добавл€емое значение

	arr[n] = value;
	//6 после того как в мвссив добавилс€, количество его элементов
	n++;
	Print(arr, n);
	delete[] arr;//   оператор "new" возращ€ет фадрес выделеной пам€ть
}
void FillRand(int arr[], const int n)
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