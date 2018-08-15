#include <iostream>
#include "djh_vector.hpp"
using namespace std;
using namespace djh;

int main(int argc, char *argv[]) {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int *p = arr;
	Vector<int> vec(p, 0, 5);
	cout << vec;

	Vector<int> v1;
	cout << v1;
	v1 = vec;

	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << endl;

	return 0;
}
