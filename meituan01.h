#pragma once
#ifndef _Meituan01
#define _Meituan01


#include<iostream>
#include<vector>

using namespace std;

vector<int> help3(vector<int>& a, int num)//找最大的三个元素
{
	if (num > a[0])
	{
		a[2] = a[1];
		a[1] = a[0];
		a[0] = num;
	}
	else if (num > a[1])
	{
		a[2] = a[1];
		a[1] = num;
	}
	else if (num > a[2])
	{
		a[2] = num;
	}
	return a;
}

int function()//主函数
{
	int n;
	cin >> n;
	vector<int> a(3, 0);
	vector<int> b(3, 0);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a = help3(a, t);
	}
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		b = help3(b, t);
	}

	int suma = a[0] + a[1] + a[2];
	int sumb = b[0] + b[1] + b[2];
	if (suma > sumb)
		return suma;

	return sumb;

}












#endif // !_Meituan01

