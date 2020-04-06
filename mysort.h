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

//快排
namespace jj05
{
	int partion(vector<int>& nums, int lo, int hi);
	void quick_sort(vector<int> &nums, int lo, int hi)
	{
		if (lo < hi)
		{
        int piovt = partion(nums, lo, hi);
		quick_sort(nums,  lo, piovt - 1);
		quick_sort(nums, piovt + 1, hi);
		}
		
	}

	int partion(vector<int> &nums, int lo, int hi)
	{
		int v = nums[lo];
		int i = lo;
		int j = hi+1;
		while (1)
		{
			while (++i <= hi && nums[i] < v);
			while (--j >= lo && nums[j] > v);
			if (i >= j)
				break;
			swap(nums[i], nums[j]);
		}
		nums[lo] = nums[j];
		nums[j] = v;
		return j;
	}
}

//topk问题
namespace jj06 {
	class Solution {
	public:
		vector<int> getLeastNumbers(vector<int>& arr, int k) {

			if (k == 0 || arr.size() == 0)
			{
				return vector<int>();
			}
			vector<int> res = quick_sort(arr, 0, arr.size() - 1, k - 1);
			vector<int> ans(k);
			copy(res.begin(), res.begin() + k, ans.begin());
			return ans;
		}
	private:
		vector<int> quick_sort(vector<int>& nums, int lo, int hi, int k)
		{
			int j = partition(nums, lo, hi);
			if (j == k)
				return nums;

			return j > k ? quick_sort(nums, lo, j - 1, k) : quick_sort(nums, j + 1, hi, k);
		}

		int partition(vector<int>& nums, int lo, int hi)
		{
			int v = nums[lo];
			int i = lo, j = hi + 1;
			while (1)
			{
				while (++i <= hi && nums[i] < v);
				while (--j >= lo && nums[j] > v);
				if (i >= j) break;

				swap(nums[i], nums[j]);
			}
			nums[lo] = nums[j];
			nums[j] = v;
			return j;
		}
	};

}

