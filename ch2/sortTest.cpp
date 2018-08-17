#include <iostream>
#include "bubbleSort.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	int arr[] = { 6, 5, 4, 7, 8, 9 };
	mysort::bubbleSort_3(arr, 6);
	
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}
