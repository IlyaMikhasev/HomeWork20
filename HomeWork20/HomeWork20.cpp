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
	std::cout << "������� ����� �� ������, ������ �������� ������ �����:\n";
	std::cin >> n;
	if (searchIndex(arr, size, n) == -1)
		std::cout << "����� ����� ��� � �������!\n";
	else
		std::cout << "������ ������� ��������� ����� � ������ = " << searchIndex(arr, size, n) << '\n';
	std::cout << "������� ����� � �����, ������ �������� ������ �����:\n";
	std::cin >> n;
	if (searchLastIndex(arr, size, n) == -1)
		std::cout << "����� ����� ��� � �������!\n";
	else
		std::cout << "������ ���������� ��������� ����� � ������ = " << searchLastIndex(arr, size, n) << '\n';
	std::cout << "������������ ������� ������� = " << MaxElement(arr, size) << "\n";
	std::cout << "����������� ������� ������� = " << MinElement(arr, size) << "\n";
	std::cout << "������� �������������� �������� ������� = " << meanValue(arr, size) << "\n";
	std::cout << "������� ��� �����, � ��������� ������� ���� ������� ����� �� �����:\n";
	std::cin >> n >> m;
	range(arr, size, n, m);
	std::cout << "������� ����� ���������� ��������� �������� ������ �����:\n";
	std::cin >> n;
	if (counter(arr, size, n) == 2 || counter(arr, size, n) == 3 || counter(arr, size, n) == 4)
		std::cout << "��������� ����� ������ � ������ " << counter(arr, size, n) << " ����\n";
	else
		std::cout << "��������� ����� ������ � ������ " << counter(arr, size, n) << " ���\n";
	return 0;
}
//���������� ������� ���������� ������� �� begin �� end
template  <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end - begin);
}
//������� ������ �� �����
template  <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

//���������� ������ ������� ��������� �������� Value � ������.
template <typename T>
int searchIndex(T arr[], const int length, T value, int begin) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1;
}
//���������� ������ ���������� ��������� �������� � ������.
template <typename T>
int searchLastIndex(T arr[], const int length, T value, int begin) {
	for(int i= length-1;i>=0;i--)
		if (arr[i] == value)
			return i;
	return -1;
}
//����� ������������� �������� � �������
template  <typename T>
int MaxElement(T arr[], const int length) {
	int maxElement = arr[0];
	for (int i = 1; i < length; i++)
		if (maxElement < arr[i])
			maxElement = arr[i];
	return maxElement;
}
//����� ������������ �������� � �������
template  <typename T>
int MinElement(T arr[], const int length) {
	int minElement = arr[0];
	for (int i = 1; i < length; i++)
		if (minElement > arr[i])
			minElement = arr[i];
	return minElement;
}
//���������� ������� �������������� ���� ��������� �������
template  <typename T>
double meanValue(T arr[], const int length) {
	double mean = 0;
	for (int i = 0; i < length; i++)
		mean += arr[i];
	return mean / length;
}
//������� ��� �������� �������, ������� ������ � ���������� � ������� ��������
template  <typename T>
void range(T arr[], const int length, T begin, T end) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		if(arr[i]>=begin && arr[i]<=end)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//���������� ���������� ��������� ����������� �������� � ������.
template <typename T>
int counter(T arr[], const int length, T value) {
	int counter = 0;
	for (int i = 0; i < length; i++)
		if (value == arr[i])
			counter++;
	return counter;
}
