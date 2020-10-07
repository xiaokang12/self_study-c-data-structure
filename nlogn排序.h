#pragma once


#include "on2排序算法.h"

//将arr[l...mid]和arr[mid+1...r]两部分进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r){
	int   *aux=new int[r-l+1];

	for (int i = l; i <= r; i++){
		aux[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid){
			arr[k]= aux[j - l];
			j++;
		}
		else if (j > r){
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l]<aux[j-l]){
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}

//递归使用归并排序，对arr[l,...r]的范围进行排序
template <typename T>
void __mergeSort(T arr[], int l, int r){
	if (l >=r)
		return;


	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if (arr[mid]>arr[mid+1])
	   __merge(arr, l, mid, r);
}

template <typename T>
void MergeSort(T *arr, int n){
	__mergeSort(arr, 0, n - 1);
}

//自底向上的归并排序***************************************//
template <typename T>
void MergeSortBU(T *arr, int n){
	for (int sz = 1; sz < n; sz += sz){  //归并排序的个数
		for(int i= 0; i +sz< n; i += sz + sz ){  //归并的起始位置
			//对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]
			__merge(arr, i, i + sz - 1, min(i + 2 * sz - 1, n - 1));
		}
	}
}