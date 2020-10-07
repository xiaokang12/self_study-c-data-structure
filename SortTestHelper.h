#include "iostream"
#include"ctime"
#include <cassert>
using namespace std;

namespace SortTestHelper{
	//生成n个元素的随机数组，每个元素的随机范围

	//显示数组
	template <typename T>
	void printArr(T arr[], int n){
		for (int i = 0; i < n; i++){
			cout << arr[i] << " ";
			if (i % 10 == 0 && i >= 10)
				cout << endl;
		}
		cout << endl;
	}

	int* generateRandArray(int n, int rangL, int rangH){
		assert(rangL <= rangH);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++){
			arr[i] = rand() % (rangH - rangL + 1) + rangL;
		}
		return arr;
	}

	//测试排序算法是否正确
	template <typename T>
	bool IsSort(T arr[], int n){
		for (int i = 0; i < n - 1; i++)
			if (arr[i]>arr[i + 1])
				return false;

		return true;
	}
	//测试排序算法的性能
	template <typename T>
	void testSort(string sortname, void(*sort)(T[], int), T arr[], int n){
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endtime = clock();

		cout << "是否排序成功" << IsSort(arr, n) << endl;
		cout << sortname << ":" << double(endtime - startTime) / CLOCKS_PER_SEC << endl;
		return;
	}

	template <typename T>
	int* copyArr(T arr[],int n){
		int *arr2 = new int[n];
		for (int i = 0; i < n; i++)
			arr2[i] = arr[i];
		return arr2;
	}


}

