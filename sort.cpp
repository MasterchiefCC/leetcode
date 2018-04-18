#include "mod.h"
template<typename T>//class的使用需要定义operator(<)
void insertionSort(vector<T>&array) {
	for (int i = 0; i<array.size(); ++i) {
		T temp = array[i];
		for (int j = i - 1; j >= 0; --j) {
			if (temp<array[j]) {
				array[j + 1] = array[j];
				array[j] = temp;
			}
			else break;
		}
	}
}
template<typename T>//class的使用需要定义operator(<)
void bubble_sort(vector<T>&array) {
	for (int i = 0; i<array.size(); ++i) {
		bool has_swap = false;
		for (int j = 0; j<array.size() -1 - i; ++j) {
			if (array[j + 1]<array[j]) {
				swap(array[j], array[j + 1]);
				has_swap = true;
			}
		}
		if (!has_swap)break;
	}
}