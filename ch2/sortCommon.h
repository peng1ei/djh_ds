#ifndef _SORT_COMMON_H
#define _SORT_COMMON_H
#include <iostream>

namespace mysort {
	int count = 0; // 用来记录排序算法执行的大体步骤数

	template <typename T>
	void swap(T &a, T &b) {
		T tmp = a;
		a = b;
		b = tmp;
	}

}

#endif // _SORT_COMMON_H
