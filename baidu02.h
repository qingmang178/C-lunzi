#pragma once
include <iostream>
#include <vector>
#include<set>

using namespace std;

bool judge(vector<int>& a);
bool help(vector<int> a);

int main()
{
	int T;
	cin >> T;
	vector<int> ans(T + 1);
	for (int i = 1; i <= T; i++)
	{
		int n;
		cin >> n;
		vector<int> stone(n);
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			stone[j] = temp;
		}
		int count = 0;
		while (judge(stone)) count++;
		ans[i] = count;



	}
	for (int i = 1; i <= T; i++)
	{
		if (ans[i] % 2 == 0)
			cout << "woman" << endl;
		else
			cout << "man" << endl;
	}

	return 0;

}

bool judge(vector<int>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > 0)
		{
			a[i]--;
			if (help(a))
				return true;
			else
			{
				a[i]++;
			}
		}
	}
	return false;
}
bool help(vector<int> a)
{
	set<int> s;
	for (auto i : a)
	{
		if (s.count(i))
			return false;
		else
			s.insert(i);
	}
	return true;
}
