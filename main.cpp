#include<iostream>
#include<algorithm>

#include"leetcode0289.h"

#include<vector>
using namespace std;

int main()
{
	Solution solu;
	vector<vector<int>> a = { {0, 1, 0
}, { 0, 0, 1
}, { 1, 1, 1
}, { 0, 0, 0 } };

	solu.gameOfLife(a);
}
