#include<iostream>
using namespace std;

#define  tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n; int value)

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ��������� ��������: "; cin >> value;
	arr = push_back(arr[], n; value);

	Print(arr, n);
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

int* push_back(int arr[], int& n; int value)
{
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];

	}

delete[] arr;
int a = 2;
int b = 3;
a = b;
arr = buffer;

arr[n] = value;
n++;
return arr;
}

