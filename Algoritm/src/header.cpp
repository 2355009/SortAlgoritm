#include "header.h"

int MergeSort(int** data, int count) {
	int size = _msize(*data) / sizeof(int);
	if (size < 2)
		return count;
	int leftsize = size / 2, rightsize = size - leftsize;
	int* left = new int[leftsize];
	int* right = new int[rightsize];
	for (int i = 0; i < leftsize; i++)
		*(left + i) = *(*data + i);
	for (int i = 0; i < rightsize; i++)
		*(right + i) = *(*data + i + leftsize);
	count = MergeSort(&left, count);
	count = MergeSort(&right, count);
	int leftnow = 0, rightnow = 0, now = 0;
	while (leftnow < leftsize && rightnow < rightsize) {
		if (left[leftnow] < right[rightnow]) {
			*((*data) + now) = *(left + leftnow);
			leftnow++;
			now++;
		}
		else {
			*((*data) + now) = *(right + rightnow);
			rightnow++;
			now++;
			count++;
		}
	}
	while (leftnow < leftsize) {
		*((*data) + now) = *(left + leftnow);
		leftnow++;
		now++;
	}
	while (rightnow < rightsize) {
		*((*data) + now) = *(right + leftnow);
		rightnow++;
		now++;
	}
	delete[] right;
	delete[] left;
	return count;
}
int QuickSort(int** data, int count) {
	int leftsize = 0, rightsize = 0, pivot = *((*data)), size = _msize(*data) / sizeof(int);
	if (size < 2)
		return count;
	for (int i = 1; i < size; i++) {
		if (*((*data) + i) < pivot)
			leftsize++;
		else
			rightsize++;
	}
	int* left = new int[leftsize], * right = new int[rightsize];
	int leftnow = 0, rightnow = 0;
	for (int i = 1; i < size; i++) {
		if (*((*data) + i) < pivot)
		{
			*(left + leftnow) = *((*data) + i);
			leftnow++;
		}
		else
		{
			*(right + rightnow) = *((*data) + i);
			rightnow++;
		}
	}
	count = QuickSort(&left, count);
	count = QuickSort(&right, count);
	for (int i = 0; i < leftsize; i++)
		*(*data + i) = *(left + i);
	*(*data + leftsize) = pivot;
	for (int i = 0; i < rightsize; i++)
		*(*data + 1 + leftsize + i) = *(right + i);
	delete[] right;
	delete[] left;
	count += leftsize;
	return count;
}
void BadSetting(int** data) {
	int size = _msize(*data) / sizeof(int);
	for (int i = 0; i < size; i++)
		*(*data + i) = size - i;
}