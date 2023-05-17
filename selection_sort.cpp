#include <iostream>
#include <iomanip>

using namespace std;


void swap(int* const p1, int* const p2);

void selectionSort(int A[], const int size, int order);


int main()
{
	int arr[10] = { 0, };
	int order;

	cout << "Enter 10 integers in [-99, 99] to sort: ";
	for (size_t i{ 0 }; i < 10; i++)
		cin >> arr[i];

	cout << "Choose sorting order (1: ascending order, 2: descending order): ";
	cin >> order;

	selectionSort(arr, 10, order);

	return 0;
}


void swap(int* const p1, int* const p2)
{
	const int tmp{ *p1 };

	*p1 = *p2;
	*p2 = tmp;
}

void selectionSort(int A[], const int size, int order)
{
	size_t idx;

	cout << "Initial array:";
	for (size_t i{0}; i < size; i++)
	{
		cout << setw(4) << A[i];
	}
	cout << endl;

	if (order == 1)
	{
		int min{ 99 };

		for (size_t i{ 0 }; i < size - 1; i++)
		{
			for (size_t j{ i }; j < size; j++)
			{
				if (min > A[j]) {
					min = A[j];
					idx = j;
				}
			}

			min = 99;
			swap(&A[idx], &A[i]);

			cout << "after " << i << "-th iteration:";
			for (size_t i{ 0 }; i < size; i++)
			{
				cout << setw(4) << A[i];
			}
			cout << endl;
		}

		cout << "Sorted in ascending order:";
		for (size_t i{ 0 }; i < size; i++)
		{
			cout << setw(4) << A[i];
		}
	}
	else
	{
		int max{ -99 };

		for (size_t i{ 0 }; i < size - 1; i++)
		{
			for (size_t j{ i }; j < size; j++)
			{
				if (max < A[j]) {
					max = A[j];
					idx = j;
				}
			}

			max = -99;
			swap(&A[idx], &A[i]);

			cout << "after " << i << "-th iteration:";
			for (size_t i{ 0 }; i < size; i++)
			{
				cout << setw(4) << A[i];
			}
			cout << endl;
		}

		cout << "Sorted in descending order:";
		for (size_t i{ 0 }; i < size; i++)
		{
			cout << setw(4) << A[i];
		}
	}
}
