#include<iostream>
using namespace std;

#define  tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, const int value,const int index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int position);

int** pop_row_back(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);



//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавлемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавлемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	int index;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);


	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;	
	arr = insert(arr, n, value, index);
	Print(arr, n);

#endif // DINAMIC_MEMORY_1

	int rows;
	int cols;
	cout << "Введите кол-во строк: "; cin >> rows;
	cout << "Введите кол-во элементов строки: "; cin >> cols;
	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	int index;
	cout << "Введите позицию добавляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	if (index < rows)FillRand(arr[index], cols, 100, 1000);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);

}
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;;
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];

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
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++) buffer[i + 1] = arr[i];
	delete[]arr;
	buffer[0] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
	 {
		int* buffer = new int[--n];
		for (int i=0; i < n; i++)buffer[i] = arr[i];
		delete[] arr;
		return buffer;
	}
int* pop_front(int arr[], int& n)
	{
		int* buffer = new int[--n];
		for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
		delete[] arr;
		return buffer;
}
int* insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n + 1];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];---------------- 1 способ
	//for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	for (int i = 0; i < n; i++)
	{
		/*if (i < index)buffer[i] = arr[i];----------------------------- 2 способ
		else buffer[i + 1] = arr[i];*/
		//i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];//----------------------- 3 cgjcj,
	}
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}
int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	return buffer;
}
int** push_row_back(int** arr, int& rows, const int cols)
{

	//1) Создаем буферный массив указателей нужного размера:
	int** buffer = new int* [rows + 1];
	//2) Копируем адреса строк из исходного массива указателей в буферный:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//3) Удаляем исходный массив указателей:
	delete[] arr;
	//4) Создаем новую строку, и помещаем ее в конц массива указателей:
	buffer[rows] = new int[cols] {};
	//5) После добавления строки количество строк увеличивается на 1:
	rows++;
	//6) Возвращаем новый массив указателей на место вызова:
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, int position)
{
	if (position >= rows)return arr;
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < position; i++)buffer[i] = arr[i];
	for (int i = position; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[position] = new int[cols];
	rows++;
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}



