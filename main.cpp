#include <iostream>
#include <time.h> 
using namespace std;

const int SIZE = 20;

void makeArr(int arr1[], int arr2[]);
void printArr(int arr[]);
void bubbleSort(int* arr);
void bubble(int* arr);
void selectionSort(int* arr);
void selection(int* arr, int r);

int main() {
	int arr1[SIZE];
	int arr2[SIZE];
	int count = 1;

	srand(time(NULL));

	makeArr(arr1, arr2);
	printArr(arr1);

	bubbleSort(arr1);
	selectionSort(arr2);

	return 0;
}

void makeArr(int arr1[], int arr2[]) {
	int num = 0;
	for (int i = 0; i < SIZE; i++) {
		num = rand() % 10 + 1;
		arr1[i] = num;
		arr2[i] = num;
	}
}

void printArr(int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

void bubbleSort(int *arr) {
	bool check = 1;
	int count = 1;

	while (true) {
		check = 1;
		cout << "call bubble sort " << count << " time" << endl;
		bubble(arr);

		for (int i = 1; i < SIZE; i++) {
			check *= (arr[i - 1] <= arr[i]);
		}
		count++;

		printArr(arr);

		if (check == 1)
			break;
	}
}

void bubble(int *arr) {
	int swap = 0;

	for (int i = 1; i < SIZE; i++) {
		if (arr[i - 1] > arr[i]) {
			swap = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = swap;
		}
	}
}

void selectionSort(int* arr) {
	int count = 0;
	bool check = 1;

	while (true) {
		check = 1;
		cout << "call selection sort " << count + 1 << " time" << endl;
		selection(arr, count);

		for (int i = 1; i < SIZE; i++) {
			check *= (arr[i - 1] <= arr[i]);
		}
		count++;

		printArr(arr);

		if (check == 1)
			break;
	}

}

void selection(int* arr, int r) {
	int min = 0, swap = 0;

	min = arr[r];

	for (int i = r; i < SIZE; i++) {
		if (min >= arr[i]) 
			min = arr[i];
	}

	for (int i = r; i < SIZE; i++) {
		if (arr[i] == min) {
			swap = arr[SIZE - (SIZE - r)];
			arr[SIZE - (SIZE - r)] = arr[i];
			arr[i] = swap;
			break;
		}
	}

	cout << "the smallest number is: " << min << endl;
}