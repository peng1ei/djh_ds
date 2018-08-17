#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H
#include "sortCommon.h"

namespace mysort {
	
	// 版本1：原始冒泡排序（bubble sorta），未优化
	// 时间复杂度：O(n^2)
	template <typename ElemType>
	void bubbleSort_1(ElemType arr[], int len) {
		int lenSubOne = len - 1;

		for (int i = 0; i < lenSubOne; i++) { // 总共要进行 len - 1 趟
			for (int j = 0; j < lenSubOne - i; j++) {
				if (arr[j] > arr[j+1]) {
					swap(arr[j], arr[j+1]);
				}

				count++;
			}
		}

		std::cout << "turns：" << count << std::endl;
	}

	// 版本2：优化1 -- 经过 k(k < len - 1) 趟后，如果数组里的元素已经有序了，则提前返回
	// 时间复杂度：最好 O(n)，最坏 O(n^2)
	// 稳定性：稳定
	// 该版本比较通用
	template <typename ElemType>	
	void bubbleSort_2(ElemType arr[], int len) {
		int lenSubOne = len - 1;

		for (int i = 0; i < lenSubOne; i++) {
			bool isSorted = true; // 进行每一趟冒泡之前都假定已排序

			for (int j = 0; j < lenSubOne - i; j++) {
				if (arr[j] > arr[j+1]) {
					isSorted = false;
					swap(arr[j], arr[j+1]);
				}
					
				count++;
			}
			
			if (isSorted) {  // 如果已经有序了就直接返回，后续的不用再排了
				std::cout << "turns：" << count << std::endl;
				return;
			}
		}
		
		std::cout << "turns：" << count << std::endl;
	}

	// 版本3：优化2 -- 记录最右端逆序对的位置，缩小趟数，相当于只排序乱序部分
	// 适用情况：乱序元素只出现在前面少部分，比如 A[0, n开根号)区间，后面绝大部分
	// 			元素都是有序的。
	// 时间复杂度：最优 O(n)
	// 稳定性：稳定
	// 优点：对于大部分元素都是有序的情况下，即乱序元素只出现在前面少部分，这样
	// 		的情况该改进的冒泡排序有较大的优势，速度较快，比如乱序元素仅限于A[0, n开根号)区间
	// 缺点：对于大部分元素都是无序的来说，效率极低。
	template <typename ElemType>
	void bubbleSort_3(ElemType arr[], int len) {
		int newLen = 1;
		int newLenSubOne = len - 1; // 需要冒泡的趟数

		//for (int i = 0; i < newLenSubOne; i = 0) {
		int i = 0;
		while (i < newLenSubOne) {
			for (int j = 0; j < newLenSubOne; j++) {
				if (arr[j] > arr[j+1]) {
					swap(arr[j], arr[j+1]);
					newLen = j + 1; // 需要重新排序的元素个数，后面已排序的元素将不再参与比较大小
				}
				
				count++;
			}

			newLenSubOne = newLen - 1; 
		}

		std::cout << "turns：" << count << std::endl;
	}
}

#endif // _BUBBLE_SORT_H
