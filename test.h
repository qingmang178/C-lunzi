#pragma once
#ifndef  _TEST_H
#define  _TEST_H

#include<iostream>

using namespace std;

#include<vector>
int main()
{
	int M;
	cin >> M;
	for (int j = 0; j < M; j++)
	{
    int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}
	cout << N + 1 << endl;
	}
	return 0;
	
}





#endif // ! _TEST_H

