#include <iostream>
#include <cstdlib>
#include <ctime>
template  <typename T>
void fill_arr(T arr[], const int length, T begin, T end);
template  <typename T>
void show_arr(T arr[], const int length);
template <typename T>
int searchIndex(T arr[], const int length, T value, int begin = 0);
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin = 0);
template  <typename T>
int MaxElement(T arr[], const int length);
template  <typename T>
int MinElement(T arr[], const int length);
template  <typename T>
double meanValue(T arr[], const int length);
template  <typename T>
void range(T arr[], const int length, T begin, T end);
template <typename T>
int counter(T arr[], const int length, T value);
int main() {
	setlocale(LC_ALL, "Russian");
	int n,m;
	const int size = 100;
	int arr[size];
	fill_arr(arr, size, -100, 100+1);
	show_arr(arr, size);
	std::cout << "Введите число от начала, индекс которого хотите найти:\n";
	std::cin >> n;
	if (searchIndex(arr, size, n) == -1)
		std::cout << "Этого числа нет в массиве!\n";
	else
		std::cout << "Индекс первого вхождения числа в массив = " << searchIndex(arr, size, n) << '\n';
	std::cout << "Введите число с конца, индекс которого хотите найти:\n";
	std::cin >> n;
	if (searchLastIndex(arr, size, n) == -1)
		std::cout << "Этого числа нет в массиве!\n";
	else
		std::cout << "Индекс последнего вхождения числа в массив = " << searchLastIndex(arr, size, n) << '\n';
	std::cout << "Максимальный элемент массива = " << MaxElement(arr, size) << "\n";
	std::cout << "Минимальный элемент массива = " << MinElement(arr, size) << "\n";
	std::cout << "Среднее арифмитическое значение массива = " << meanValue(arr, size) << "\n";
	std::cout << "Введите два числа, в диапазоне которых надо вывести числа на экран:\n";
	std::cin >> n >> m;
	range(arr, size, n, m);
	std::cout << "Введите число количество вхождений которого хотите найти:\n";
	std::cin >> n;
	if (counter(arr, size, n) == 2 || counter(arr, size, n) == 3 || counter(arr, size, n) == 4)
		std::cout << "Выбранное число входит в массив " << counter(arr, size, n) << " раза\n";
	else
		std::cout << "Выбранное число входит в массив " << counter(arr, size, n) << " раз\n";
	return 0;
}
//Заполнение массива случайными числами от begin до end
template  <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end - begin);
}
//Выводит массив на экран
template  <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

//возвращает индекс первого вхождения элемента Value в массив.
template <typename T>
int searchIndex(T arr[], const int length, T value, int begin) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1;
}
//возвращает индекс последнего вхождения элемента в массив.
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin) {
	for(int i= length-1;i>=0;i--)
		if (arr[i] == value)
			return i;
	return -1;
}
//Поиск максимального элемента в массиве
template  <typename T>
int MaxElement(T arr[], const int length) {
	int maxElement = arr[0];
	for (int i = 1; i < length; i++)
		if (maxElement < arr[i])
			maxElement = arr[i];
	return maxElement;
}
//Поиск минимального элемента в массиве
template  <typename T>
int MinElement(T arr[], const int length) {
	int minElement = arr[0];
	for (int i = 1; i < length; i++)
		if (minElement > arr[i])
			minElement = arr[i];
	return minElement;
}
//возвращает среднее арифметическое всех элементов массива
template  <typename T>
double meanValue(T arr[], const int length) {
	double mean = 0;
	for (int i = 0; i < length; i++)
		mean += arr[i];
	return mean / length;
}
//выводит все элементы массива, которые входят в переданный в функцию диапазон
template  <typename T>
void range(T arr[], const int length, T begin, T end) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		if(arr[i]>=begin && arr[i]<=end)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//возвращает количество вхождений переданного элемента в массив.
template <typename T>
int counter(T arr[], const int length, T value) {
	int counter = 0;
	for (int i = 0; i < length; i++)
		if (value == arr[i])
			counter++;
	return counter;
}
