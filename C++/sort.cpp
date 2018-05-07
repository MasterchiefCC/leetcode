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

template<typename T>//class的使用需要定义operator(<)
void shell_sort(vector<T> &array) {
	for (int gap = array.size() / 2; gap>0; gap /= 2) {
		for (int i = gap; i<array.size(); ++i) {
			int j, temp=array[i];
			//j>=temp == j-gay>=0
			for (j = i; j >= gap && array[j-gap]>temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
	}
}

template<typename T>
int partition(vector<T>&array, int low, int high) {
	int pivot = array[high];
	int i = low - 1;
	for (int j = low; j<high; ++j) {
		if (array[j] <= pivot) {
			++i;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[high]);
	return i + 1;
}

template<typename T>//class的使用需要定义operator(<=)
void quick_sort(vector<T>&array, int low, int high) {
	if (low<high) {
		int split = partition(array, low, high);
		quick_sort(array, low, split - 1);
		quick_sort(array, split, high);
	}
}

template<typename T>
void merge(vector<T> &array, int mid, int low, int high) {
	int sze_left = mid - low + 1;
	int sze_right = high - mid;

	vector<T>left(sze_left);
	vector<T>right(sze_right);

	for (int i = 0; i<left.size(); ++i)
		left[i] = array[low + i];
	for (int i = 0; i<right.size(); ++i)
		right[i] = array[mid + 1 + i];

	int  L_i = 0, R_i = 0, arr_i = low;

	while (L_i<left.size() && R_i<right.size()) {
		if (left[L_i] <= right[R_i]) {
			array[arr_i] = left[L_i];
			++L_i;
		}
		else {
			array[arr_i] = right[R_i];
			++R_i;
		}
		++arr_i;
	}

	while (L_i<left.size()) {
		array[arr_i++] = left[L_i++];
	}
	while (R_i<right.size()) {
		array[arr_i++] = right[R_i++];
	}
}

template<typename T>//class的使用需要定义operator(<)
void merge_sort(vector<T> &array, int low, int high) {//usage: merge_sort(array, 0, array.size()-1);
	if (low<high) {
		int mid = low + (high - low) / 2;

		merge_sort(array, low, mid);
		merge_sort(array, mid + 1, high);

		merge(array, mid, low, high);
	}
}
