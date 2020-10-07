#pragma once

#include "iostream"
#include "string"
#include "SortTestHelper.h"
#include "algorithm"

template <typename T>
void selectSort(T *arr, int n){
	int minIndex = 0;
	for (int i = 0; i < n; i++){
		minIndex = i;
		for (int j = i + 1; j < n; j++){
			if (arr[j] <arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}

//≤Â»Î≈≈–Ú
template <typename T>
void insertSort(T *arr, int n){
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j > 0; j--){
			if (arr[j]<arr[j - 1])
				swap(arr[j - 1], arr[j]);
		}
	}
}


//”≈ªØ≤Â»Î≈≈–Ú
template <typename T>
void insertSortOpt(T *arr, int n){
	for (int i = 1; i < n; i++)
	{
		T temp = arr[i];
		int j;
		for (j = i; j > 0 && arr[j - 1]>temp; j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

template <typename T>
void insertSortOpt(T *arr, int l,int r){
	for (int i = l+1; i <=r; i++)
	{
		T temp = arr[i];
		int j;
		for (j = i; j > 0 && arr[j - 1]>temp; j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}


//œ£∂˚≈≈–Ú
template <typename T>
T * insertSortOpt(int delta, T *arr, int n){
	for (int i = delta; i < n; i++)
	{
		T temp = arr[i];
		int j;
		for (j = i; j > 0 && arr[j - delta]>temp; j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
	return arr;
}
template <typename T>
void shellSort(T *arr, int n){   //
	arr = insertSortOpt(7, arr, n);
	arr = insertSortOpt(3, arr, n);
	arr = insertSortOpt(1, arr, n);
}

//√∞≈›≈≈–Ú
template <typename T>
void BubSort(T *arr, int n){
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j + 1]< arr[j])
				swap(arr[j + 1], arr[j]);
}