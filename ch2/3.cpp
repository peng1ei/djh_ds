#include <iostream>
#include "bubbleSort.hpp"
using namespace std;

void imSort(int a[], int N) {
	int i = 0, j, k = 0;
	while (i < N - 1) {
		k = N - 1;
		for (j = N-1; j > i; j--) {
			if (a[j] < a[j-1]) {
				k = j;
				mysort::swap(a[j-1], a[j]);
			}

			mysort::count++;
		}
		
		i = k;
	}
	cout << mysort::count << endl;
}

int main(int argc, char *argv[]) {
	int arr[] = { 6, 5, 4, 7, 3, 9, 11, 12, 3, 14, 15, 6, 17, 11, 9, 20, 1, 22, 2, 24, 5 };
	//int arr[] = { 6, 5, 4, 7, 3, 9, 11, 12, 31, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44 };
	//int arr[] = {  31, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44 ,6, 5, 4, 7, 3, 9, 11, 12};
	//int arr[] = { 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
	//	9, 8, 7, 6, 5, 4, 3, 2, 1 };	
	int size = sizeof(arr)/sizeof(int);
	cout << "size = " << size << endl;
	//mysort::bubbleSort_3(arr, size);
	imSort(arr, size);
	
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}
