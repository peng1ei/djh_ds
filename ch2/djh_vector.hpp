#ifndef _DJH_VECTOR_H
#define _DJH_VECTOR_H
#include <iostream>

namespace djh {

typedef int Rank; // 秩
#define DEFAULT_CAPACITY 3 // 默认的初始容量

template <typename T>
class Vector {
	protected:
		Rank _size; // 规模
		int _capacity; // 容量
		T *_elem; // 数据区

	protected:
		void copyFrom(const T *A, Rank lo, Rank hi); // 复制数组区间 A[lo, hi)
		void expand(); // 空间不足时扩容，倍增
		void shrink(); // 装填因子过小时压缩
		Rank max(Rank lo, Rank hi);	// 选取最大元素

	public:
		// 构造函数
		Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
			_elem = new T[_capacity = c];
			for (_size = 0; _size < s; _elem[_size++] = v) ;
		}

		Vector(const T *A, Rank length) { // 通过数组整体来初始化Vector
			copyFrom(A, 0, length);
		}

		Vector(const T *A, Rank lo, Rank hi) { // 通过区间 [lo, hi) 来初始化Vector
			copyFrom(A, lo, hi);
		}	
		
		Vector(const Vector<T> &v) { // 向量整体复制初始化
			copyFrom(v._elem, 0, v._size);
		}

		Vector(const Vector<T> &v, Rank lo, Rank hi) {
			copyFrom(v._elem, lo, hi);
		}

		// 析构函数
		~Vector() { delete _elem; }

		// 只读访问接口
		Rank size() const { return _size; }
		bool empty() const { return !_size; }

		int disordered() const; // 判断向量是否已排序
		Rank find(const T &e) const; // 无序向量整体查找
		Rank find(const T &e, Rank lo, Rank hi) const; // 无序向量区间查找
		Rank search(const T &e) const; // 有序向量整体查找
		Rank search(const T &e, Rank lo, Rank hi) const; // 有序向量区间查找

		// 可写访问接口
		T& operator[](Rank r) { return _elem[r]; }
		T& operator[](Rank r) const { return _elem[r]; }

		Vector<T>& operator=(const Vector<T> &v); // 重载赋值操作符
		T remove(Rank r); // 删除秩为 r 的元素
		int remove(Rank lo, Rank hi); // 杀出秩在区间 [lo, hi) 之间的元素
		Rank insert(Rank r, const T &e); // 插入元素
		Rank insert(const T &e); // 默认在末尾插入元素
		void sort(Rank lo, Rank hi); // 对 [lo, hi) 排序
		void sort(); // 整体排序
		void unsort(Rank lo, Rank hi); // 对区间 [lo, hi) 置乱
		void unsort(); // 整体置乱
		int deduplicate(); // 无序去重
		int uniquify(); // 有序去重

		// 遍历
		void traverse(void (*visit)(T &e));	// 遍历，使用函数指针，只读或局部性修改
		template <typename VST>
		void traverse(VST &); // 遍历，使用仿函数，可全局性修改

		template <typename U>
		friend std::ostream& operator<<(std::ostream &os, const Vector<U> &vec);
};

template <typename U>
std::ostream& operator<<(std::ostream &os, const Vector<U> &vec) {
	if (vec._size == 0) {
		os << "{ }" << std::endl;
		return os;
	}

	os << "{ " << vec[0];
	for (int i = 1; i < vec._size; i++)
		std::cout << ", " << vec[i];

	os << " }" << std::endl;	

	return os;	
}

template <typename T>
void Vector<T>::copyFrom(const T *A, Rank lo, Rank hi) {
	if (A == nullptr || lo == hi || lo < 0 || hi < 0)
		return;

	_size = hi - lo;
	_elem = new T[_capacity = _size];

	for (; lo < hi; lo++) {
		_elem[lo] = A[lo];
	}
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &v) { // 重载赋值操作符
	delete [] _elem;
	_elem = nullptr;

	copyFrom(v._elem, 0, v._size);

	return *this;
}

template <typename T>
void Vector<T>::expand() {
	if (_size < _capacity) 
		return;

	T *old = _elem;
	_elem = new T[_capacity <<= 1]; // 左移一位，相当于扩大两倍
	
	for (int i = 0; i < _size; i++)
		_elem[i] = old[i];

	delete old;
	old = nullptr;
}


}
#endif // _DJH_VECTOR_H
