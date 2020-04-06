#include<iostream>
#include<algorithm>

#include<string>
#include<map>
#include<vector>

#include "mysort.h"
using namespace std;


int main()
{
	vector<int> test = { 3,5,1,4,2,6 };
	jj05::quick_sort(test, 0, test.size() - 1);
	for (auto t : test)
	{
		cout << t << " ";
	}
}

