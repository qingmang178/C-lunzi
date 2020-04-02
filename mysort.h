#pragma once
#ifndef _MYSORT_H
#define _MYSORT_H

#include<iostream>
using namespace std;

#include<vector>
namespace jj01 {
//快排算法
	/*
	时间复杂度 平均O（nlog(n)）
	最优情况，每次正好中分，减少迭代次数
	2020.3.19
	*/
	
	int parition(vector<int>& A, int low, int high)
	{
		int pivot = A[low];
		while (low < high)
		{
			while (A[high] >= pivot && low < high) high--;
			A[low] = A[high];
			while (A[low] <= pivot && low < high) low++;
			A[high] = A[low];
		}
		A[low] = pivot;
		return low;
	}

	void quicksort(vector<int> &A,int low,int high)
	{
		if (low < high)
		{
			int pivot = parition(A, low, high);
			quicksort(A, low, pivot - 1);
			quicksort(A, pivot + 1, high);
		}
	}

	void test()
	{
		vector<int> a = { 9,5,3,1,3,8 };
		quicksort(a, 0, a.size() - 1);

		for (auto i : a)
			cout << i << " ";//1 1 3 5 8 9
	}


}
//堆排
namespace jj02
{
	void insertion_sort(vector<int>& A, int N)
	{
		for (int p = 0; p < N; p++)
		{
			int temp = A[p];
			int i;
			for (i = p; i > 0 && A[i - 1] > temp; i--)
			{
				A[i] = A[i - 1];
			}
			A[i] = temp;
		}
	}
	void test()
	{
		vector<int> a = { 9,5,3,1,3,8 };
		insertion_sort(a, a.size());

		for (auto i : a)
			cout << i << " ";//1 1 3 5 8 9
	}
	/*ostream& operator<<(const vector<int> a)
	{

	}*/
}

//插入排序
namespace jj03
{


}
//ostream iterator
#include<iterator>
#include<algorithm>
namespace jj04
{
	void test()
	{
		vector<int> myvector;
		for (int i = 1; i < 10; i++) myvector.push_back(i * 10);
		ostream_iterator<int> out_it(cout, ",");
		copy(myvector.begin(), myvector.end(), out_it);
	
	}

}





#endif // !_MYSORT_H

